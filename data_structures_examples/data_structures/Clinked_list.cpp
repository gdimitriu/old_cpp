#include "StdAfx.h"
#include "Clinked_list.h"
#include <iostream>
using namespace std;


Clinked_list::Clinked_list(void)
{
	m_first_element=NULL;
}


Clinked_list::~Clinked_list(void)
{
	Clinked_list_element *current_position_next;
	current_position_next=m_first_element;
	while(NULL!=m_first_element)
	{
		current_position_next=m_first_element;
		m_first_element=m_first_element->next_ptr;
		delete current_position_next;
	}
}

void Clinked_list::clean(void)
{
	Clinked_list_element *current_position_next;
	current_position_next=m_first_element;
	while(NULL!=m_first_element)
	{
		current_position_next=m_first_element;
		m_first_element=m_first_element->next_ptr;
		delete current_position_next;
	}
	m_first_element=NULL;
}


void Clinked_list::add_list_first(int item)
{
	Clinked_list_element *new_elem;
	new_elem=new Clinked_list_element(item);
	new_elem->next_ptr=m_first_element;
	m_first_element=new_elem;
}

void Clinked_list::print(void)
{
	Clinked_list_element *current_position;
	current_position=m_first_element;
	while(NULL!=current_position)
	{
		cout<<current_position->m_data<<"\n";
		current_position=current_position->next_ptr;
	}
}


int Clinked_list::find(int item)
{
	Clinked_list_element *current_position;
	current_position=m_first_element;
	while(NULL!=current_position)
	{
		if(item==current_position->m_data)
			return 1;
		current_position=current_position->next_ptr;
	}
	return 0;
}


void Clinked_list::add_list(int item)
{
	Clinked_list_element *new_elem;
	new_elem=new Clinked_list_element(item);
	if(NULL==m_first_element)
	{
		m_first_element=new_elem;
		return;
	}
	Clinked_list_element *current_position;
	current_position=m_first_element;
	if(item<=current_position->m_data)
	{
		new_elem->next_ptr=m_first_element;
		m_first_element=new_elem;
	}
	else
	{
		while(1)
		{
			if(NULL==current_position->next_ptr)
			{
				//end of list
				current_position->next_ptr=new_elem;
				return;
			}
			else
			{
				if(current_position->m_data<item && current_position->next_ptr->m_data>=item)
				{
					new_elem->next_ptr=current_position->next_ptr;
					current_position->next_ptr=new_elem;
					return;
				}
				current_position=current_position->next_ptr;
			}
		}
	}
}

