#pragma once
#include "CmyStack.h"
class CLockStack
{
private:
	static CLockStack *m_pLockVar;
	static CLockStack *m_pFirstGotIt;
	static CmyStack *m_pStack;
	static int m_Count;
public:
	CLockStack(void);
	~CLockStack(void);
	int Push(long item);
	int Pop(long &item);
	int SetExclusiveLock(void);
	int ReleaseExclusiveLock(void);
	static void ResetLocks(void);
};

