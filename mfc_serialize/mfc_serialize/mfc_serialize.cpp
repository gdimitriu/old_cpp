//#include "CObArray_emulation.h"

#ifndef _MFC_EMULATION
	#include <afxwin.h>
#endif
#include <cassert>

class CMyValue : public CObject
{
public:
	DECLARE_SERIAL(CMyValue);
	CMyValue()
	{
		uInt_=0;
	}
	virtual void Serialize(CArchive &ar)
	{
		CObject::Serialize(ar);
		if (ar.IsStoring())
		{
			ar<<uInt_;
		}
		else
		{
			ar>>uInt_;
		}
	}
	unsigned int uInt_;
};

IMPLEMENT_SERIAL(CMyValue,CObject,1);

using namespace std;

class StorageClass : public CObject
{
public:
	DECLARE_SERIAL(StorageClass);
	StorageClass()
	{		
	}
	void Save(void)
	{
		CMyValue *value1;
		value1=new CMyValue;
		value1->uInt_=101;
		carray_.Add(value1);
		CFile *pFile=new CFile(_T("stored.dat"),CFile::modeCreate | CFile::modeWrite);
		CArchive arSave(pFile,CArchive::store);
		this->Serialize(arSave);
		arSave.Close();
		pFile->Close();
		delete pFile;
	}
	void Load(void)
	{
		CFile *pFile=new CFile(_T("stored.dat"),CFile::modeRead);
		CArchive arLoad(pFile,CArchive::load);
		this->Serialize(arLoad);
		arLoad.Close();
		pFile->Close();
		delete pFile;
		CMyValue *value1=dynamic_cast<CMyValue*>(carray_.GetAt(0));
		ASSERT(value1->uInt_==101);
	}
	virtual void Serialize(CArchive &ar)
	{
		CObject::Serialize(ar);
		carray_.Serialize(ar);
	}
private:
	CObArray carray_;
};

IMPLEMENT_SERIAL(StorageClass,CObject,1);


#ifndef _MFC_EMULATION
	CWinApp theApp;
#endif

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
#ifndef _MFC_EMULATION
	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0)) return 0;
	}
	else return 0;
#endif
	StorageClass val;
//	val.Save();
	val.Load();

}