#pragma once
class CDog
{
protected:
	char* m_Name;
	int m_Age;
private:
	static int m_NrOfInstances;
public:
	CDog(const char *name,int age);
	CDog(void);
	~CDog(void);
	static int NumberOfInstances(void);
	void PrintIndetifier(void);
};

