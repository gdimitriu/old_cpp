/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is liste_ordonate_dinamic.cpp Lucrul cu liste ordonate dinamic.

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
void inserare_lo(struct nod **head,int val)
//se presupune ca lista este initial ordonata crescator
{
	struct nod *parc;
	struct nod *aux,*p1;
	p1=NULL;
	parc=*head;
	aux=new (struct nod);
	aux->info=val;
	if((*head)->info>val)
	{
		aux->next=*head;
		*head=aux;
		return;
	}
	while(parc!=NULL && (parc->next->info<=val))
	{
		p1=parc;
		parc=parc->next;
	}
	if(p1!=NULL)
	{
		aux->next=p1->next;
		p1->next=aux;
	}
	else
	{
		aux->next=(*head)->next;
		(*head)->next=aux;
	}
}
//creaza o lista simplu inlantuita din intregii introdusi de la tastatura
struct nod *creare(void) 
{
	struct nod *aux;
	int nr;
	cout<<"Dati nr ";cin>>nr; //se termina cu zero
	if(nr!=0)
	{
		aux=new (struct nod);
		aux->info=nr;
		aux->next=creare();
		return aux;
	}
	else return NULL;
}
void tiparire(struct nod *head)
//tipareste toata lista simplu inlantuita
{
	struct nod *aux;
	aux=head;
	while(aux!=NULL)
	{
		cout<<"Nr introdus a fost "<<aux->info<<endl;
		aux=aux->next;
	}
}
void stergerelista(struct nod **head)
//functia care sterge lista delocind memoria
{
	struct nod *aux,*parc;
	parc=*head;
	while(parc!=NULL)
	{
		aux=parc;
		parc=parc->next;
		delete aux;
	}
	*head=NULL;
}
int main(int argc, char* argv[])
{	struct nod *base;
	int val;
	base=NULL;
	base=creare();
	tiparire(base);
	cout<<"Ce valoarea vreti sa introduceti\n";
	cin>>val;
	inserare_lo(&base,val);
	tiparire(base);
	stergerelista(&base);
	return 0;
}
