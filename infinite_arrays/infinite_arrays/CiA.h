#pragma once
#include <memory.h>

/***********************************
* this class will store the infinite array structure
* the infinite array has no boudoury except the memory
* of the system.
************************************/
const unsigned int BUCKET_SIZE=100;
class CiA
{
protected:
	int m_array[BUCKET_SIZE];
	class CiA *m_next;
public:
	CiA(void)
	{
		m_next=NULL;
		memset(m_array,'\0',sizeof(m_array));
	}
	~CiA(void)
	{
		if(NULL!=m_next)
		{
			delete m_next;
			m_next=NULL;
		}
	}//default destructor
	int & operator [] (const unsigned int index);
};

