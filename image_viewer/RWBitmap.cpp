// RWBitmap.cpp: implementation of the CRWBitmap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RWBitmap.h"
#include <iostream>
#include <fstream>
#include<stdlib.h>

using namespace std;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRWBitmap::CRWBitmap()
{
	m_bfSize=0;
	m_bfReserved1=0;
	m_bfReserved2=0;
	m_bfOffBits=0;
	m_biSize=0;
	m_biWidth=0;
	m_biHeight=0;
	m_biPlanes=0;
	m_biBitCount=0;
	m_biCompression=0;
	m_biSizeImage=0;
	m_biXPelsPerMeter=0;
	m_biYPelsPerMeter=0;
	m_biClrUsed=0;
	m_biClrImportant=0;
	m_rgbBlue=NULL;
	m_rgbGreen=NULL;
	m_rgbRed=NULL;
	data=NULL;
}

CRWBitmap::~CRWBitmap()
{
	if(m_rgbBlue!=NULL) free(m_rgbBlue);
	if(m_rgbGreen!=NULL) free(m_rgbGreen);
	if(m_rgbRed!=NULL) free(m_rgbRed);
	if(data!=NULL)
	{
		free(*data);
		free(data);
	}
}

void CRWBitmap::ReadFH()
{
	//read the File Header
	m_IFile.read(m_bfType,4);
	if(!(m_bfType[0]=='B' && m_bfType[1]=='M')) return ;
	m_IFile.read((char *)&m_bfSize,4);
	m_IFile.read((char *)&m_bfReserved1,2);
	m_IFile.read((char *)&m_bfOffBits,4);
	//read the Info Header
	m_IFile.read((char *)&m_biSize,4);
	if(m_biSize>=40)
	{
		m_IFile.read((char *)&m_biWidth,4);
		m_IFile.read((char *)&m_biHeight,4);
		m_IFile.read((char *)&m_biPlanes,2);
		m_IFile.read((char *)&m_biBitCount,2);
		m_IFile.read((char *)&m_biCompression,4);
		m_IFile.read((char *)&m_biSizeImage,4);
		m_IFile.read((char *)&m_biXPelsPerMeter,4);
		m_IFile.read((char *)&m_biYPelsPerMeter,4);
		m_IFile.read((char *)&m_biClrUsed,4);
		m_IFile.read((char *)&m_biClrImportant,4);
	}
	else
	{
		m_IFile.read((char *)&m_biWidth,2);
		m_IFile.read((char *)&m_biHeight,2);
		m_IFile.read((char *)&m_biPlanes,2);
		m_IFile.read((char *)&m_biBitCount,2);
	}
	long i;
	if(m_IFile.tellg().seekpos() != m_bfOffBits)
	switch(m_biBitCount)
	{
		case 1:
			m_rgbBlue=(char *)calloc(2,sizeof(char));
			m_rgbGreen=(char *)calloc(2,sizeof(char));
			m_rgbRed=(char *)calloc(2,sizeof(char));
			for(i=0;i<2;i++)
			{
				m_IFile.read(&m_rgbBlue[i],1);
				m_IFile.read(&m_rgbGreen[i],1);
				m_IFile.read(&m_rgbRed[i],1);
				m_IFile.read(&m_rgbReserved,1);
			}
			break;
		case 4:
			m_rgbBlue=(char *)calloc(16,sizeof(char));
			m_rgbGreen=(char *)calloc(16,sizeof(char));
			m_rgbRed=(char *)calloc(16,sizeof(char));
			for(i=0;i<16;i++)
			{
				m_IFile.read(&m_rgbBlue[i],1);
				m_IFile.read(&m_rgbGreen[i],1);
				m_IFile.read(&m_rgbRed[i],1);
				m_IFile.read(&m_rgbReserved,1);
			}
			break;
		case 8:
			m_rgbBlue=(char *)calloc(256,sizeof(char));
			m_rgbGreen=(char *)calloc(256,sizeof(char));
			m_rgbRed=(char *)calloc(256,sizeof(char));
			for(i=0;i<256;i++)
			{
				m_IFile.read(&m_rgbBlue[i],1);
				m_IFile.read(&m_rgbGreen[i],1);
				m_IFile.read(&m_rgbRed[i],1);
				m_IFile.read(&m_rgbReserved,1);
			}
			break;
		case 16:
			if(m_biCompression==3)
			{
				m_IFile.read((char *)&m_rgbRed16,4);
				m_IFile.read((char *)&m_rgbGreen16,4);
				m_IFile.read((char *)&m_rgbBlue16,4);
			}
			break;
		case 24:
			if(m_biCompression==3)
			{
				m_IFile.read((char *)&m_rgbRed16,4);
				m_IFile.read((char *)&m_rgbGreen16,4);
				m_IFile.read((char *)&m_rgbBlue16,4);
			}
			break;
		case 32:
			if(m_biCompression==3)
			{
				m_IFile.read((char *)&m_rgbRed16,4);
				m_IFile.read((char *)&m_rgbGreen16,4);
				m_IFile.read((char *)&m_rgbBlue16,4);
			}
			break;
		default:
			{
			}
	}
}

void CRWBitmap::SetIFileName(char* str)
{
	m_IFile.open(str,ios::binary);
}

void CRWBitmap::PrintFH()
{
	//tests;
	if(m_biSize>=40)
	{
		cout<<"Using Info Header\n";
		cout<<"Width="<<m_biWidth<<" and Height="<<m_biHeight<<endl;
		cout<<"BitPlanes="<<m_biPlanes<<endl;
		cout<<"BitCount="<<m_biBitCount<<endl;
		cout<<"Compression="<<m_biCompression<<endl;
		cout<<"Image Size="<<m_biSizeImage<<endl;
		cout<<"Resolution in pixel per meter for X="<<m_biXPelsPerMeter<<endl;
		cout<<"Resolution in pixel per meter for Y="<<m_biYPelsPerMeter<<endl;
		cout<<"Used colors="<<m_biClrUsed<<endl;
		cout<<"Significant colors="<<m_biClrImportant<<endl;
	}
	else
	{
		cout<<"Using Color Header\n";
		cout<<"Width="<<m_biWidth<<" and Height="<<m_biHeight<<endl;
		cout<<"BitPlanes="<<m_biPlanes<<endl;
		cout<<"BitCount="<<m_biBitCount<<endl;
	}
	long i;
	if(m_rgbBlue!=NULL)
	switch(m_biBitCount)
	{
		case 1:
			cout<<"\nBlue ";
			for(i=0;i<2;i++)
				cout<<m_rgbBlue[i]<<" ";
			cout<<"\nGreen ";
			for(i=0;i<2;i++)
				cout<<m_rgbGreen[i]<<" ";
			cout<<"\nRed ";
			for(i=0;i<2;i++)
				cout<<m_rgbRed[i]<<" ";
			cout<<endl;
			break;
		case 4:
			cout<<"Blue ";
			for(i=0;i<16;i++)
				cout<<m_rgbBlue[i]<<" ";
			cout<<"\nGreen ";
			for(i=0;i<16;i++)
				cout<<m_rgbGreen[i]<<" ";
			cout<<"\nRed ";
			for(i=0;i<16;i++)
				cout<<m_rgbRed[i]<<" ";
			cout<<endl;
			break;
		case 8:
			cout<<"Blue ";
			for(i=0;i<256;i++)
				cout<<m_rgbBlue[i]<<" ";
			cout<<"\nGreen ";
			for(i=0;i<256;i++)
				cout<<m_rgbGreen[i]<<" ";
			cout<<"\nRed ";
			for(i=0;i<256;i++)
				cout<<m_rgbRed[i]<<" ";
			cout<<endl;
			break;
		case 16:
			if(m_biCompression==3)
			{
				cout<<m_rgbRed16<<" "<<m_rgbGreen16<<" "<<m_rgbBlue16<<endl;
			}
			break;
		case 24:
			if(m_biCompression==3)
			{
				cout<<m_rgbRed16<<" "<<m_rgbGreen16<<" "<<m_rgbBlue16<<endl;
			}
			break;
		case 32:
			if(m_biCompression==3)
			{
				cout<<m_rgbRed16<<" "<<m_rgbGreen16<<" "<<m_rgbBlue16<<endl;
			}
			break;
		default:
			{
			}
	}
}

void CRWBitmap::ReadData()
{
	unsigned long *ltemp;
	unsigned long j;
	long i;
	long number;
	data=(unsigned long **)calloc(m_biHeight,sizeof(unsigned long *));
	ltemp=(unsigned long *)calloc(m_biWidth*m_biHeight,sizeof(unsigned long));
	for(j=0;j<m_biHeight;j++)
	{
		data[j]=ltemp;
		ltemp+=m_biWidth;
	}
	long k;
	m_IFile.seekg(m_bfOffBits,ios::beg);
	if(m_biBitCount==16)
	{
		unsigned short stemp;
		unsigned short stemp1;
		if(m_biCompression==0)
		{
			for(i=m_biHeight-1;i>=0;i--)
				for(j=0;j<m_biWidth;j++)
				{
					m_IFile.read((char *)&stemp,2);
					data[i][j]=0x0;
					stemp1=stemp<<11;
					stemp1=stemp1>>11;
					data[i][j]|=stemp1<<8;
					stemp1=stemp>>5;
					stemp1=stemp1<<11;
					stemp1=stemp1>>11;
					data[i][j]|=stemp1<<16;
					stemp1=stemp>>10;
					stemp1=stemp1<<11;
					stemp1=stemp1>>11;
					data[i][j]|=stemp1;
				}
		}
	}
	else if(m_biBitCount==24)
	{
		unsigned  char ctemp[3];
		unsigned long ltemp1;
		if(m_biCompression==0)
		{
			for(i=m_biHeight-1;i>=0;i--)
				for(j=0;j<m_biWidth;j++)
				{
					m_IFile.read((char *)ctemp,3);
					data[i][j]=0x0;
					ltemp1=ctemp[0];
					data[i][j]|=ltemp1<<16;
					ltemp1=ctemp[1];
					data[i][j]|=ltemp1<<8;
					ltemp1=ctemp[2];
					data[i][j]|=ltemp1;
				}
		}
	}
	else if(m_biBitCount==32)
	{
		unsigned  char ctemp[4];
		unsigned long ltemp1;
		if(m_biCompression==0)
		{
			for(i=m_biHeight-1;i>=0;i--)
				for(j=0;j<m_biWidth;j++)
				{
					m_IFile.read((char *)ctemp,4);
					data[i][j]=0x0;
					ltemp1=ctemp[0];
					data[i][j]|=ltemp1<<16;
					ltemp1=ctemp[1];
					data[i][j]|=ltemp1<<8;
					ltemp1=ctemp[2];
					data[i][j]|=ltemp1;
				}
		}
	}
	else
	{	
		char *ctemp;
		char ctemp1;
		if(m_biBitCount==1) number=m_biWidth/8;
		if(m_biBitCount==4) number=m_biWidth/2;
		if(m_biBitCount==8) number=m_biWidth;
		ctemp=(char *)calloc(number,sizeof(char));
		for(i=m_biHeight-1;i>=0;i--)
		{
			m_IFile.read((char *)ctemp,number);
			k=0;
			j=0;
			while(k<number)
			{
				if(m_biBitCount==1)
				{
					for(int m=0;m<8;m++)
					{
						data[i][j]=0x00;
						ctemp1=ctemp[k];
						ctemp1=ctemp1>>m;
						ctemp1=ctemp1<<7;
						ctemp1=ctemp1>>7;
						data[i][j]|=m_rgbRed[ctemp1];
						data[i][j]|=m_rgbBlue[ctemp1]<<16;
						data[i][j]|=m_rgbGreen[ctemp1]<<8;
						j++;
					}
					k++;
				}
				else if(m_biBitCount==4)
				{
					data[i][j]=0x00;
					ctemp1=ctemp[k];
					ctemp1=ctemp1<<4;
					ctemp1=ctemp1>>4;
					data[i][j]|=m_rgbRed[ctemp1];
					data[i][j]|=m_rgbBlue[ctemp1]<<16;
					data[i][j]|=m_rgbGreen[ctemp1]<<8;
					j++;
					data[i][j]=0x00;
					ctemp1=ctemp[k];
					ctemp1=ctemp1>>4;
					data[i][j]|=m_rgbRed[ctemp1];
					data[i][j]|=m_rgbBlue[ctemp1]<<16;
					data[i][j]|=m_rgbGreen[ctemp1]<<8;
					j++;
					k++;
				}
				else if(m_biBitCount==8)
				{
					data[i][j]=0x00;
					data[i][j]|=m_rgbRed[ctemp[k]];
					data[i][j]|=m_rgbBlue[ctemp[k]]<<16;
					data[i][j]|=m_rgbGreen[ctemp[k]]<<8;
					j++;
					k++;
				}
				else break;
			}
		}
		free(ctemp);
	}
	m_IFile.close();
}

unsigned long CRWBitmap::width()
{
	return m_biWidth;
}

unsigned long CRWBitmap::height()
{
	return m_biHeight;
}


void CRWBitmap::SetHeight(unsigned long val)
{
	m_biHeight=val;
}

void CRWBitmap::SetWidth(unsigned long val)
{
	m_biWidth=val;
}

void CRWBitmap::CreateImg()
{
	unsigned long *ltemp;
	unsigned long i,j;
	data=(unsigned long **)calloc(m_biHeight,sizeof(unsigned long *));
	ltemp=(unsigned long *)calloc(m_biWidth*m_biHeight,sizeof(unsigned long));
	for(i=0;i<m_biHeight;i++)
	{
		data[i]=ltemp;
		ltemp+=m_biWidth;
	}
	for(i=0;i<m_biHeight;i++)
		for(j=0;j<m_biWidth;j++) data[i][j]=0;
}

void CRWBitmap::SetType(unsigned short type,unsigned short compression)
{
	m_biBitCount=type;
	m_biCompression=compression;
}

void CRWBitmap::WriteFH()
{
	//only for 16b
	m_biSize=12;
	m_biPlanes=1;
	m_biSizeImage=0; //no compression
	m_bfType[0]='B';
	m_bfType[1]='M';
	m_bfSize=sizeof(char)*(4+4+2+4+4+8+2*m_biHeight*m_biWidth);
	m_bfOffBits=sizeof(char)*(4+8);
	//write the File Header
	m_OFile.write(m_bfType,4);
	m_OFile.write((char *)&m_bfSize,4);
	m_OFile.write((char *)&m_bfReserved1,2);
	m_OFile.write((char *)&m_bfOffBits,4);
	//write the Info Header
	m_OFile.write((char *)&m_biSize,4);
	if(m_biSize>=40)
	{
		m_OFile.write((char *)&m_biWidth,4);
		m_OFile.write((char *)&m_biHeight,4);
		m_OFile.write((char *)&m_biPlanes,2);
		m_OFile.write((char *)&m_biBitCount,2);
		m_OFile.write((char *)&m_biCompression,4);
		m_OFile.write((char *)&m_biSizeImage,4);
		m_OFile.write((char *)&m_biXPelsPerMeter,4);
		m_OFile.write((char *)&m_biYPelsPerMeter,4);
		m_OFile.write((char *)&m_biClrUsed,4);
		m_OFile.write((char *)&m_biClrImportant,4);
	}
	else
	{
		m_OFile.write((char *)&m_biWidth,2);
		m_OFile.write((char *)&m_biHeight,2);
		m_OFile.write((char *)&m_biPlanes,2);
		m_OFile.write((char *)&m_biBitCount,2);
	}
	long i;
	//write the palette
	switch(m_biBitCount)
	{
		case 1:
			for(i=0;i<2;i++)
			{
				m_OFile.write(&m_rgbBlue[i],1);
				m_OFile.write(&m_rgbGreen[i],1);
				m_OFile.write(&m_rgbRed[i],1);
				m_OFile.write(&m_rgbReserved,1);
			}
			break;
		case 4:
			for(i=0;i<16;i++)
			{
				m_OFile.write(&m_rgbBlue[i],1);
				m_OFile.write(&m_rgbGreen[i],1);
				m_OFile.write(&m_rgbRed[i],1);
				m_OFile.write(&m_rgbReserved,1);
			}
			break;
		case 8:
			for(i=0;i<256;i++)
			{
				m_OFile.write(&m_rgbBlue[i],1);
				m_OFile.write(&m_rgbGreen[i],1);
				m_OFile.write(&m_rgbRed[i],1);
				m_OFile.write(&m_rgbReserved,1);
			}
			break;
		case 16:
			if(m_biCompression==3)
			{
				m_OFile.write((char *)&m_rgbRed16,4);
				m_OFile.write((char *)&m_rgbGreen16,4);
				m_OFile.write((char *)&m_rgbBlue16,4);
			}
			break;
		case 24:
			if(m_biCompression==3)
			{
				m_OFile.write((char *)&m_rgbRed16,4);
				m_OFile.write((char *)&m_rgbGreen16,4);
				m_OFile.write((char *)&m_rgbBlue16,4);
			}
			break;
		case 32:
			if(m_biCompression==3)
			{
				m_OFile.write((char *)&m_rgbRed16,4);
				m_OFile.write((char *)&m_rgbGreen16,4);
				m_OFile.write((char *)&m_rgbBlue16,4);
			}
			break;
		default:
			{
			}
	}
}

void CRWBitmap::WriteData()
{
	unsigned long j;
	long i;
	if(m_biBitCount==16)
	{
		unsigned short stemp;
		unsigned short stemp1;
		if(m_biCompression==0)
		{
			for(i=m_biHeight-1;i>=0;i--)
				for(j=0;j<m_biWidth;j++)
				{
					stemp=0x0;
					//blue
					stemp1=data[i][j]>>16;
					stemp1=stemp1<<5;
					stemp|=stemp1;
					//green
					stemp1=data[i][j]>>8;
					stemp1=stemp1<<24;
					stemp1=stemp1>>24;
					stemp|=stemp1;
					//red
					stemp1=data[i][j]<<24;
					stemp1=stemp1>>24;
					stemp1=stemp1<<10;
					stemp|=stemp1;
					m_OFile.write((char *)&stemp,2);
				}
		}
	}
	m_OFile.close();
}

unsigned short CRWBitmap::GetPalette(void **Blue, void **Green, void **Red, unsigned long *comp)
{
	comp=&m_biCompression;
	if(m_biBitCount==16 || m_biBitCount==24 || m_biBitCount==32)
	{
		*Blue=(void *)&m_rgbBlue16;
		*Green=(void *)&m_rgbGreen16;
		*Red=(void *)&m_rgbRed16;
	}
	else
	{
		*Blue=(void *)m_rgbBlue;
		*Green=(void *)m_rgbGreen;
		*Red=(void *)m_rgbRed;
	}
	return m_biBitCount;
}


void CRWBitmap::SetPalette(void *Blue, void *Green, void *Red, unsigned short type, unsigned long *comp)
{
	m_biBitCount=type;
	m_biCompression=*comp;
	if(m_biBitCount==16 || m_biBitCount==24 || m_biBitCount==32)
	{
		m_rgbBlue16=*((long *)Blue);
		m_rgbGreen16=*((long *)Green);
		m_rgbRed16=*((long *)Red);
	}
	else if(m_biBitCount==8)
	{
		m_rgbBlue=(char *)calloc(256,sizeof(char));
		m_rgbGreen=(char *)calloc(256,sizeof(char));
		m_rgbRed=(char *)calloc(256,sizeof(char));
		memcpy(m_rgbBlue,Blue,256*sizeof(char));
		memcpy(m_rgbGreen,Green,256*sizeof(char));
		memcpy(m_rgbRed,Red,256*sizeof(char));
	}
	else if(m_biBitCount==4)
	{
		m_rgbBlue=(char *)calloc(16,sizeof(char));
		m_rgbGreen=(char *)calloc(16,sizeof(char));
		m_rgbRed=(char *)calloc(16,sizeof(char));
		memcpy(m_rgbBlue,Blue,16*sizeof(char));
		memcpy(m_rgbGreen,Green,16*sizeof(char));
		memcpy(m_rgbRed,Red,16*sizeof(char));
	}
	else if(m_biBitCount==1)
	{
		m_rgbBlue=(char *)calloc(2,sizeof(char));
		m_rgbGreen=(char *)calloc(2,sizeof(char));
		m_rgbRed=(char *)calloc(2,sizeof(char));
		memcpy(m_rgbBlue,Blue,2*sizeof(char));
		memcpy(m_rgbGreen,Green,2*sizeof(char));
		memcpy(m_rgbRed,Red,2*sizeof(char));
	}
}

void CRWBitmap::SetOFileName(char *str)
{
	m_OFile.open(str,ios::binary);
}
