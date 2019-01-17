#include <iostream>
#include "intrusive_list.h"
#include "nonintrusive_list.h"
#include "intrusive_dlist.h"
#include "nonintrusive_dlist.h"
#include "elem.h"
#include "delem.h"
#include <cassert>

int main(int argc, char* argv[])
{
	intrusive_list lista;
	Celem<int> *elem;
	elem=new Celem<int>(1);
	lista.push_front(elem);
	elem=new Celem<int>(2);
	lista.push_front(elem);
	elem=new Celem<int>(10);
	lista.push_front(elem);
	elem=static_cast<Celem<int> *>(lista.pop_back());
	assert(1==elem->GetData());
	delete elem;
	elem=static_cast<Celem<int> *>(lista.pop_back());
	assert(2==elem->GetData());
	delete elem;
	elem=static_cast<Celem<int> *>(lista.pop_back());
	assert(10==elem->GetData());
	delete elem;
	assert(0==lista.size());

	std::cout<<"Passed intrusive list"<<std::endl;

	nonintrusive_list<int> *lista1;
	lista1=new nonintrusive_list<int>();
	lista1->push_front(1);
	lista1->push_front(2);
	lista1->push_front(10);
	assert(1==lista1->pop_back());
	assert(2==lista1->pop_back());
	assert(10==lista1->pop_back());
	assert(0==lista1->size());
	lista1->push_front(1);
	delete lista1;
	std::cout<<"Passed nonintrusive list"<<std::endl;

	intrusive_dlist dlista;
	CDelem<int> *delem;
	delem=new CDelem<int>(1);
	dlista.push_front(delem);
	delem=new CDelem<int>(2);
	dlista.push_front(delem);
	delem=new CDelem<int>(10);
	dlista.push_front(delem);
	delem=static_cast<CDelem<int> *>(dlista.pop_back());
	assert(1==delem->GetData());
	delete delem;
	delem=static_cast<CDelem<int> *>(dlista.pop_back());
	assert(2==delem->GetData());
	delete delem;
	delem=static_cast<CDelem<int> *>(dlista.pop_back());
	assert(10==delem->GetData());
	delete delem;
	assert(0==dlista.size());
	std::cout<<"Passed intrusive dlist"<<std::endl;

	nonintrusive_dlist<int> *dlista1;
	dlista1=new nonintrusive_dlist<int>();
	dlista1->push_front(1);
	dlista1->push_front(2);
	dlista1->push_front(10);
	assert(1==dlista1->pop_back());
	assert(2==dlista1->pop_back());
	assert(10==dlista1->pop_back());
	assert(0==dlista1->size());
	dlista1->push_front(1);
	delete dlista1;
	std::cout<<"Passed nonintrusive dlist"<<std::endl;
	return 0;
}