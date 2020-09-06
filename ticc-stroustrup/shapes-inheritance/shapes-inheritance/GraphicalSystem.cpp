// GraphicalSystem.cpp : implementation file
//

#include "stdafx.h"
#include "shapes-inheritance.h"
#include "GraphicalSystem.h"
#include "afxdialogex.h"


// CGraphicalSystem dialog

IMPLEMENT_DYNAMIC(CGraphicalSystem, CDialog)

CGraphicalSystem::CGraphicalSystem(CWnd* pParent /*=NULL*/)
	: CDialog(CGraphicalSystem::IDD, pParent)
{

}

CGraphicalSystem::~CGraphicalSystem()
{
}

void CGraphicalSystem::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGraphicalSystem, CDialog)
END_MESSAGE_MAP()


// CGraphicalSystem message handlers


void CGraphicalSystem::draw(CShapes *shape)
{
	CClientDC *pdc;
	pdc=new CClientDC(this);
	shape->draw(pdc);
	delete pdc;
}
