// computer.h: interface for the Ccomputer class.
//
//////////////////////////////////////////////////////////////////////
/*
	Copyright 2006 Gabriel Dimitriu

	This file is part of Computer.
	This is the definition of the model of the computer.
	
    Computer is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Computer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Computer; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/
#if !defined(AFX_COMPUTER_H__1E7690EF_AAAA_11DA_B910_FF68DBF41048__INCLUDED_)
#define AFX_COMPUTER_H__1E7690EF_AAAA_11DA_B910_FF68DBF41048__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Ccomputer  
{
public:
	void get(double *rez);
	void delop();
	void operatie(char ch);
	void Addop(char ch);
	Ccomputer();
	virtual ~Ccomputer();
protected:
	char last;
	bool isop;
	double rez;
	double oper;
	double inter;
	CString input;
};

#endif // !defined(AFX_COMPUTER_H__1E7690EF_AAAA_11DA_B910_FF68DBF41048__INCLUDED_)
