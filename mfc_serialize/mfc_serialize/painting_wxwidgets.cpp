#include "wx/wx.h"
#include <fstream>
#include <vector>
#include<stdlib.h>

class CArchive;
class CObject;
/*
 CObject emulation for MFC
*/
class CObject
{
public:
	CObject(){};
	virtual void Serialize(CArchive& ar)
	{
	};
};

/*
 CArchive emulation for MFC
*/
class CArchive
{
public:
	CArchive(){};
	CArchive(std::ifstream *in)
	{
		_pin=in;
		_storing=false;
	}
	CArchive(std::ofstream *out)
	{
		_pout=out;
		_storing=true;
	}
	bool IsStoring()
	{
		return _storing;
	};
	void WriteCount(unsigned int value)
	{
		char *buff=new char[sizeof(value)];
		_itoa(value,buff,10);
		_pout->write(buff,sizeof(value));
		delete[] buff;
	}
	unsigned int ReadCount(void)
	{
		unsigned int temp;
		char *buff=new char[sizeof(temp)];
		_pin->read(buff,sizeof(temp));
		temp=atoi(buff);
		delete[] buff;
		return temp;
	}
	CArchive &operator<<(CObject *& value)
	{
		return *this;
	}
	CArchive &operator>>(CObject *& value)
	{
		return *this;
	}
	//wrong it should have a brand new definition of overloading using UNALIGNED WORD,DWORD,FLOAT etc
	template<class mtype>
	CArchive &operator <<(mtype& value)
	{
		(*_pout)<<value;
		return *this;
	}
	template<class mtype>
	CArchive &operator>>(mtype& value)
	{
		(*_pin)>>value;
		return *this;
	}
private:
	std::ifstream *_pin;
	std::ofstream *_pout;
	bool _storing;
};

/*
 CObArray emulation for MFC
*/
class CObArray : public CObject
{
public:
	CObArray()
	{

	};
	virtual void Serialize(CArchive& ar)
	{
		CObject::Serialize(ar);

		if (ar.IsStoring())
		{
			ar.WriteCount(_values.size());
			for (unsigned int i = 0; i < _values.size(); i++)
				ar << _values[i];
		}
		else
		{
			unsigned int nOldSize = ar.ReadCount();
			_values.reserve(nOldSize);
			for (unsigned int i = 0; i < nOldSize; i++)
				ar >> _values[i];
		}
	};
	void Add(CObject * ob)
	{
		_values.push_back(ob);
	}
	CObject *GetAt(int index)
	{
		return _values.at(index);
	}
protected:
	std::vector<CObject *> _values;
};

/*
 CPoint emulation for MFC
*/
class CPoint
{
public:
	CPoint():x(0),y(0){};
	CPoint(int dx,int dy):x(dx),y(dy){};
	int x;
	int y;
};
//////////////////////////////////////////////////////////////////////////////////
/*
	from here it starts the implementation of the example
*/

class CMyPoint : public CObject
{
public:
	CMyPoint(CPoint point)
	{
		m_point=point;
	}
	CMyPoint()
	{
	}
	virtual void Serialize(CArchive& ar)
	{
		if (ar.IsStoring())
		{
			//normal code for storing contents 
			//of this object
			ar<<m_point.x;
			ar<<m_point.y;
		}
		else
		{
			//normal code for reading contents 
			//of this object
			ar>>m_point.x;
			ar>>m_point.y;
		}

		//allow the base class to serialize along 
		//with its version information
		CObject::Serialize(ar);
	}
	int GetX() { return m_point.x;}
	int GetY() { return m_point.y;}
protected:
	CPoint m_point;
};


class CMyApp : public wxApp
{
public:
	virtual bool OnInit();
};

class CMyWindow : public wxFrame
{
public:
	CMyWindow();
	void OnMouseMove(wxMouseEvent& event);
	void OnLButtonUp(wxMouseEvent& event);
	void OnRButtonDown(wxMouseEvent& event);
	virtual void Serialize(CArchive& ar)
	{
		m_values.Serialize(ar);
	}
	wxDECLARE_EVENT_TABLE();
protected:
	CObArray m_values;
};

bool CMyApp::OnInit()
{
	wxApp::OnInit();
	CMyWindow *frame=new CMyWindow();
	frame->Show(true);
	return true;
}

wxBEGIN_EVENT_TABLE(CMyWindow,wxFrame)
	EVT_MOTION(CMyWindow::OnMouseMove)
	EVT_LEFT_UP(CMyWindow::OnLButtonUp)
	EVT_RIGHT_DOWN(CMyWindow::OnRButtonDown)
wxEND_EVENT_TABLE();

CMyWindow::CMyWindow()
{
	Create(NULL,100,"painting",wxPoint(100,100),wxSize(400,400));
}

IMPLEMENT_APP(CMyApp);

void CMyWindow::OnMouseMove(wxMouseEvent& event)
{
	if(event.LeftIsDown())
	{
		wxPoint point;
		point=event.GetPosition();
		wxClientDC dc(this);
		dc.DrawPoint(point);
		CMyPoint* pPoint=new CMyPoint(CPoint(point.x,point.y));
		m_values.Add(pPoint);
	}
}

void CMyWindow::OnLButtonUp(wxMouseEvent& event)
{
	std::ofstream file(_T("stored.dat"),std::ios::binary);
	if(file.is_open())
	{
		CArchive ar(&file);
		Serialize(ar);
		file.close();
	}
}

void CMyWindow::OnRButtonDown(wxMouseEvent& event)
{
	std::ifstream file(_T("stored.dat"),std::ios::binary);
	if(file.is_open())
	{
		CArchive ar(&file);
		Serialize(ar);
		file.close();
	}
}