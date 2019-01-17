#include "StdAfx.h"
#include "CiA.h"
#include <iostream>

int & CiA::operator [] (const unsigned int index)
{
	using namespace std;
	class CiA *pCurrent;
	unsigned int current_index;
	pCurrent=this;//this is the pointer to the memory location
	current_index=index;// this is the index to work
	
	while(current_index>=BUCKET_SIZE)
	{
		if(NULL==pCurrent->m_next)
		{
			pCurrent->m_next=new CiA();
			if(NULL==pCurrent->m_next)
			{
				cerr<<"Out of memory\n";
				exit(0);
			}
		}
		pCurrent=pCurrent->m_next;
		current_index-=BUCKET_SIZE;
	}
	return(pCurrent->m_array[current_index]);
}