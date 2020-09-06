#pragma once
#include "resource.h"
#include "Shapes.h"

// CGraphicalSystem dialog

class CGraphicalSystem : public CDialog
{
	DECLARE_DYNAMIC(CGraphicalSystem)

public:
	CGraphicalSystem(CWnd* pParent = NULL);   // standard constructor
	virtual ~CGraphicalSystem();

// Dialog Data
	enum { IDD = IDD_GRAPHICALSYSTEM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void draw(CShapes *shape);
};
