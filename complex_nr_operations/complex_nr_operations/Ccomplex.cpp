#include "StdAfx.h"
#include "Ccomplex.h"


Ccomplex::Ccomplex(void)
{
	m_RealPart=0.0;
	m_ImaginaryPart=0.0;
}

Ccomplex::Ccomplex(const double real,const double imaginary=0.0)
{
	m_RealPart=real;
	m_ImaginaryPart=imaginary;
}

Ccomplex::~Ccomplex(void)
{
}

Ccomplex::Ccomplex(const Ccomplex &complex)
{
	m_RealPart=complex.m_RealPart;
	m_ImaginaryPart=complex.m_ImaginaryPart;
}
