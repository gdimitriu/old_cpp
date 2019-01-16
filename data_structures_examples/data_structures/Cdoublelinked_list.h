#pragma once
class Cdoublelinked_list
{
public:
	class Cdoublelinked_element
	{
	public:
		int m_data;
		Cdoublelinked_element(int item)
		{
			next_pointer=NULL;
			previous_pointer=NULL;
			m_data=item;
		}
	private:
		Cdoublelinked_element *next_pointer;
		Cdoublelinked_element *previous_pointer;
		friend class Cdoublelinked_list;
	};
private:
	Cdoublelinked_element *m_first_element;
public:
	Cdoublelinked_list(void);
	~Cdoublelinked_list(void);
	void add(int item);
	void print(void);
};

