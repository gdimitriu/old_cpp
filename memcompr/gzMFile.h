// gzMFile.h: interface for the CgzMFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GZMFILE_H__5FE5DE6B_7219_11DA_B910_B185C4B3AD18__INCLUDED_)
#define AFX_GZMFILE_H__5FE5DE6B_7219_11DA_B910_B185C4B3AD18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "zlib.h"
class CgzMFile  
{
public:
	int seek(bool pos,unsigned long step);
	void reset();
	long read(void *output,uLong dim);
	long write(void *input,uLong dim);
	void close();
	void open(bool type,bool rtype);
	bool IsInsert();
	void Insert();
	bool IsBinary();
	CgzMFile();
	virtual ~CgzMFile();
protected:
	void readpart(Byte *ioutput,unsigned long dim);
	void readfirst(Byte *ioutput,unsigned long dim);
	void readms(Byte *ioutput,unsigned long dim);
	bool m_fread;
	bool m_isinsert;
	unsigned long m_uncomprLen;
	unsigned long m_pread;
	unsigned long ndim;
	unsigned long m_owrite;
	struct memory
	{
		struct memory *next;
		struct memory *prev;
		unsigned long size;
		unsigned long o_size;
		Byte *compr;
	} *m_memory,*m_mlast,*m_memorylast,*m_mtemp;
	unsigned long m_comprLen;
	int err;
	bool m_isbinary; //true for binary and false for normal
	bool m_isread;	//true for read and false for write
	char *m_name;
	z_stream c_stream,d_stream;
	Byte *m_decompr;
};

#endif // !defined(AFX_GZMFILE_H__5FE5DE6B_7219_11DA_B910_B185C4B3AD18__INCLUDED_)
