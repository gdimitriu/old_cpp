// stack_el.h: interface for the Cstack_el class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	This is the stack defition.

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

#if !defined(AFX_STACK_EL_H__6C4B74C2_4DFD_11DA_B910_90B240A1F47F__INCLUDED_)
#define AFX_STACK_EL_H__6C4B74C2_4DFD_11DA_B910_90B240A1F47F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "element.h"
class Cstack_el  
{
public:
	void purge();
	bool get(Celement *&val);
	void add(Celement *val);
	Cstack_el();
	virtual ~Cstack_el();
protected:
	struct element
	{
		Celement *info;
		struct element *prev;
	};
	struct element *m_end;
	struct element *m_temp;
};

#endif // !defined(AFX_STACK_EL_H__6C4B74C2_4DFD_11DA_B910_90B240A1F47F__INCLUDED_)
