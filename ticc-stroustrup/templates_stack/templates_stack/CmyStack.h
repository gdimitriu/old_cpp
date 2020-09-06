#pragma once

template <class cValue> class CmyStack
{
private:
	int m_NrOfElements;
	cValue m_Data[100];
public:
	CmyStack(void)
	{
		m_NrOfElements=0;
	}
	~CmyStack(void)
	{
	}
	void Push(cValue item)
	{
		m_Data[m_NrOfElements]=item;
		++m_NrOfElements;
	}
	cValue Pop(void)
	{
		--m_NrOfElements;
		return m_Data[m_NrOfElements];
	}
};

