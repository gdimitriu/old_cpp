// listaDL.cpp: implementation of the ClistaDL class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	This is the double link list implementation.	

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
#include "listaDL.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ClistaDL::ClistaDL()
{
	m_beg=NULL;
	m_end=NULL;
	m_list=NULL;
	m_parc=NULL;
	m_pos=NULL;
	m_first=true;
}

ClistaDL::~ClistaDL()
{
	m_parc=m_beg;
	while(m_parc!=NULL)
	{
		m_list=m_parc;
		m_parc=m_parc->next;
		delete m_list;
	}
}

void ClistaDL::add(int val)
{
	if(m_beg==NULL)
	{
		m_parc=new (struct nod);
		m_parc->next=NULL;
		m_parc->prev=NULL;
		m_parc->val=val;
		m_beg=m_end=m_parc;
		return;
	}
	else
	{
		m_parc=m_beg;
		if(m_end->val<=val)
		{
			m_list=new (struct nod);
			m_list->next=NULL;
			m_list->prev=m_end;
			m_list->val=val;
			m_end->next=m_list;
			m_end=m_list;
			return;
		}
		if(m_beg->val>=val)
		{
			m_list=new (struct nod);
			m_list->next=m_beg;
			m_beg->prev=m_list;
			m_list->prev=NULL;
			m_list->val=val;
			m_beg=m_list;
			return;
		}
		while(m_parc!=NULL)
		{
			if(m_parc->val<val) m_parc=m_parc->next;
			else
			{
				m_list=new (struct nod);
				m_list->next=m_parc;
				m_list->prev=m_parc->prev;
				m_list->val=val;
				m_parc->prev->next=m_list;
				m_parc->prev=m_list;
				return;
			}
		}
	}
}

bool ClistaDL::get(int &val)
{
	if(m_first==true)
	{
		m_pos=m_beg;
		m_first=false;
	}
	m_parc=m_pos;
	if(m_parc!=NULL)
	{
		m_pos=m_pos->next;
		val=m_parc->val;
		return true;
	}
	else return false;
}

bool ClistaDL::search(int val)
{
	m_parc=m_beg;
	while(m_parc!=NULL)
	{
		if(m_parc->val!=val) m_parc=m_parc->next;
		else break;
	}
	if(m_parc!=NULL) return true;
	else return false;
}

void ClistaDL::reset()
{
	m_first=true;
}

bool ClistaDL::erase(int val)
{
	m_parc=m_beg;
	struct nod *temp;
	while(m_parc!=NULL)
	{
		if(m_parc->val!=val) m_parc=m_parc->next;
		else
		{
			temp=m_parc;
			if(m_parc->prev==NULL)
			{
				m_beg=m_parc->next;
				m_beg->prev=NULL;
			}
			else
			{
				m_parc->prev->next=m_parc->next;
				if(m_parc->next==NULL) m_end=m_parc->prev;
			}
			delete m_parc;
			return true;
		}
	}
	return false;
}
