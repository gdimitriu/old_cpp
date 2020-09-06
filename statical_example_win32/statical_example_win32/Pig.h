#pragma once
class CPig
{
protected:
	char* m_Name;
	int m_Age;
private:
	static int m_NrOfInstances;
public:
	CPig(const char *name,int age);
	CPig(void);
	~CPig(void);
	static int NumberOfInstances(void);
	void PrintIndetifier(void);
};

