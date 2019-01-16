// data_structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Clinked_list.h"
#include "Cdoublelinked_list.h"
#include <iostream>
#include "btree.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Clinked_list *list;
	list=new Clinked_list();
	list->add_list_first(10);
	list->add_list_first(20);
	list->add_list_first(5);
	list->print();
	cout<<list->find(10)<<"\n";
	cout<<list->find(3)<<"\n";
	list->clean();
	cout<<"cleaning the list\n"<<flush;
	cout<<"simple linked list\n"<<flush;
	list->add_list(10);
	list->add_list(20);
	list->add_list(5);
	list->add_list(15);
	list->print();
	delete list;
	cout<<"double linked list\n"<<flush;
	Cdoublelinked_list *dlist;
	dlist=new Cdoublelinked_list();
	dlist->add(10);
	dlist->add(20);
	dlist->add(5);
	dlist->add(15);
	dlist->print();
	delete dlist;
	cout<<"start binary tree"<<endl<<flush;
	btree _btree;
	_btree.insert(50);
	_btree.insert(14);
	_btree.insert(67);
	_btree.insert(9);
	_btree.insert(19);
	_btree.insert(54);
	_btree.insert(72);
	_btree.insert(7);
	_btree.insert(12);
	_btree.insert(17);
	_btree.insert(23);
	_btree.insert(76);
	_btree.LRR();
/* this doesn 't work for my case because it will modify the structure of the tree

	cout<<_btree.setFirstSortOrderMoris()<<"*-*";
	for(int i=0;i<11;++i)
		cout<<_btree.getNextSortOrderMoris()<<"*-*";
	cout<<endl;
*/
//	_btree.LRR_stack();
	_btree.setFirstLRR();
	for(int i=0;i<13;++i)
		cout<<_btree.LRR_stack_next()<<"*-*";
	cout<<endl;
	cout<<"end binary tree"<<endl<<flush;
	return 0;
}

