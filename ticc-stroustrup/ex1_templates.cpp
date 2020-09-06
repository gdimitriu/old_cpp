// ex1_templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
template<class T> class List
{
	struct Link
	{
		Link* pre;
		Link* suc;
		T val;
		Link(Link* p=0,Link* s=0,const T& v=0) : pre(p),suc(s),val(v)
		{
			if(p)
			{
				p->suc=this;
			}
		}
		Link()
		{
			pre=NULL;
			suc=NULL;
			val=0;
		}
	};
	Link* head;
	Link* last;
public:
	List() : head(),last() {}
	List(const T&t) : head(new Link(0,0,t)) {last=head;}
	void add(T& elem)
	{
		if(head==NULL)
		{
			head=new Link(0,0,elem);
			last=head;
			return;
		}
		if(last)
		{
			last=new Link(last,0,elem);
		}
	}
	void print_all() { for(Link* p=head;p;p=p->suc) std::cout<<p->val<<std::endl;};
};
class Rec
{
private:
	int value;
public:
	Rec(int val) : value(val){}
	friend std::ostream& operator<<(std::ostream& out,const class Rec &rec);
};
std::ostream& operator<<(std::ostream& out,const class Rec &rec)
{
	out<<rec.value;
	return out;
}
void f(List<int>& li,List<Rec>& lr)
{
	li.print_all();
	lr.print_all();
}

int _tmain(int argc, _TCHAR* argv[])
{
	List<int> my_list;
	List<Rec> my_rec_list;
	for(int i=0;i<6;++i)
		my_list.add(i);
	my_list.print_all();
	return 0;
}

