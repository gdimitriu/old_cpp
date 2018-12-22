// listaDL.h: interface for the ClistaDL class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	This is the double link list definition.

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

#if !defined(AFX_LISTADL_H__03C450EF_49FA_11DA_B910_B337BE9EF70F__INCLUDED_)
#define AFX_LISTADL_H__03C450EF_49FA_11DA_B910_B337BE9EF70F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "data.h"
class ClistaDL  : public Cdata
{
public:
	bool erase(int val);
	void reset();
	bool search(int val);
	bool get(int &val);
	void add(int val);
	ClistaDL();
	virtual ~ClistaDL();
protected:
	struct nod
	{
		int val;
		struct nod *next;
		struct nod *prev;
	};
	struct nod *m_list;
	struct nod *m_end;
	struct nod *m_beg;
	struct nod *m_parc;
	struct nod *m_pos;
	bool m_first;
};

#endif // !defined(AFX_LISTADL_H__03C450EF_49FA_11DA_B910_B337BE9EF70F__INCLUDED_)
