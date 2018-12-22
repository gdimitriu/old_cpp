// Fifo.cpp: implementation of the CFifo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Fifo.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFifo::CFifo()
{
	head=NULL;
	tail=NULL;
	parc=NULL;
	data=NULL;
}

CFifo::~CFifo()
{
	int type;
	CNode *parc1;
	while(head!=NULL)
	{
		head=parc;
		parc->Get(&head,&parc1,&type);
		delete parc;
	}
	if(data!=NULL) free(data);
}

void CFifo::Push(long val)
{
	if(head==NULL)
	{
		head=new CNode(val,NULL,NULL);
		tail=head;
	}
	else
	{
		parc=new CNode(val,NULL,NULL);
		tail->SetUp(parc);
		tail=parc;
	}
}

void CFifo::Push(double val)
{
	if(head==NULL)
	{
		head=new CNode(val,NULL,NULL);
		tail=head;
	}
	else
	{
		parc=new CNode(val,NULL,NULL);
		tail->SetUp(parc);
		tail=parc;
	}
}

void CFifo::Push(char val)
{
	if(head==NULL)
	{
		head=new CNode(val,NULL,NULL);
		tail=head;
	}
	else
	{
		parc=new CNode(val,NULL,NULL);
		tail->SetUp(parc);
		tail=parc;
	}
}

void CFifo::Push(char *val)
{
	if(head==NULL)
	{
		head=new CNode(val,NULL,NULL);
		tail=head;
	}
	else
	{
		parc=new CNode(val,NULL,NULL);
		tail->SetUp(parc);
		tail=parc;
	}
}

void * CFifo::Pop(int *type)
{
	if(data!=NULL) free(data);
	data=NULL;
	CNode *tmp,*tmp1;
	void *datatmp;
	if(head==NULL)
	{
		*type=-1;
		return NULL;
	}
	tmp1=head;
	datatmp=tmp1->Get(&head,&tmp,type);
	if(datatmp==NULL)
	{
		*type=-1;
		head=tail=NULL;
		return NULL;
	}
	else
	{
		if(*type==0) //is long
		{
			data=(long *)calloc(1,sizeof(long));
			*((long *)data)=*((long *)datatmp);
		}
		else if(*type==1) //is double
		{
			data=(double *)calloc(1,sizeof(double));
			*((double *)data)=*((double *)datatmp);
		}
		else if(*type==2) //is string
		{
			int dim=strlen((char *)datatmp);
			data=(char *)calloc(dim+1,sizeof(char));
			strcpy((char *)data,(char *)datatmp);
		}
		else if(*type==3) //is char
		{
			data=(char *)calloc(1,sizeof(char));
			*((char *)data)=*((char *)datatmp);
		}
		delete tmp1;
		return data;
	}
}
