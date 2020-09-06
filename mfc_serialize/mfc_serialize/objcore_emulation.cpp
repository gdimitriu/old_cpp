#pragma once
#include "CRuntimeClass_emulation.h"
#include "CObject_emulation.h"

// special runtime-class structure for CObject (no base class)
const struct CRuntimeClass CObject::classCObject =
	{ "CObject", sizeof(CObject), 0xffff, NULL, NULL, NULL };

void AFXAPI AfxClassInit(CRuntimeClass* pNewClass)
{
	AFX_MODULE_STATE* pModuleState = AfxGetModuleState();
	AfxLockGlobals(CRIT_RUNTIMECLASSLIST);
	pModuleState->m_classList.AddHead(pNewClass);
	AfxUnlockGlobals(CRIT_RUNTIMECLASSLIST);
} 

CRuntimeClass* CObject::GetRuntimeClass() const
{
	return _RUNTIME_CLASS(CObject);
}

BOOL CObject::IsKindOf(const CRuntimeClass* pClass) const
{
	// simple SI case
	CRuntimeClass* pClassThis = GetRuntimeClass();

	return pClassThis->IsDerivedFrom(pClass);
}

BOOL CObject::IsSerializable() const
{
	return (GetRuntimeClass()->m_wSchema != 0xffff);
}

inline CObject::CObject()
{

}

inline CObject::~CObject()
{

}

void CObject::Serialize(CArchive&)
{
//no serialization by default
}

/*----------------------------------------------------------------------
** CRuntimeClass
**--------------------------------------------------------------------*/
BOOL CRuntimeClass::IsDerivedFrom(const CRuntimeClass* pBaseClass) const
{
	// simple SI case
	const CRuntimeClass* pClassThis = this;
	while (pClassThis != NULL)
	{
		if (pClassThis == pBaseClass)
			return TRUE;
		pClassThis = pClassThis->m_pBaseClass;
	}
	return FALSE;       // walked to the top, no match
}

////////////////////////////////////////////////////////////////////////////
// Allocation/Creation

CObject* CRuntimeClass::CreateObject()
{
	if (m_pfnCreateObject == NULL)
	{
		return NULL;
	}

	CObject* pObject = NULL;
	try
	{
		pObject = (*m_pfnCreateObject)();
	}
	catch (...)
	{
	}

	return pObject;
}

/*---------------------------------------------------
*****************************************************
***            Dynamic creation from archive
*****************************************************
---------------------------------------------------*/

CRuntimeClass* PASCAL CRuntimeClass::FromName(LPCSTR lpszClassName)
{
	CRuntimeClass* pClass=NULL;

	// search app specific classes
	AFX_MODULE_STATE* pModuleState = AfxGetModuleState();
	AfxLockGlobals(CRIT_RUNTIMECLASSLIST);
	for (pClass = pModuleState->m_classList; pClass != NULL;
		pClass = pClass->m_pNextClass)
	{
		if (lstrcmpA(lpszClassName, pClass->m_lpszClassName) == 0)
		{
			AfxUnlockGlobals(CRIT_RUNTIMECLASSLIST);
			return pClass;
		}
	}
	AfxUnlockGlobals(CRIT_RUNTIMECLASSLIST);

	return NULL; // not found
}

CRuntimeClass* PASCAL CRuntimeClass::FromName(LPCWSTR lpszClassName)
{	
	const CStringA strClassName(lpszClassName);	
	if( lpszClassName == NULL )
		return NULL;
	return CRuntimeClass::FromName( strClassName.GetString() );
}