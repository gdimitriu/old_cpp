#pragma once
#include "CRuntimeClass_emulation.h"
#include <fstream>

/*
 CArchive emulation for MFC
*/
class CArchive
{
public:
	CArchive()
	{
	}
	CArchive(std::ifstream *in)
	{
		_pin=in;
		_storing=false;
		m_lpBuffer=(BYTE *)calloc(64,sizeof(BYTE));
	}

	CArchive(std::ofstream *out)
	{
		_pout=out;
		_storing=true;
		m_lpBuffer=(BYTE *)calloc(64,sizeof(BYTE));
	}

	~CArchive()
	{
		if(m_lpBuffer!=nullptr)
			free(m_lpBuffer);
	}
	bool IsStoring()
	{
		return _storing;
	}

	void WriteCount(unsigned int value)
	{
		char *buff=new char[sizeof(value)];
		_itoa(value,buff,10);
		_pout->write(buff,sizeof(value));
		delete[] buff;
	}

	unsigned int ReadCount(void)
	{
		unsigned int temp;
		char *buff=new char[sizeof(temp)];
		_pin->read(buff,sizeof(temp));
		temp=atoi(buff);
		delete[] buff;
		return temp;
	}

	/*-------------------------------------------------------------------
	** loading procedures
	**-----------------------------------------------------------------*/
	CArchive &operator<<(CObject *& value)
	{
		return *this;
	}

	CArchive &operator>>(CObject *& value)
	{
		return *this;
	}
	
	CArchive& CArchive::operator>>(int& i)
	{
		return CArchive::operator>>((LONG&)i);
	}
	
	CArchive& CArchive::operator>>(unsigned& u)
	{
		return CArchive::operator>>((LONG&)u);
	}
	
	CArchive& CArchive::operator>>(short& w)
	{
		return CArchive::operator>>((WORD&)w);
	}
	
	CArchive& CArchive::operator>>(char& ch)
	{
		return CArchive::operator>>((BYTE&)ch);
	}
	
	CArchive& CArchive::operator>>(bool& b)
	{
		BYTE by; CArchive& ar = CArchive::operator>>(by);
		b = (by ? true : false);
		return ar;
	}
	
	CArchive& CArchive::operator>>(BYTE& by)
	{ 
		if (m_lpBufCur + sizeof(BYTE) > m_lpBufMax)
			FillBuffer(UINT(sizeof(BYTE) - (m_lpBufMax - m_lpBufCur)));
		by = *(UNALIGNED BYTE*)m_lpBufCur;
		m_lpBufCur += sizeof(BYTE);
		return *this; 
	}

	CArchive& CArchive::operator>>(LONGLONG& dwdw)
	{ 
		if (m_lpBufCur + sizeof(LONGLONG) > m_lpBufMax)
			FillBuffer(sizeof(LONGLONG) - (UINT)(m_lpBufMax - m_lpBufCur));
		dwdw = *(UNALIGNED LONGLONG*)m_lpBufCur;
		m_lpBufCur += sizeof(LONGLONG);
		return *this; 
	}

	CArchive& CArchive::operator>>(ULONGLONG& dwdw)
	{ 
		if (m_lpBufCur + sizeof(ULONGLONG) > m_lpBufMax)
			FillBuffer(sizeof(ULONGLONG) - (UINT)(m_lpBufMax - m_lpBufCur));
		dwdw = *(UNALIGNED ULONGLONG*)m_lpBufCur;
		m_lpBufCur += sizeof(ULONGLONG);
		return *this; 
	}

	CArchive& CArchive::operator>>(WORD& w)
	{ 
		if (m_lpBufCur + sizeof(WORD) > m_lpBufMax)
			FillBuffer(UINT(sizeof(WORD) - (m_lpBufMax - m_lpBufCur)));
		w = *(UNALIGNED WORD*)m_lpBufCur;
		m_lpBufCur += sizeof(WORD);
		return *this; 
	}

	CArchive& CArchive::operator>>(DWORD& dw)
	{ 
		if (m_lpBufCur + sizeof(DWORD) > m_lpBufMax)
			FillBuffer(UINT(sizeof(DWORD) - (m_lpBufMax - m_lpBufCur)));
		dw = *(UNALIGNED DWORD*)m_lpBufCur;
		m_lpBufCur += sizeof(DWORD);
		return *this; 
	}
	
	CArchive& CArchive::operator>>(float& f)
	{ 
		if (m_lpBufCur + sizeof(float) > m_lpBufMax)
			FillBuffer(UINT(sizeof(float) - (m_lpBufMax - m_lpBufCur)));
		f = *(UNALIGNED float*)m_lpBufCur;
		m_lpBufCur += sizeof(float);
		return *this; 
	}
	
	CArchive& CArchive::operator>>(double& d)
	{ 
		if (m_lpBufCur + sizeof(double) > m_lpBufMax)
			FillBuffer(UINT(sizeof(double) - (m_lpBufMax - m_lpBufCur)));
		d = *(UNALIGNED double*)m_lpBufCur;
		m_lpBufCur += sizeof(double);
		return *this; 
	}

	CArchive& CArchive::operator>>(LONG& l)
	{ 
		if (m_lpBufCur + sizeof(LONG) > m_lpBufMax)
			FillBuffer(UINT(sizeof(LONG) - (m_lpBufMax - m_lpBufCur)));
		l = *(UNALIGNED LONG*)m_lpBufCur;
		m_lpBufCur += sizeof(LONG);
		return *this; 
	}

	/*-------------------------------------------------------------------
	** storing procedures
	**-----------------------------------------------------------------*/
	CArchive& CArchive::operator<<(int i)
	{
		return CArchive::operator<<((LONG)i);
	}

	CArchive& CArchive::operator<<(unsigned u)
	{
		return CArchive::operator<<((LONG)u);
	}
	
	CArchive& CArchive::operator<<(short w)
	{
		return CArchive::operator<<((WORD)w);
	}
	CArchive& CArchive::operator<<(char ch)
	{
		return CArchive::operator<<((BYTE)ch);
	}

	CArchive& CArchive::operator<<(bool b)
	{
		return CArchive::operator <<((BYTE)(b ? 1 : 0));
	}

	CArchive& CArchive::operator<<(BYTE by)
	{ 
		if (m_lpBufCur + sizeof(BYTE) > m_lpBufMax)
			Flush();
		*(UNALIGNED BYTE*)m_lpBufCur = by;
		m_lpBufCur += sizeof(BYTE);
		return *this; 
	}

	CArchive& CArchive::operator<<(LONGLONG dwdw)
	{ 
		if (m_lpBufCur + sizeof(LONGLONG) > m_lpBufMax)
			Flush();
		*(UNALIGNED LONGLONG*)m_lpBufCur = dwdw;
		m_lpBufCur += sizeof(LONGLONG);
		return *this; 
	}
	
	CArchive& CArchive::operator<<(ULONGLONG dwdw)
	{ 
		if (m_lpBufCur + sizeof(ULONGLONG) > m_lpBufMax)
			Flush();
		*(UNALIGNED ULONGLONG*)m_lpBufCur = dwdw;
		m_lpBufCur += sizeof(ULONGLONG);
		return *this; 
	}
	
	CArchive& CArchive::operator<<(WORD w)
	{ 
		if (m_lpBufCur + sizeof(WORD) > m_lpBufMax)
			Flush();
		*(UNALIGNED WORD*)m_lpBufCur = w;
		m_lpBufCur += sizeof(WORD);
		return *this; 
	}

	CArchive& CArchive::operator<<(LONG l)
	{ 
		if (m_lpBufCur + sizeof(LONG) > m_lpBufMax)
			Flush();
		*(UNALIGNED LONG*)m_lpBufCur = l;
		m_lpBufCur += sizeof(LONG);
		return *this; 
	}

	CArchive& CArchive::operator<<(DWORD dw)
	{ 
		if (m_lpBufCur + sizeof(DWORD) > m_lpBufMax)
			Flush();
		*(UNALIGNED DWORD*)m_lpBufCur = dw;
		m_lpBufCur += sizeof(DWORD);
		return *this; 
	}

	CArchive& CArchive::operator<<(float f)
	{ 
		if (m_lpBufCur + sizeof(float) > m_lpBufMax)
			Flush();
		*(UNALIGNED float*)m_lpBufCur = f;
		m_lpBufCur += sizeof(float);
		return *this;
	}
	
	CArchive& CArchive::operator<<(double d)
	{
		if (m_lpBufCur + sizeof(double) > m_lpBufMax)
			Flush();
		*(UNALIGNED double*)m_lpBufCur = d;
		m_lpBufCur += sizeof(double);
		return *this; 
	}
protected:
	//to be implemented
	void Flush(void)
	{

	}
	void FillBuffer(UINT nAdditionalBytesNeeded)
	{
		realloc(m_lpBuffer,sizeof(m_lpBuffer)+nAdditionalBytesNeeded);
	}
	std::ifstream *_pin;
	std::ofstream *_pout;
	bool _storing;
	BYTE* m_lpBufCur;
	BYTE* m_lpBufMax;
	BYTE* m_lpBufStart;
	BYTE* m_lpBuffer;
};