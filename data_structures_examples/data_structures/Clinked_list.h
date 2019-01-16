#pragma once
class Clinked_list
{
public:
	class Clinked_list_element
	{
	public:
		int m_data;
		Clinked_list_element(int item)
		{
			m_data=item;
			next_ptr=NULL;
		}
	private:
		Clinked_list_element *next_ptr;
		friend class Clinked_list;
	};
public:
	Clinked_list_element *m_first_element;
	Clinked_list(void);
	~Clinked_list(void);
	void add_list_first(int item);
	void print(void);
	int find(int item);
	void add_list(int item);
	void clean(void);
};

