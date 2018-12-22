// stack.h: interface for the Cstack class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	This is the stack definition.

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

#if !defined(AFX_STACK_H__22E15221_4DF1_11DA_B910_90B240A1F47F__INCLUDED_)
#define AFX_STACK_H__22E15221_4DF1_11DA_B910_90B240A1F47F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "data.h"

class Cstack  : public Cdata
{
public:
	virtual void purge();
	virtual bool search(int val);
	virtual bool erase(int val);
	virtual void reset();
	virtual bool get(int &val);
	virtual void add(int val);
	Cstack();
	virtual ~Cstack();
protected:
	struct nod
	{
		int info;
		struct nod *prev;
	};
	struct nod *m_end;
	struct nod *m_temp;
};

#endif // !defined(AFX_STACK_H__22E15221_4DF1_11DA_B910_90B240A1F47F__INCLUDED_)
