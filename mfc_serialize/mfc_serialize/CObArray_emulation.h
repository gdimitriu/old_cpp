#pragma once
#include "CArchive_emulation.h"
#include "CObject_emulation.h"
#include <vector>

/*
 CObArray emulation for MFC
*/
class CObArray : public CObject
{
	DECLARE_SERIAL(CObArray)
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
