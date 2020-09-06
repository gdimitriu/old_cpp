#include "StdAfx.h"
#include <iostream>
#include "LockStack.h"

using namespace std;

CLockStack::CLockStack(void)
{
	if(NULL==m_pStack)
	{
		m_pStack=new CmyStack;
	}
	++m_Count;
}


CLockStack::~CLockStack(void)
{
	--m_Count;
	if(0==m_Count)
	{
		delete m_pStack;
	}
}

int CLockStack::Push(long item)
{
	if(this==m_pLockVar || NULL==m_pLockVar)
	{
		m_pStack->Push(item);
		return(0);
	}
	else
	{
		return(1);
	}
}

int CLockStack::Pop(long &item)
{
	if (this==m_pLockVar || NULL==m_pLockVar)
	{
		item=m_pStack->Pop();
		return(0);
	}
	else
	{
		return(1);
	}
}

int CLockStack::SetExclusiveLock(void)
{
	if(NULL==m_pLockVar)
	{
		m_pLockVar=this;
		if(NULL==m_pFirstGotIt)
		{
			m_pFirstGotIt=this;
			cout <<"this is the first instance which got the lock\n";
		}
		else
		{
			cout<<"Instance got the lock\n";
		}
		return(0);
	}
	else
	{
		return(1);
	}
}

int CLockStack::ReleaseExclusiveLock(void)
{
	
	if(m_pLockVar==this)
	{
		m_pLockVar=NULL;
		cout<<"Instance release the lock\n";
		return(0);
	}
	else
	{
		cout<<"We try to release a lock which is not ours\n";
		return(1);
	}
}

void CLockStack::ResetLocks(void)
{
	m_pLockVar=NULL;
	m_pFirstGotIt=NULL;
}