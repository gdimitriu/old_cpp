// MFifo.cpp: implementation of the CMFifo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFifo.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMFifo::CMFifo()
{
	int i;
	for(i=0;i<DATA_TYPES;i++)
	{
		head[i]=NULL;
		tail[i]=NULL;
		data[i]=NULL;
	}
	parc=NULL;
}

CMFifo::~CMFifo()
{
	int i;
	int type;
	CNode *tmp;
	for(i=0;i<DATA_TYPES;i++)
	{
		while(head[i]!=NULL)
		{
			head[i]->Get(&parc,&tmp,&type);
			delete head[i];
			head[i]=parc;
		}
		if(data[i]!=NULL) free(data[i]);
	}
}

void CMFifo::Push(long val)
{
	parc=new CNode(val,NULL,NULL);
	if(head[0]==NULL)
	{
		head[0]=tail[0]=parc;
	}
	else
	{
		tail[0]->SetUp(parc);
		tail[0]=parc;
	}
}

void CMFifo::Push(double val)
{
	parc=new CNode(val,NULL,NULL);
	if(head[1]==NULL)
	{
		head[1]=tail[1]=parc;
	}
	else
	{
		tail[1]->SetUp(parc);
		tail[1]=parc;
	}
}

void CMFifo::Push(char val)
{
	parc=new CNode(val,NULL,NULL);
	if(head[3]==NULL)
	{
		head[3]=tail[3]=parc;
	}
	else
	{
		tail[3]->SetUp(parc);
		tail[3]=parc;
	}
}

void CMFifo::Push(char *val)
{
	parc=new CNode(val,NULL,NULL);
	if(head[2]==NULL)
	{
		head[2]=tail[2]=parc;
	}
	else
	{
		tail[2]->SetUp(parc);
		tail[2]=parc;
	}
}

void * CMFifo::Pop(int type)
{
	int ttemp;
	int dim;
	CNode *temp;
	void *dattmp;
	if(type<0) return NULL;
	if(data[type]!=NULL) free(data[type]);
	data[type]=NULL;
	if(head[type]==NULL) return NULL;
	dattmp=head[type]->Get(&parc,&temp,&ttemp);
	if(ttemp==-1) return NULL;
	switch(type)
	{
	case 0:
		data[type]=(long *)calloc(1,sizeof(long));
		*((long *)data[type])=*((long *)dattmp);
		break;
	case 1:
		data[type]=(double *)calloc(1,sizeof(double));
		*((double *)data[type])=*((double *)dattmp);
		break;
	case 2:
		dim=strlen((char *)dattmp);
		data[type]=(char *)calloc(dim+1,sizeof(char));
		strcpy((char *)data[type],(char *)dattmp);
		break;
	case 3:
		data[type]=(char *)calloc(1,sizeof(char));
		*((char *)data[type])=*((char *)dattmp);
		break;
	default:
		return NULL;
	}
	temp=head[type];
	head[type]=parc;
	delete temp;
	return data[type];
}
