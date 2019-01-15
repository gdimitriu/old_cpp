// gzMFile.cpp: implementation of the CgzMFile class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "gzMFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CgzMFile::CgzMFile()
{
	//settings for memory
	m_memory=NULL;
	m_mlast=NULL;
	m_memorylast=NULL;
	//other settings
	m_name=NULL;
	m_isbinary=true;
	m_isread=false;
	m_isinsert=false;
	m_fread=false;
	m_decompr=NULL;
}

CgzMFile::~CgzMFile()
{
	if(m_name!=NULL) free(m_name);
	if(m_memory!=NULL)
	{
		while(m_memory!=NULL)
		{
			m_mlast=m_memory;
			m_memory=m_memory->next;
			free(m_mlast->compr);
			free(m_mlast);
		}
	}
}

void CgzMFile::open(bool type,bool rtype)
{
	m_isbinary=type;
	if(rtype==false)//open for write
	{
		m_isread=rtype;
		c_stream.zalloc=(alloc_func)0;
		c_stream.zfree=(free_func)0;
		c_stream.opaque=(voidpf)0;
		err=deflateInit(&c_stream,Z_DEFAULT_COMPRESSION);
		if(m_memory==NULL) m_comprLen=0;
		else
		{
			while(m_memory!=NULL)
			{
				m_mlast=m_memory;
				m_memory=m_memory->next;
				free(m_mlast->compr);
				free(m_mlast);
			}
			m_memory=NULL;
			m_mlast=NULL;
			m_memorylast=NULL;
			m_decompr=NULL;
			m_comprLen=0;
		}
	}
	else  //open for read
	{
		if(m_memory!=NULL)
		{		
			d_stream.zalloc=(alloc_func)0;
			d_stream.zfree=(free_func)0;
			d_stream.opaque=(voidpf)0;
			d_stream.avail_in=0;
			err=inflateInit(&d_stream);
			m_uncomprLen=0;
			m_mlast=m_memory;
			m_isread=true;
		}
		else m_isread=false;
		m_fread=false;
		m_pread=0;
	}
}

void CgzMFile::close()
{
	if(m_isread==false) //open for write
	{
		m_comprLen=c_stream.total_out;
		err=deflateEnd(&c_stream);
		cout<<"final="<<m_comprLen<<endl;cout.flush();
		if(m_decompr!=NULL) free(m_decompr);
	}
	else //open for read
		err=inflateEnd(&d_stream);
}

void CgzMFile::reset()
{
	if(m_isread==true)
	{
		m_mlast=m_memory;
		m_fread=false;
		if(m_decompr!=NULL) free(m_decompr);
		m_uncomprLen=0;
		m_pread=0;
		m_owrite=0;
		d_stream.total_in=0;
		d_stream.total_out=0;
		err=inflateEnd(&d_stream);
		d_stream.zalloc=(alloc_func)0;
		d_stream.zfree=(free_func)0;
		d_stream.opaque=(voidpf)0;
		d_stream.avail_in=0;
		err=inflateInit(&d_stream);
	}
}

void CgzMFile::Insert()
{
	m_isinsert=true;
}

bool CgzMFile::IsInsert()
{
	return m_isinsert;
}

bool CgzMFile::IsBinary()
{
	return m_isbinary;
}

long CgzMFile::write(void *input, uLong dim)
{
	if(m_isbinary==true && m_isread==false)
	{
		Byte *temp;
		temp=(Byte *)calloc(128*1024,1);
		unsigned long total=c_stream.total_out;
		unsigned long len=c_stream.total_in+dim;
		c_stream.next_in=(Byte *)input;
		c_stream.next_out=temp;
		unsigned long count=0;
		c_stream.avail_out=128*1024;
		c_stream.avail_in=dim;
		err=deflate(&c_stream,Z_FULL_FLUSH);
		if(err!=Z_OK && err!=Z_STREAM_END)
		{
			cout<<"deflate error="<<err<<endl;
			cout.flush();
		}
		m_mtemp=(struct memory *)calloc(1,sizeof(struct memory));
		if(m_memory==NULL)
		{
			m_mtemp->prev=NULL;
			m_memory=m_mlast=m_memorylast=m_mtemp;
		}
		else
		{
			m_mtemp->prev=m_memorylast;
			m_memorylast->next=m_mtemp;
			m_memorylast=m_mlast=m_mtemp;
		}
		m_mtemp->next=NULL;
		m_mtemp->size=c_stream.total_out-total;
		m_mtemp->o_size=dim;
		m_mtemp->compr=(Byte *)calloc(m_mtemp->size,1);
		memcpy(m_mtemp->compr,temp,m_mtemp->size);
		free(temp);
		return m_comprLen;
	}
	else return -1;
}

long CgzMFile::read(void *output, uLong dim)
{
	Byte *ioutput=(Byte *)output;
	if(m_isbinary==true && m_isread==true)
	{
		if(m_mlast!=NULL)
		{
			if(m_fread==false)
				readfirst(ioutput,dim);
			else
			{
				if((m_mlast->o_size-m_pread)<dim) //link to another segment
				{
					m_owrite=m_mlast->o_size-m_pread;
					memcpy(output,&m_decompr[m_pread],m_mlast->o_size-m_pread);
					m_pread=0;
					m_mlast=m_mlast->next;
					free(m_decompr);
					m_decompr=NULL;
					ndim=dim-m_owrite;
					readms(ioutput,dim);
				}
				else //read a part of the segment
					readpart(ioutput,dim);
			}
		}
		else return -2;
		return m_uncomprLen;
	}
	else return -1;
}

void CgzMFile::readfirst(Byte *ioutput, unsigned long dim)
{
	m_decompr=(Byte *)calloc(m_mlast->o_size,1);
	d_stream.next_in=m_mlast->compr;
	d_stream.next_out=m_decompr;
	d_stream.avail_in=m_mlast->size;
	d_stream.avail_out=m_mlast->o_size;
	err=inflate(&d_stream,Z_SYNC_FLUSH);
	if(err!=Z_OK && err!=Z_STREAM_END)
	{
		cout<<"inflate error="<<err<<endl;
		cout.flush();
	}
	m_uncomprLen=d_stream.total_out;
	if(dim<m_mlast->o_size)
	{
		memcpy(ioutput,m_decompr,dim);
		m_pread=dim;
		m_owrite=dim;
		m_fread=true;
	}
	else if(dim==m_mlast->o_size)
	{
		memcpy(ioutput,m_decompr,m_mlast->o_size);
		free(m_decompr);
		m_decompr=NULL;
		m_owrite=0;
		m_pread=0;
		m_mlast=m_mlast->next;
		m_fread=false;
	}
	else
	{
		memcpy(ioutput,m_decompr,m_mlast->o_size);
		free(m_decompr);
		m_decompr=NULL;
		m_owrite=m_mlast->o_size;
		m_pread=0;
		m_mlast=m_mlast->next;
		ndim=dim-m_owrite;
		readms(ioutput,dim);
		m_fread=false;
	}
}

void CgzMFile::readpart(Byte *ioutput, unsigned long dim)
{
	memcpy(ioutput,&m_decompr[m_pread],dim);
	m_pread=m_pread+dim;
	if(m_pread<m_mlast->o_size)
		m_fread=true;
	else
	{
		m_pread=0;
		m_mlast=m_mlast->next;
		free(m_decompr);
		m_decompr=NULL;
		m_fread=false;
	}
}

void CgzMFile::readms(Byte *ioutput, unsigned long dim)
{
	while(ndim>=m_mlast->o_size)
	{
		m_decompr=(Byte *)calloc(m_mlast->o_size,1);
		d_stream.next_in=m_mlast->compr;
		d_stream.next_out=m_decompr;
		d_stream.avail_in=m_mlast->size;
		d_stream.avail_out=m_mlast->o_size;
		err=inflate(&d_stream,Z_SYNC_FLUSH);
		if(err!=Z_OK && err!=Z_STREAM_END)
		{
			cout<<"inflate error="<<err<<endl;
			cout.flush();
		}
		m_uncomprLen=d_stream.total_out;
		memcpy(&ioutput[m_owrite],m_decompr,m_mlast->o_size);
		m_fread=false;
		free(m_decompr);
		m_decompr=NULL;
		m_owrite=m_owrite+m_mlast->o_size;
		m_mlast=m_mlast->next;
		m_pread=0;
		ndim=dim-m_owrite;
	}
	if(ndim<=m_mlast->o_size)
	{
		m_decompr=(Byte *)calloc(m_mlast->o_size,1);
		d_stream.next_in=m_mlast->compr;
		d_stream.next_out=m_decompr;
		d_stream.avail_in=m_mlast->size;
		d_stream.avail_out=m_mlast->o_size;
		err=inflate(&d_stream,Z_SYNC_FLUSH);
		if(err!=Z_OK && err!=Z_STREAM_END)
		{
			cout<<"inflate error="<<err<<endl;
			cout.flush();
		}
		m_uncomprLen=d_stream.total_out;
		memcpy(&ioutput[m_owrite],m_decompr,ndim);
		if(ndim<m_mlast->o_size)
		{
			m_pread=ndim;
			m_fread=true;
		}
		else
		{
			m_mlast=m_mlast->next;
			m_pread=0;
			m_fread=false;
			free(m_decompr);
			m_decompr=NULL;
		}
	}
}

int CgzMFile::seek(bool pos, unsigned long step)
{
	if(pos==true) reset();
	unsigned long runpos;
	if(m_pread!=0 && step>(m_mlast->o_size-m_pread))
	{
		runpos=m_mlast->o_size-m_pread;
		m_mlast=m_mlast->next;
	}
	else runpos=0;
	while(1)
	{
		m_decompr=(Byte *)calloc(m_mlast->o_size,1);
		d_stream.next_in=m_mlast->compr;
		d_stream.next_out=m_decompr;
		d_stream.avail_in=m_mlast->size;
		d_stream.avail_out=m_mlast->o_size;
		err=inflate(&d_stream,Z_SYNC_FLUSH);
		if(err!=Z_OK && err!=Z_STREAM_END)
		{
			cout<<"inflate error="<<err<<endl;
			cout.flush();
		}
		m_uncomprLen=d_stream.total_out;
		runpos+=m_mlast->o_size;
		if(step<runpos && m_mlast->next!=NULL)
		{
			m_fread=true;
			runpos-=m_mlast->o_size;
			m_pread=step-runpos;
			return 0;
		}
		else if(step<runpos && m_mlast->next==NULL)
		{
			m_fread=true;
			m_pread=runpos-m_mlast->o_size;
			if(m_pread==0) m_pread=step;
			return 0;
		}
		else if(step>runpos)
		{
			free(m_decompr);
			m_decompr=NULL;
			m_mlast=m_mlast->next;			
		}
		else if(step==runpos)
		{
			m_pread=0;
			free(m_decompr);
			m_decompr=NULL;
			m_mlast=m_mlast->next;			
			m_fread=false;
			return 0;
		}
		else
		{
			free(m_decompr);
			m_decompr=NULL;
			return -1;
		}
	}
	return -1;
}
