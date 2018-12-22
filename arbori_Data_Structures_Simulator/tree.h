// tree.h: interface for the Ctree class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	This is the tree defition.

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

#if !defined(AFX_TREE_H__2D2F0241_4DF6_11DA_B910_90B240A1F47F__INCLUDED_)
#define AFX_TREE_H__2D2F0241_4DF6_11DA_B910_90B240A1F47F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "data.h"
#include "element.h"
#include "stack_el.h"
class Ctree : public Cdata  
{
public:
	virtual bool getr(int &val);
	virtual bool search(int val);
	virtual void reset();
	virtual bool get(int &val);
	virtual bool erase(int val);
	virtual void add(int val);
	Ctree();
	virtual ~Ctree();
protected:
	virtual void addp(Celement *val);
	void del(Celement *el);
	bool m_first;
	bool m_flag1;
	bool m_flag;
	Celement *m_top,*m_temp,*m_temp1;
	Cstack_el m_stack;
};

#endif // !defined(AFX_TREE_H__2D2F0241_4DF6_11DA_B910_90B240A1F47F__INCLUDED_)
