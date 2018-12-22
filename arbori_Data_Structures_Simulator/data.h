// data.h: interface for the Cdata class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Arbori (Data Structures Simulator).
	This is the data class.

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

#if !defined(AFX_DATA_H__1365B202_4BD5_11DA_B910_898F3D663870__INCLUDED_)
#define AFX_DATA_H__1365B202_4BD5_11DA_B910_898F3D663870__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Cdata  
{
public:
	Cdata();
	virtual ~Cdata();
	virtual bool search(int val)=0;
	virtual bool get(int &val)=0;
	virtual void add(int val)=0;
	virtual void reset()=0;
	virtual bool erase(int val)=0;
};

#endif // !defined(AFX_DATA_H__1365B202_4BD5_11DA_B910_898F3D663870__INCLUDED_)
