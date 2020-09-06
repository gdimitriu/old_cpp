// statical_example_win32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Dog.h"
#include "Horse.h"
#include "Pig.h"
#include "LockStack.h"
using namespace std;
int CDog::m_NrOfInstances=0;
int CHorse::m_NrOfInstances=0;
int CPig::m_NrOfInstances=0;
CLockStack *CLockStack::m_pFirstGotIt=NULL;
CLockStack *CLockStack::m_pLockVar=NULL;
int CLockStack::m_Count=0;
CmyStack *CLockStack::m_pStack=NULL;
int TotalNumberOfInstances(void)
{
	return CDog::NumberOfInstances()+CHorse::NumberOfInstances()+CPig::NumberOfInstances();
}
void TestPHD(void)
{
	CDog *Dog1;
	Dog1=new CDog("bula",10);
	CDog *Dog2;
	Dog2=new CDog("strula",5);
	cout <<TotalNumberOfInstances()<<"\n";
	Dog1->PrintIndetifier();
	Dog2->PrintIndetifier();
	CHorse *Horse1;
	Horse1=new CHorse("gigi",1);
	Horse1->PrintIndetifier();
	cout <<TotalNumberOfInstances()<<"\n";
	delete Dog1;
	cout <<TotalNumberOfInstances()<<"\n";
	CPig *Pig1;
	Pig1=new CPig("porcusor",1);
	Pig1->PrintIndetifier();
	cout <<TotalNumberOfInstances()<<"\n";

	delete Pig1;
	delete Dog2;
	delete Horse1;
}
void testLockStack(void)
{
	CLockStack Stack1;
	CLockStack Stack2;
	long value;
	value=2L;
	cout<<"lock stack1 status="<<Stack1.SetExclusiveLock()<<"\n";
	cout<<"lock stack2 status="<<Stack2.SetExclusiveLock()<<"\n";
	cout<<"push 2 into stack2 status="<<Stack2.Push(value)<<"\n";
	cout<<"release stack2 status="<<Stack2.ReleaseExclusiveLock()<<"\n";
	cout<<"release stack1 status="<<Stack1.ReleaseExclusiveLock()<<"\n";
	cout<<"lock stack2 status="<<Stack2.SetExclusiveLock()<<"\n";
	cout<<"push 2 into stack2 status="<<Stack2.Push(value)<<"\n";
	value=3;
	cout<<"push 3 into stack2 status="<<Stack2.Push(value)<<"\n";
	cout<<"pop stack2 status="<<Stack2.Pop(value);
	cout<<" and had pop="<<value<<"\n";
	cout<<"release stack2 status="<<Stack2.ReleaseExclusiveLock()<<"\n";
	cout<<"lock stack1 status="<<Stack1.SetExclusiveLock()<<"\n";
	cout<<"pop stack1 status="<<Stack1.Pop(value);
	cout<<" and had pop="<<value<<"\n";
}
int _tmain(int argc, _TCHAR* argv[])
{
	TestPHD();
	testLockStack();
	return 0;
}

