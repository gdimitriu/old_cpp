// Stack.cpp: implementation of the CStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Stack.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStack::CStack()
{
	stack=NULL;
	data=NULL;
	parc=NULL;
}

CStack::~CStack()
{
	if(stack!=NULL)
	{
		CNode *up,*next;
		int type;
		stack->Get(&up,&next,&type);
		delete stack;
		stack=next;
	}
	if(data!=NULL)
		free(data);
}

void CStack::Push(long val)
{
	stack=new CNode(val,NULL,stack);
}

void CStack::Push(double val)
{
	stack=new CNode(val,NULL,stack);
}

void CStack::Push(char *val)
{
	stack=new CNode(val,NULL,stack);
}

void CStack::Push(char val)
{
	stack=new CNode(val,NULL,stack);
}

void * CStack::Pop(int *type)
{
	if(data!=NULL) free(data);
	data=NULL;
	CNode *tmp;
	if(stack!=NULL)
	{
		void *datatmp=stack->Get(&tmp,&parc,type);
		if(*type==0)
		{	
			data=(long *)calloc(1,sizeof(long));
			*((long *)data)=*((long *)datatmp);
		}
		else if(*type==1)
		{
			data=(double *)calloc(1,sizeof(double));
			*((double *)data)=*((double *)datatmp);
		}
		else if(*type==2)
		{
			int dim=-1;
			dim=strlen((char *)datatmp);
			if(dim>0)
			{
				data=(char *)calloc(dim+1,sizeof(char));
				strcpy((char *)data,(char *)datatmp);
			}
		}
		else if(*type==3)
		{
			data=(char *)calloc(1,sizeof(char));
			*((char *)data)=*((char *)datatmp);
		}
		delete stack;
		stack=parc;
		return data;
	}
	else
	{
		*type=-1;
		return NULL;
	}
}
