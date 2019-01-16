#pragma once
class Ccomplex
{
protected:
	double m_RealPart;
	double m_ImaginaryPart;
public:
	Ccomplex(void);
	Ccomplex(const Ccomplex &complex);
	Ccomplex(const double real,const double imaginary);
	~Ccomplex(void);
	double real(void) const
	{
		return(m_RealPart);
	}
	double imaginary(void) const
	{
		return(m_ImaginaryPart);
	}
	void set_real(double real)
	{
		m_RealPart=real;
	}
	void set_imaginary(double imaginary)
	{
		m_ImaginaryPart=imaginary;
	}
	void set(double real,double imaginary)
	{
		m_RealPart=real;
		m_ImaginaryPart=imaginary;
	}
	//=
	Ccomplex& operator =(const Ccomplex &oper)
	{
		m_RealPart=oper.m_RealPart;
		m_ImaginaryPart=oper.m_ImaginaryPart;
	}
	//++c
	Ccomplex& operator ++(void)
	{
		++m_RealPart;
		return(*this);
	}
	//c++
	Ccomplex& operator ++(int oper)
	{
		++m_RealPart;
		return(*this);
	}
	//--c
	Ccomplex& operator --(void)
	{
		--m_RealPart;
		return(*this);
	}
	//c--
	Ccomplex& operator --(int oper)
	{
		--m_RealPart;
		return(*this);
	}
	Ccomplex& operator +=(const double real)
	{
		m_RealPart+=real;
		return(*this);
	}
	Ccomplex& operator +=(const Ccomplex &oper)
	{
		m_RealPart+=oper.m_RealPart;
		m_ImaginaryPart+=oper.m_ImaginaryPart;
		return(*this);
	}
	Ccomplex& operator -=(const double real)
	{
		m_RealPart-=real;
		return(*this);
	}
	Ccomplex& operator -=(const Ccomplex &oper)
	{
		m_RealPart-=oper.m_RealPart;
		m_ImaginaryPart-=oper.m_ImaginaryPart;
		return(*this);
	}
};

inline Ccomplex operator +(const Ccomplex &oper1,const Ccomplex &oper2)
{
	return Ccomplex(oper1.real()+oper2.real(),oper1.imaginary()+oper2.imaginary());
}

inline Ccomplex operator +(const double oper1,const Ccomplex &oper2)
{
	return(Ccomplex(oper1+oper2.real(),oper2.imaginary()));
}

inline Ccomplex operator +(const Ccomplex &oper1,const double oper2)
{
	return(Ccomplex(oper1.real()+oper2,oper1.imaginary()));
}

inline Ccomplex operator -(const Ccomplex &oper1,const Ccomplex &oper2)
{
	return Ccomplex(oper1.real()-oper2.real(),oper1.imaginary()-oper2.imaginary());
}

inline Ccomplex operator -(const double oper1,const Ccomplex &oper2)
{
	return(Ccomplex(oper1-oper2.real(),-oper2.imaginary()));
}

inline Ccomplex operator -(const Ccomplex &oper1,const double oper2)
{
	return(Ccomplex(oper1.real()-oper2,-oper1.imaginary()));
}

inline Ccomplex operator -(const Ccomplex &oper1)
{
	return(Ccomplex(-oper1.real(),-oper1.imaginary()));
}