// stack_el.cpp: implementation of the Cstack_el class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "arbori.h"
#include "stack_el.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
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

Cstack_el::Cstack_el()
{
	m_end=NULL;
}

Cstack_el::~Cstack_el()
{
	while(m_end!=NULL)
	{
		m_temp=m_end;
		m_end=m_end->prev;
		delete m_temp;
	}
}

void Cstack_el::add(Celement *val)
{
	if(m_end==NULL)
	{
		m_end=new (struct element);
		m_end->prev=NULL;
		m_end->info=val;
	}
	else
	{
		m_temp=new (struct element);
		m_temp->info=val;
		m_temp->prev=m_end;
		m_end=m_temp;
	}
}

bool Cstack_el::get(Celement * &val)
{
	if(m_end==NULL) return false;
	val=m_end->info;
	m_temp=m_end;
	m_end=m_end->prev;
	delete m_temp;
	return true;
}

void Cstack_el::purge()
{
	while(m_end!=NULL)
	{
		m_temp=m_end;
		m_end=m_end->prev;
		delete m_temp;
	}
}
