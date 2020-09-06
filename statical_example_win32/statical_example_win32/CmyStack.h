#pragma once

class CmyStack
{
private:
	int m_NrOfElements;
	long m_Data[100];
public:
	CmyStack(void)
	{
		m_NrOfElements=0;
	}
	~CmyStack(void)
	{
	}
	void Push(long item)
	{
		m_Data[m_NrOfElements]=item;
		++m_NrOfElements;
	}
	long Pop(void)
	{
		--m_NrOfElements;
		return m_Data[m_NrOfElements];
	}
};

