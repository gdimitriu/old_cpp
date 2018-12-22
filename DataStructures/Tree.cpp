// Tree.cpp: implementation of the CTree class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Tree.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTree::CTree()
{
	for(int i=0;i<DATA_TYPES;i++)
	{
		roots[i]=NULL;
		views[i]=NULL;
		was[i]=true;
		m_first[i]=true;
		data[i]=NULL;
	}
	parc=NULL;
	left=right=NULL;
	old=NULL;
}

CTree::~CTree()
{

}

void CTree::Add(long val)
{
	if(roots[0]==NULL)
	{
		roots[0]=new CNode(val,NULL,NULL);
		return;
	}
	parc=roots[0];
	int type;
	long *plong;
	plong=(long *)parc->Get(&right,&left,&type);
	while(1)
	{
		if(val<*plong)
		{
			if(left==NULL)
			{
				nparc=new CNode(val,NULL,NULL);
				parc->SetDown(nparc);
				return;
			}
			parc=left;
		}
		else
		{
			if(right==NULL)
			{
				nparc=new CNode(val,NULL,NULL);
				parc->SetUp(nparc);
				return;
			}
			parc=right;
		}
		plong=(long *)parc->Get(&right,&left,&type);
	}
}

void CTree::Add(double val)
{
	if(roots[1]==NULL)
	{
		roots[1]=new CNode(val,NULL,NULL);
		return;
	}
	parc=roots[1];
	int type;
	double *pdouble;
	pdouble=(double *)parc->Get(&right,&left,&type);
	while(1)
	{
		if(val<*pdouble)
		{
			if(left==NULL)
			{
				nparc=new CNode(val,NULL,NULL);
				parc->SetDown(nparc);
				return;
			}
			parc=left;
		}
		else
		{
			if(right==NULL)
			{
				nparc=new CNode(val,NULL,NULL);
				parc->SetUp(nparc);
				return;
			}
			parc=right;
		}
		pdouble=(double *)parc->Get(&right,&left,&type);
	}
}

void CTree::Add(char *val)
{
	if(roots[2]==NULL)
	{
		roots[2]=new CNode(val,NULL,NULL);
		return;
	}
	parc=roots[2];
	int type;
	char *pchar;
	pchar=(char *)parc->Get(&right,&left,&type);
	while(1)
	{
		if(strcmp(val,pchar)<0)
		{
			if(left==NULL)
			{
				nparc=new CNode(val,NULL,NULL);
				parc->SetDown(nparc);
				return;
			}
			parc=left;
		}
		else
		{
			if(right==NULL)
			{
				nparc=new CNode(val,NULL,NULL);
				parc->SetUp(nparc);
				return;
			}
			parc=right;
		}
		pchar=(char *)parc->Get(&right,&left,&type);
	}

}

void CTree::Add(char val)
{
	if(roots[3]==NULL)
	{
		roots[3]=new CNode(val,NULL,NULL);
		return;
	}
	parc=roots[3];
	int type;
	char *pchar;
	pchar=(char *)parc->Get(&right,&left,&type);
	while(1)
	{
		if(val<*pchar)
		{
			if(left==NULL)
			{
				nparc=new CNode(val,NULL,NULL);
				parc->SetDown(nparc);
				return;
			}
			parc=left;
		}
		else
		{
			if(right==NULL)
			{
				nparc=new CNode(val,NULL,NULL);
				parc->SetUp(nparc);
				return;
			}
			parc=right;
		}
		pchar=(char *)parc->Get(&right,&left,&type);
	}
}

void CTree::Add(CNode *root,int type)
{
	if(roots[type]==NULL)
	{
		roots[type]=root;
		return;
	}
	parc=roots[type];
	int type_l;
	long *plong;
	double *pdouble;
	char *pchar;
	if(type==0)
		plong=(long *)parc->Get(&right,&left,&type_l);
	else if(type==1)
		pdouble=(double *)parc->Get(&right,&left,&type_l);
	else if(type==2 || type==3)
		pchar=(char *)parc->Get(&right,&left,&type_l);
	while(1)
	{
		int quest;
		if(type==0)
			quest=*((long *)root->View())<*plong;
		else if(type==1)
			quest=*((double *)root->View())<*pdouble;
		else if(type==3)
			quest=*((char *)root->View())<*pchar;
		else if(type==2)
			quest=strcmp((char *)root->View(),pchar)<0;
		if(quest)
		{
			if(left==NULL)
			{
				parc->SetDown(root);
				return;
			}
			parc=left;
		}
		else
		{
			if(right==NULL)
			{
				parc->SetUp(root);
				return;
			}
			parc=right;
		}
		if(type==0)
			plong=(long *)parc->Get(&right,&left,&type_l);
		else if(type==1)
			pdouble=(double *)parc->Get(&right,&left,&type_l);
		else if(type==2 || type==3)
			pchar=(char *)parc->Get(&right,&left,&type_l);
	}
}

int CTree::Del(long val)
{
	CNode *right_l,*left_l,*parc_l,*right_l1,*left_l1;
	if(roots[0]==NULL)
	{
		return -1;
	}
	old=NULL;
	parc_l=roots[0];
	int type;
	long *plong;
	plong=(long *)parc_l->Get(&right_l1,&left_l1,&type);
	if(val==*plong)
	{
		delete roots[0];
		roots[0]=right_l1;
		Add(left_l1,0);
		return 0;
	}
	while(1)
	{
		if(val<*plong)
		{
			if(left_l1!=NULL)
			{
				old=parc_l;
				parc_l=left_l1;
			}
			else
				return -1;
		}
		else if(val>*plong)
		{
			if(right_l1==NULL)
				return -1;
			else
			{
				old=parc_l;
				parc_l=right_l1;
			}
		}
		else 
		{
			old->Get(&right_l,&left_l,&type);
			if(right_l==parc_l)
				old->SetUp(NULL);
			else if(left_l==parc_l)
				old->SetDown(NULL);
			if(right_l1!=NULL)
				Add(right_l1,0);
			if(left_l1!=NULL)
				Add(left_l1,0);
			delete parc_l;
			return 0;
		}
		plong=(long *)parc_l->Get(&right_l1,&left_l1,&type);
	}
}

int CTree::Del(double val)
{
	CNode *right_l,*left_l,*parc_l,*right_l1,*left_l1;
	if(roots[1]==NULL)
	{
		return -1;
	}
	old=NULL;
	parc_l=roots[1];
	int type;
	double *pdouble;
	pdouble=(double *)parc_l->Get(&right_l1,&left_l1,&type);
	if(fabs(val-*pdouble)<1e-6)
	{
		delete roots[1];
		roots[0]=right_l1;
		Add(left_l1,1);
		return 0;
	}
	while(1)
	{
		if(val<*pdouble)
		{
			if(left_l1!=NULL)
			{
				old=parc_l;
				parc_l=left_l1;
			}
			else
				return -1;
		}
		else if(val>*pdouble)
		{
			if(right_l1==NULL)
				return -1;
			else
			{
				old=parc_l;
				parc_l=right_l1;
			}
		}
		else 
		{
			old->Get(&right_l,&left_l,&type);
			if(right_l==parc_l)
				old->SetUp(NULL);
			else if(left_l==parc_l)
				old->SetDown(NULL);
			if(right_l1!=NULL)
				Add(right_l1,1);
			if(left_l1!=NULL)
				Add(left_l1,1);
			delete parc_l;
			return 0;
		}
		pdouble=(double *)parc_l->Get(&right_l1,&left_l1,&type);
	}
}

int CTree::Del(char *val)
{
	CNode *right_l,*left_l,*parc_l,*right_l1,*left_l1;
	if(roots[2]==NULL)
	{
		return -1;
	}
	old=NULL;
	parc_l=roots[2];
	int type;
	char *pchar;
	pchar=(char *)parc_l->Get(&right_l1,&left_l1,&type);
	if(strcmp(val,pchar)==0)
	{
		delete roots[2];
		roots[2]=right_l1;
		Add(left_l1,2);
		return 0;
	}
	while(1)
	{
		if(strcmp(val,pchar)<0)
		{
			if(left_l1!=NULL)
			{
				old=parc_l;
				parc_l=left_l1;
			}
			else
				return -1;
		}
		else if(strcmp(val,pchar)>0)
		{
			if(right_l1==NULL)
				return -1;
			else
			{
				old=parc_l;
				parc_l=right_l1;
			}
		}
		else 
		{
			old->Get(&right_l,&left_l,&type);
			if(right_l==parc_l)
				old->SetUp(NULL);
			else if(left_l==parc_l)
				old->SetDown(NULL);
			if(right_l1!=NULL)
				Add(right_l1,2);
			if(left_l1!=NULL)
				Add(left_l1,2);
			delete parc_l;
			return 0;
		}
		pchar=(char *)parc_l->Get(&right_l1,&left_l1,&type);
	}
}

int CTree::Del(char val)
{
	CNode *right_l,*left_l,*parc_l,*right_l1,*left_l1;
	if(roots[0]==NULL)
	{
		return -1;
	}
	old=NULL;
	parc_l=roots[3];
	int type;
	char *pchar;
	pchar=(char *)parc_l->Get(&right_l1,&left_l1,&type);
	if(val==*pchar)
	{
		delete roots[3];
		roots[3]=right_l1;
		Add(left_l1,3);
		return 0;
	}
	while(1)
	{
		if(val<*pchar)
		{
			if(left_l1!=NULL)
			{
				old=parc_l;
				parc_l=left_l1;
			}
			else
				return -1;
		}
		else if(val>*pchar)
		{
			if(right_l1==NULL)
				return -1;
			else
			{
				old=parc_l;
				parc_l=right_l1;
			}
		}
		else 
		{
			old->Get(&right_l,&left_l,&type);
			if(right_l==parc_l)
				old->SetUp(NULL);
			else if(left_l==parc_l)
				old->SetDown(NULL);
			if(right_l1!=NULL)
				Add(right_l1,3);
			if(left_l1!=NULL)
				Add(left_l1,3);
			delete parc_l;
			return 0;
		}
		pchar=(char *)parc_l->Get(&right_l1,&left_l1,&type);
	}
}

void CTree::PrintRSD(CNode *root)
{
	int type;
	if(root==NULL) return;
	CNode *right_l;
	CNode *left_l;
	void *data_l;
	data_l=root->Get(&right_l,&left_l,&type);
	switch(type)
	{
	case 0:
		cout<<*(long *)data_l<<endl;
		break;
	case 1:
		cout<<*(double *)data_l<<endl;
		break;
	case 2:
		cout<<(char *)data_l<<endl;
		break;
	case 3:
		cout<<*(char *)data_l<<endl;
		break;
	default:
		break;
	}
	if(left_l!=NULL)
		PrintRSD(left_l);
	if(right_l!=NULL)
		PrintRSD(right_l);

}

void CTree::PrintRSD(int type)
{
	PrintRSD(roots[type]);
}

void CTree::PrintSRD(CNode *root)
{
	int type;
	if(root==NULL) return;
	CNode *right_l;
	CNode *left_l;
	void *data_l;
	data_l=root->Get(&right_l,&left_l,&type);
	if(left_l!=NULL)
		PrintSRD(left_l);
	switch(type)
	{
	case 0:
		cout<<*(long *)data_l<<endl;
		break;
	case 1:
		cout<<*(double *)data_l<<endl;
		break;
	case 2:
		cout<<(char *)data_l<<endl;
		break;
	case 3:
		cout<<*(char *)data_l<<endl;
		break;
	default:
		break;
	}
	if(right_l!=NULL)
		PrintSRD(right_l);
}

void CTree::PrintSRD(int type)
{
	PrintSRD(roots[type]);
}

void CTree::PrintSDR(CNode *root)
{
	int type;
	if(root==NULL) return;
	CNode *right_l;
	CNode *left_l;
	void *data_l;
	data_l=root->Get(&right_l,&left_l,&type);
	if(left_l!=NULL)
		PrintSDR(left_l);
	if(right_l!=NULL)
		PrintSDR(right_l);
	switch(type)
	{
	case 0:
		cout<<*(long *)data_l<<endl;
		break;
	case 1:
		cout<<*(double *)data_l<<endl;
		break;
	case 2:
		cout<<(char *)data_l<<endl;
		break;
	case 3:
		cout<<*(char *)data_l<<endl;
		break;
	default:
		break;
	}
}

void CTree::PrintSDR(int type)
{
	PrintSDR(roots[type]);
}


void * CTree::Get(int type) //SRD
{
	int m_type;
	if(roots[type]==NULL)
		return NULL;
	if(views[type]==NULL && stacks[type].IsEmpty()==true && m_first[type]==false)
		return NULL;
	if(m_first[type]==true)
	{
		m_first[type]=false;
		views[type]=roots[type];
		was[type]=true;
	}
	while(1)
	{
		if(views[type]->GetDown()!=NULL && was[type]==true)
		{
			stacks[type].Push(views[type]);
			views[type]=views[type]->GetDown();
		}
		else if(views[type]->GetUp()!=NULL)
		{
			data[type]=views[type]->Get(&right,&left,&m_type);
			views[type]=right;
			was[type]=true;
			return data[type];
		}
		else 
		{
			data[type]=views[type]->Get(&right,&left,&m_type);
			views[type]=stacks[type].Pop();
			if(views[type]!=NULL) was[type]=false;
			return data[type];
		}	
	}
}

void CTree::ResetGet(int type)
{
	views[type]=NULL;
	stacks[type].Empty();
	was[type]=true;
	m_first[type]=true;
	data[type]=NULL;
}
