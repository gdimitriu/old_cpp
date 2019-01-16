#include "StdAfx.h"
#include "Cdoublelinked_list.h"
#include <iostream>
using namespace std;

Cdoublelinked_list::Cdoublelinked_list(void)
{
	m_first_element=NULL;
}


Cdoublelinked_list::~Cdoublelinked_list(void)
{
	Cdoublelinked_element *current_element;
	while(NULL!=m_first_element)
	{
		current_element=m_first_element;
		m_first_element=m_first_element->next_pointer;
		delete current_element;
	}
}


void Cdoublelinked_list::add(int item)
{
	Cdoublelinked_element *current_element;
	Cdoublelinked_element *new_elem;
	new_elem=new Cdoublelinked_element(item);
	if(NULL==m_first_element)
	{
		m_first_element=new_elem;
		return;
	}
	if(m_first_element->m_data>=item)
	{
		m_first_element->previous_pointer=new_elem;
		new_elem->next_pointer=m_first_element;
		m_first_element=new_elem;
		return;
	}
	current_element=m_first_element;
	while(NULL!=current_element)
	{
		if(NULL!=current_element->next_pointer)
		{
			if(current_element->m_data<item && current_element->next_pointer->m_data>=item)
			{
				current_element->next_pointer->previous_pointer=new_elem;
				new_elem->next_pointer=current_element->next_pointer;
				new_elem->previous_pointer=current_element;
				current_element->next_pointer=new_elem;
				break;
			}
			else
			{
				current_element=current_element->next_pointer;
			}
		}
		else
		{
			new_elem->previous_pointer=current_element;
			current_element->next_pointer=new_elem;
			break;
		}
	}
}


void Cdoublelinked_list::print(void)
{
	Cdoublelinked_element *current_element;
	current_element=m_first_element;
	while(1)
	{
		if(NULL==current_element)
		{
			break;
		}
		else
		{
			cout<<current_element->m_data<<"\n";
			current_element=current_element->next_pointer;
		}
	}
}
