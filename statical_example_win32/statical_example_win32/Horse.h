#pragma once
class CHorse
{
protected:
	char* m_Name;
	int m_Age;
private:
	static int m_NrOfInstances;
public:
	CHorse(const char *name,int age);
	CHorse(void);
	~CHorse(void);
	static int NumberOfInstances(void);
	void PrintIndetifier(void);
};

