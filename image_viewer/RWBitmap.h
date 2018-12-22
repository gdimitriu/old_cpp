// RWBitmap.h: interface for the CRWBitmap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RWBITMAP_H__F7C5521E_4CEE_4D32_A5E2_083C06DAB898__INCLUDED_)
#define AFX_RWBITMAP_H__F7C5521E_4CEE_4D32_A5E2_083C06DAB898__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <fstream>
#include <string.h>
using namespace std;

class CRWBitmap  
{
public:
	void SetOFileName(char * str);
	void SetPalette(void *Blue,void *Green,void *Red,unsigned short type, unsigned long *comp);
	unsigned short GetPalette(void **Blue,void **Green,void **Red, unsigned long *comp);
	void WriteData();
	void WriteFH();
	void SetType(unsigned short type,unsigned short compression);
	void CreateImg();
	void SetWidth(unsigned long val);
	void SetHeight(unsigned long val);
	unsigned long height();
	unsigned long width();
	void ReadData();
	void PrintFH();
	void SetIFileName(char *str);
	void ReadFH();
	CRWBitmap();
	virtual ~CRWBitmap();
	unsigned long **data;
protected:
	ifstream m_IFile;
	ofstream m_OFile;
	//Bitmap File Header
	char m_bfType[2];
	unsigned long m_bfSize;
	short m_bfReserved1;
	short m_bfReserved2;
	long m_bfOffBits;
	//Bitmap Info Header
	unsigned long m_biSize;
	unsigned long m_biWidth;
	unsigned long m_biHeight;
	unsigned short m_biPlanes;
	unsigned short m_biBitCount;
	unsigned long m_biCompression; //BI_RGB=0, BI_RLE=1, BI_RLE4=2, BI_BITFIELDS=3
	unsigned long m_biSizeImage;
	unsigned long m_biXPelsPerMeter;
	unsigned long m_biYPelsPerMeter;
	unsigned long m_biClrUsed;
	unsigned long m_biClrImportant;
	//Bitmap Color Header
//	short m_biWidth;
//	short m_biHeight;
//	short m_biPlanes;
//	short m_biBitCount;
	//RGBQUAD
	char *m_rgbBlue;
	char *m_rgbGreen;
	char *m_rgbRed;
	char m_rgbReserved;
	long m_rgbBlue16;
	long m_rgbGreen16;
	long m_rgbRed16;
};

#endif // !defined(AFX_RWBITMAP_H__F7C5521E_4CEE_4D32_A5E2_083C06DAB898__INCLUDED_)
