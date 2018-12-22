// Node.cpp: implementation of the CNode class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Node.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNode::CNode()
{
	data=NULL;
	down=NULL;
	up=NULL;
	type=-1;
}
CNode::CNode(long val,CNode *up,CNode *down)
{
	type=0;
	data=(long *)calloc(1,sizeof(long));
	*((long *)data)=val;
	this->up=up;
	this->down=down;
}

CNode::CNode(double val,CNode *up,CNode *down)
{
	type=1;
	data=(double *)calloc(1,sizeof(double));
	*((double *)data)=val;
	this->up=up;
	this->down=down;
}

CNode::CNode(char *val,CNode *up,CNode *down)
{
	type=2;
	int dim=strlen(val);
	if(dim>0)
	{
		data=(char *)calloc(dim+1,sizeof(char));
		strcpy((char *)data,val);
	}
	this->up=up;
	this->down=down;
}

CNode::CNode(char val,CNode *up,CNode *down)
{
	type=3;
	data=(char *)calloc(1,sizeof(char));
	*((char *)data)=val;
	this->up=up;
	this->down=down;
}

	
CNode::~CNode()
{
	if(data!=NULL) free(data);
}

void * CNode::Get(CNode **up, CNode **down, int *type)
{
	*up=this->up;
	*down=this->down;
	*type=this->type;
	return data;
}

void CNode::SetUp(CNode *up)
{
	this->up=up;
}

void CNode::SetDown(CNode *down)
{
	this->down=down;
}

void * CNode::View()
{
	return data;
}

CNode * CNode::GetUp()
{
	return up;
}

CNode * CNode::GetDown()
{
	return down;
}
