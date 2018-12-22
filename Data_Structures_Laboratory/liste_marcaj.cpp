/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is liste_marcaj.cpp lucrul cu liste alocate dinamic cu componenta marcaj.

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
struct nod
{
	int info;
	struct nod *next;
};
void creare_lc(struct nod *head,int val)
//functia de creare a unei liste circulare cu nod marcaj
{
	struct nod *aux;
	aux=new (struct nod);
	aux->info=val;
	aux->next=head;
	struct nod *parc;
	parc=head;
	if(parc->next==head) //lista este goala
		head->next=aux;
	else
	{
		while(parc->next!=head) parc=parc->next;
		parc->next=aux;
	}
}
void tiparire(struct nod *head)
{
	struct nod *parc;
	parc=head->next;
	while(parc!=head)
	{
		cout<<"Elementul este "<<parc->info<<endl;
		parc=parc->next;
	}
}
int search_lc(struct nod *head,int val)
//returneaza pozitia pe care se afla valoarea val
{
	struct nod *parc;
	int count;
	count=0;
	parc=head->next;
	while(parc!=head && parc->info!=val)
	{
		parc=parc->next;
		count++;
	}
	if(parc!=head) count++;
	return count;
}
int main(int argc, char* argv[])
{
	struct nod *head;
	int nr,val;
	head=new (struct nod);
	head->info=0;
	head->next=head;
	cout<<"Introuceti cite numere aveti nr=";cin>>nr;
	for(int i=0;i<nr;i++)
	{
		cin>>val;
		creare_lc(head,val);
	}
	tiparire(head);
	cout<<"Care este elementul pe care il cautati val=";cin>>val;
	nr=search_lc(head,val);
	if(nr!=0)	cout<<"Elementul cautat este pe pozitia "<<nr<<endl;
	else cout<<"Elementul "<<val<<" nu se afla in lista\n";
	return 0;
}
