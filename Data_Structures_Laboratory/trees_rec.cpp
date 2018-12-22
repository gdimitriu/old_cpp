/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is trees.cpp Fisier pentru lucrul cu arbori binari recursivi
	ordonati (versiune proprie).

    Data Structures Laboratory is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Data Structures Laboratory is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Data Structures Laboratory; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/

#include<iostream.h>
#include<stdlib.h>

struct nod
{
	double info;
	struct nod *sons[2];
};

struct nod* insert(struct nod *top,struct nod *ins)
{
	if(top==NULL) return ins;
	int val=(top->info<ins->info);
	if(top->sons[val]!=NULL) insert(top->sons[val],ins);
	else top->sons[val]=ins;
	return top;
}
void RLR(struct nod *top) //RLR Root Left Right
{
	if(top!=NULL)
	{
		cout<<top->info<<" ";
		cout.flush();
		RLR(top->sons[0]);
		RLR(top->sons[1]);
	}
}
void LRR(struct nod *top) //LRR Left Root Right
{
	if(top!=NULL)
	{
		LRR(top->sons[0]);
		cout<<top->info<<" ";
		cout.flush();
		LRR(top->sons[1]);
	}
}
void RRL(struct nod *top) //RRL Right Root Left
{
	if(top!=NULL)
	{
		RRL(top->sons[1]);
		cout<<top->info<<" ";
		cout.flush();
		RRL(top->sons[0]);
	}
}
void LRR1(struct nod *top) //LRR1 Left Right Root
{
	if(top!=NULL)
	{
		LRR1(top->sons[0]);
		LRR1(top->sons[1]);
		cout<<top->info<<" ";
		cout.flush();
	}
}
struct nod *deletet(struct nod *top)
{
	if(top!=NULL)
	{
		top->sons[0]=deletet(top->sons[0]);
		top->sons[1]=deletet(top->sons[1]);
		delete top;
	}
	return NULL;
}
int main(int argc, char* argv[])
{
	struct nod *top;
	int nr;
	double info;
	double sup,inf;
	cout<<"Input the nodes of the tree\n";
	cout<<"Input the numbers of nodes ";
	cin>>nr;
	cout<<"Input the sup and inf \n";
	cin>>inf; cin>>sup;
	top=NULL;
	for(int i=0;i<nr;i++)
	{
//		cin>>info;
		struct nod *aux;
		aux=new struct nod;
//		aux->info=info;
		aux->info=inf+(sup-inf)*rand()/(double)RAND_MAX;
		aux->sons[0]=NULL;
		aux->sons[1]=NULL;
		top=insert(top,aux);
	}
	cout<<"\n LRR Left Root Right\n";
	LRR(top);
	cout<<"\n RRL Right Root Left\n";
	RRL(top);
	cout<<"\n RLR Root Left Right\n";
	RLR(top);
	cout<<"\n LRR1 Left Right Root\n";
	LRR1(top);
	cout<<endl;
	top=deletet(top);
	LRR(top);
	return 0;
}
