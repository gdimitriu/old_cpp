// DList.cpp: implementation of the CDList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DList.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDList::CDList()
{
	for(int i=0;i<DATA_TYPES;i++)
	{
		head[i]=tail[i]=NULL;
		data[i]=NULL;
		view[i]=NULL;
	}
	parc=next=prev=NULL;
}

CDList::~CDList()
{
	int tp;
	for(int i=0;i<DATA_TYPES;i++)
	{
		while(head[i]!=NULL)
		{
			head[i]->Get(&next,&prev,&tp);
			delete head[i];
			head[i]=next;
			if(head[i]!=NULL)
				head[i]->SetDown(NULL);
		}
		if(data[i]!=NULL) free(data[i]);
	}
}

void CDList::Add(long val)
{
	long *plong;
	int type;
	if(head[0]==NULL)
	{
		head[0]=tail[0]=view[0]=new CNode(val,NULL,NULL);
		return;
	}
	if(val<=*((long *)head[0]->View()))
	{
		parc=new CNode(val,head[0],NULL);
		head[0]->SetDown(parc);
		head[0]=view[0]=parc;
		return;
	}
	if(val>=*((long *)tail[0]->View()))
	{
		parc=new CNode(val,NULL,tail[0]);
		tail[0]->SetUp(parc);
		tail[0]=parc;
		return;
	}
	parc=head[0];
	plong=(long *)parc->Get(&next,&prev,&type);
	while(*plong<=val && parc!=NULL)
	{
		parc=next;
		plong=(long *)parc->Get(&next,&prev,&type);
	}
	CNode *temp;
	if(parc!=NULL)
	{
		temp=new CNode(val,parc,prev);
		parc->SetDown(temp);
		prev->SetUp(temp);
	}
}

void CDList::Add(double val)
{
	double *pdouble;
	int type;
	if(head[1]==NULL)
	{
		head[1]=tail[1]=view[1]=new CNode(val,NULL,NULL);
		return;
	}
	if(val<=*((double *)head[1]->View()))
	{
		parc=new CNode(val,head[1],NULL);
		head[1]->SetDown(parc);
		head[1]=view[1]=parc;
		return;
	}
	if(val>=*((double *)tail[1]->View()))
	{
		parc=new CNode(val,NULL,tail[1]);
		tail[1]->SetUp(parc);
		tail[1]=parc;
		return;
	}
	parc=head[1];
	pdouble=(double *)parc->Get(&next,&prev,&type);
	while(*pdouble<=val && parc!=NULL)
	{
		parc=next;
		pdouble=(double *)parc->Get(&next,&prev,&type);
	}
	CNode *temp;
	if(parc!=NULL)
	{
		temp=new CNode(val,parc,prev);
		parc->SetDown(temp);
		prev->SetUp(temp);
	}
}

void CDList::Add(char val)
{
	char *pchar;
	int type;
	if(head[3]==NULL)
	{
		head[3]=tail[3]=view[3]=new CNode(val,NULL,NULL);
		return;
	}
	if(val<=*((char *)head[3]->View()))
	{
		parc=new CNode(val,head[3],NULL);
		head[3]->SetDown(parc);
		head[3]=view[3]=parc;
		return;
	}
	if(val>=*((char *)tail[3]->View()))
	{
		parc=new CNode(val,NULL,tail[3]);
		tail[3]->SetUp(parc);
		tail[3]=parc;
		return;
	}
	parc=head[3];
	pchar=(char *)parc->Get(&next,&prev,&type);
	while(*pchar<=val && parc!=NULL)
	{
		parc=next;
		pchar=(char *)parc->Get(&next,&prev,&type);
	}
	CNode *temp;
	if(parc!=NULL)
	{
		temp=new CNode(val,parc,prev);
		parc->SetDown(temp);
		prev->SetUp(temp);
	}
}

void CDList::Add(char *val)
{
	char *pchar;
	int type;
	if(head[2]==NULL)
	{
		head[2]=tail[2]=view[2]=new CNode(val,NULL,NULL);
		return;
	}
	if(strcmp(val,(char *)head[2]->View())<=0)
	{
		parc=new CNode(val,head[2],NULL);
		head[2]->SetDown(parc);
		head[2]=view[2]=parc;
		return;
	}
	if(strcmp(val,(char *)tail[2]->View())>=0)
	{
		parc=new CNode(val,NULL,tail[2]);
		tail[2]->SetUp(parc);
		tail[2]=parc;
		return;
	}
	parc=head[2];
	pchar=(char *)parc->Get(&next,&prev,&type);
	while(strcmp(pchar,val)<=0 && parc!=NULL)
	{
		parc=next;
		pchar=(char *)parc->Get(&next,&prev,&type);
	}
	CNode *temp;
	if(parc!=NULL)
	{
		temp=new CNode(val,parc,prev);
		parc->SetDown(temp);
		prev->SetUp(temp);
	}
}

void * CDList::Get(int type)
{
	void *data;
	int tp;
	if(view[type]!=NULL)
	{
		data=view[type]->Get(&next,&prev,&tp);
		view[type]=next;
		return data;
	}
	else return NULL;
}

void CDList::ResetGet(int type)
{
	view[type]=head[type];
}

int CDList::Del(long val)
{
	int tp;
	long *plong;
	if(head[0]==NULL) return -1;
	if(val<*(long *)head[0]->View()) return -1;
	if(val>*(long *)tail[0]->View()) return -1;
	if(*(long *)head[0]->Get(&next,&prev,&tp)==val)
	{
		delete head[0];
		head[0]=next;
		next->SetDown(NULL);
		view[0]=head[0];
		return 0;
	}
	if(*(long *)tail[0]->Get(&next,&prev,&tp)==val)
	{
		delete tail[0];
		tail[0]=prev;
		tail[0]->SetUp(NULL);
		return 0;
	}
	parc=head[0];
	plong=(long *)parc->Get(&next,&prev,&tp);
	while(val>*plong && parc!=NULL)
	{
		parc=next;
		plong=(long *)parc->Get(&next,&prev,&tp);
	}
	if(parc!=NULL)
	{
		if(val==*(long *)parc->View())
		{
			delete parc;
			prev->SetUp(next);
			next->SetDown(prev);
			return 0;
		}
		else return -1;
	}
	else return -1;
}

int CDList::Del(double val)
{
	int tp;
	double *pdouble;
	if(head[1]==NULL) return -1;
	if(val<*(double *)head[1]->View()) return -1;
	if(val>*(double *)tail[1]->View()) return -1;
	if(fabs(*(double *)head[1]->Get(&next,&prev,&tp)-val)<1e-6)
	{
		delete head[1];
		head[1]=next;
		next->SetDown(NULL);
		view[1]=head[1];
		return 0;
	}
	if(fabs(*(double *)tail[1]->Get(&next,&prev,&tp)-val)<1e-6)
	{
		delete tail[1];
		tail[1]=prev;
		tail[1]->SetUp(NULL);
		return 0;
	}
	parc=head[1];
	pdouble=(double *)parc->Get(&next,&prev,&tp);
	while(val>*pdouble && parc!=NULL)
	{
		parc=next;
		pdouble=(double *)parc->Get(&next,&prev,&tp);
	}
	if(parc!=NULL)
	{
		if(fabs(val-*(double *)parc->View())<1e-6)
		{
			delete parc;
			prev->SetUp(next);
			next->SetDown(prev);
			return 0;
		}
		else return -1;
	}
	else return -1;
}

int CDList::Del(char *val)
{
	int tp;
	char *pchar;
	if(head[2]==NULL) return -1;
	if(strcmp(val,(char *)head[2]->View())<0) return -1;
	if(strcmp(val,(char *)tail[2]->View())>0) return -1;
	if(strcmp((char *)head[2]->Get(&next,&prev,&tp),val)==0)
	{
		delete head[2];
		head[2]=next;
		next->SetDown(NULL);
		view[2]=head[2];
		return 0;
	}
	if(strcmp((char *)tail[2]->Get(&next,&prev,&tp),val)==0)
	{
		delete tail[2];
		tail[2]=prev;
		tail[2]->SetUp(NULL);
		return 0;
	}
	parc=head[2];
	pchar=(char *)parc->Get(&next,&prev,&tp);
	while(strcmp(val,pchar)>0 && parc!=NULL)
	{
		parc=next;
		pchar=(char *)parc->Get(&next,&prev,&tp);
	}
	if(parc!=NULL)
	{
		if(strcmp(val,(char *)parc->View())==0)
		{
			delete parc;
			prev->SetUp(next);
			next->SetDown(prev);
			return 0;
		}
		else return -1;
	}
	else return -1;
}

int CDList::Del(char val)
{
	int tp;
	char *pchar;
	if(head[3]==NULL) return -1;
	if(val<*(char *)head[3]->View()) return -1;
	if(val>*(char *)tail[3]->View()) return -1;
	if(*(char *)head[3]->Get(&next,&prev,&tp)==val)
	{
		delete head[3];
		head[3]=next;
		next->SetDown(NULL);
		view[3]=head[3];
		return 0;
	}
	if(*(char *)tail[3]->Get(&next,&prev,&tp)==val)
	{
		delete tail[3];
		tail[3]=prev;
		tail[3]->SetUp(NULL);
		return 0;
	}
	parc=head[3];
	pchar=(char *)parc->Get(&next,&prev,&tp);
	while(val>*pchar && parc!=NULL)
	{
		parc=next;
		pchar=(char *)parc->Get(&next,&prev,&tp);
	}
	if(parc!=NULL)
	{
		if(val==*(char *)parc->View())
		{
			delete parc;
			prev->SetUp(next);
			next->SetDown(prev);
			return 0;
		}
		else return -1;
	}
	else return -1;
}
