// tree.cpp: implementation of the Ctree class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	This is the tree implementation.

    Arbori (Data Structures Simulator) is free software; you can redistribute
	it and/or modify it under the terms of the GNU General Public License as 
	published by the Free Software Foundation; either version 2 of the License,
	or (at your option) any later version.

    Arbori (Data Structures Simulator) is distributed in the hope that it will
	be useful,but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Arbori (Data Structures Simulator); if not, write to the Free 
	Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/

#include "stdafx.h"
#include "arbori.h"
#include "tree.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Ctree::Ctree()
{
	m_flag=true;
	m_flag1=true;
	m_first=true;
	m_top=NULL;
}

Ctree::~Ctree()
{
	del(m_top);
	m_top=NULL;
}

void Ctree::add(int val)
{
	int flag;
	int test;
	m_temp=new Celement(val);
	if(m_top==NULL)
	{
		m_top=m_temp;
		return;
	}
	m_temp1=m_top;
	flag=0;
	while(flag==0)
	{
		test=m_temp1->info<m_temp->info;
		if(m_temp1->child[test]==NULL)
		{
			m_temp1->child[test]=m_temp;
			flag=1;
		}
		else m_temp1=m_temp1->child[test];
	}
}

void Ctree::addp(Celement *val)
{
	int flag;
	int test;
	if(m_top==NULL)
	{
		m_top=val;
		return;
	}
	m_temp1=m_top;
	flag=0;
	while(flag==0)
	{
		test=m_temp1->info<val->info;
		if(m_temp1->child[test]==NULL)
		{
			m_temp1->child[test]=val;
			flag=1;
		}
		else m_temp1=m_temp1->child[test];
	}
}

bool Ctree::erase(int val)
{
	int test;
	if(m_top==NULL)	return false;
	if(m_top->info==val)
	{
		Celement *temp;
		temp=m_top;
		m_top=temp->child[0];
		addp(temp->child[1]);
		delete temp;
		return true;
	}
	m_temp1=m_top;
	while(1)
	{
		if(m_temp1->info!=val)
		{
			test=m_temp1->info<val;
			if(m_temp1->child[test]==NULL) return false;
			else
			{
				m_temp=m_temp1;
				m_temp1=m_temp1->child[test];
			}
		}
		else
		{
			Celement *temp;
			temp=m_temp1;
			m_temp->child[test]=NULL;
			if(temp->child[0]!=NULL) addp(temp->child[0]);
			if(temp->child[1]!=NULL) addp(temp->child[1]);
			delete temp;
			return true;
		}
	}
	return false;
}

bool Ctree::get(int &val) //SRD
{
	if(m_top==NULL) return false;
	if(m_first==true)
	{
		m_flag=true;
		m_flag1=true;
		m_temp1=m_top;
		m_first=false;
	}
	if(m_flag==false) return false;
	while(1)
	{
		if(m_temp1->child[0]!=NULL && m_flag1==true)
		{
			m_stack.add(m_temp1);
			m_temp1=m_temp1->child[0];
		}
		else if(m_temp1->child[1]!=NULL)
		{
			val=m_temp1->info;
			m_temp1=m_temp1->child[1];
			m_flag1=true;
			return true;
		}
		else
		{
			val=m_temp1->info;
			if(m_stack.get(m_temp1)==true) m_flag1=false;
			else m_flag=false;
			return true;
		}
	}
}

bool Ctree::getr(int &val)
{
	if(m_top==NULL) return false;
	if(m_first==true)
	{
		m_flag=true;
		m_flag1=true;
		m_temp1=m_top;
		m_first=false;
		val=m_top->info;
		return true;
	}
	if(m_flag==false) return false;
	while(1)
	{
		if(m_temp1->child[0]!=NULL && m_flag1==true)
		{
			m_stack.add(m_temp1);
			m_temp1=m_temp1->child[0];
			val=m_temp1->info;
			return true;
		}
		else if(m_temp1->child[1]!=NULL)
		{
			m_temp1=m_temp1->child[1];
			m_flag1=true;
			val=m_temp1->info;
			return true;
		}
		else
		{
			if(m_stack.get(m_temp1)==true) m_flag1=false;
			else
			{
				m_flag=false;
				return false;
			}
		}
	}

}

void Ctree::reset()
{
	m_first=true;
	m_stack.purge();
}

bool Ctree::search(int val)
{
	int test;
	if(m_top==NULL)	return false;
	m_temp1=m_top;
	while(1)
	{
		if(m_temp1->info!=val)
		{
			test=m_temp1->info<val;
			if(m_temp1->child[test]==NULL) return false;
			else m_temp1=m_temp1->child[test];
		}
		else return true;
	}
	return false;
}

void Ctree::del(Celement *el)
{
	if(el!=NULL)
	{
		del(el->child[0]);
		del(el->child[1]);
		delete el;
	}
}


