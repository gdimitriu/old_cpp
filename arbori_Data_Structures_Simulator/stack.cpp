// stack.cpp: implementation of the Cstack class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	This is the stack implementation.

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
#include "stack.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Cstack::Cstack()
{
	m_end=NULL;
}

Cstack::~Cstack()
{
	while(m_end!=NULL)
	{
		m_temp=m_end;
		m_end=m_end->prev;
		delete m_temp;
	}
	m_end=NULL;
}

void Cstack::add(int val)
{
	if(m_end==NULL)
	{
		m_end=new (struct nod);
		m_end->prev=NULL;
		m_end->info=val;
	}
	else
	{
		m_temp=new (struct nod);
		m_temp->prev=m_end;
		m_temp->info=val;
		m_end=m_temp;
	}
}

bool Cstack::get(int &val)
{
	
	if(m_end==NULL) return false;
	val=m_end->info;
	m_temp=m_end;
	m_end=m_end->prev;
	delete m_temp;
	return true;
}

void Cstack::reset()
{

}

bool Cstack::erase(int val)
{
	return false;
}

bool Cstack::search(int val)
{
	return false;
}

void Cstack::purge()
{
	while(m_end!=NULL)
	{
		m_temp=m_end;
		m_end=m_end->prev;
		delete m_temp;
	}
	m_end=NULL;
}
