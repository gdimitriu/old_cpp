/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is liste_dinamic.cpp Lucrul cu liste alocate dinamic.

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
//liste determinate de doi pointer (head si tail)
void adaugare(struct nod **head,struct nod **tail,int val)
{
	struct nod *aux;
	aux=new (struct nod);
	aux->info=val;
	aux->next=NULL;
	if(*head==NULL) *head=*tail=aux;
	else
	{
		(*tail)->next=aux;
		*tail=aux;
	}
}
void ainsert(struct nod **base,struct nod **tail,int val,int info)
//insereaza dupa nodul cu valoarea val un alt nod cu valoarea info
{
	struct nod *aux,*parc;
	aux=new (struct nod);
	aux->info=info;
	if(val==(*tail)->info) //daca elementul cautat este ultimul
	{
		(*tail)->next=aux;
		*tail=aux;
		aux->next=NULL;
	}
	else
	{
		parc=*base;
		while(parc->info!=val)
		{
			if(parc->next==NULL) break; //daca nu am gasit valoarea vom insera la sfirsit
			parc=parc->next;
		}
		if(parc->next==NULL)
		{
			(*tail)->next=aux;
			*tail=aux;
			aux->next=NULL;
		}
		else
		{
			aux->next=parc->next;
			parc->next=aux;
		}
	}
}
void binsert(struct nod **head,struct nod **tail,int val,int info)
//insereaza inaintea nodului cu valoarea val un alt nod cu valoarea info
{
	struct nod *aux,*parc;
	bool flag;
	aux=new (struct nod);
	aux->info=info;
	if((*head)->info==val) //se face insertia la head
	{
		aux->next=*head;
		*head=aux;
	}
	else
	{
		parc=*head;
		flag=false;
		while(parc->next->info!=val)
		{
			if(parc->next->next==NULL)
			{
				flag=true;
				break; //nu am gasit elementul cerut deci vom face insertia la head
			}
			parc=parc->next;
		}
		if(flag==true)
		{
			aux->next=*head;
			*head=aux;
		}
		else
		{
			aux->next=parc->next;
			parc->next=aux;
		}
	}
}
void stergere(struct nod **head,struct nod **tail,int val)
//setergerea unui element cu o valoarea data,
//daca valoarea este gasita in mai multe locuri ea este stearsa
{
	struct nod *aux,*parc;
	if((*head)->info==val)
	{
		aux=*head;
		*head=aux->next;
		delete aux;
	}
	parc=*head;
	while(parc->next!=NULL)
	{
		if(parc->next->info==val)
		{
			aux=parc->next;
			parc->next=aux->next;
			if(parc->next==NULL) *tail=parc;
			delete aux;
		}
		parc=parc->next;
		if(parc->next==NULL)
		{
			if(parc->info==val)
			{
				aux=parc->next;
				parc->next=aux->next;
				*tail=parc;
				delete aux;
			}
		}
	}
}
void stergerelista(struct nod **head,struct nod **tail)
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
	*head=*tail=NULL;
}
int numarare(struct nod *head)
//numara numarul de elemente ale listei
{
	struct nod *aux;
	int nr;
	nr=0;
	aux=head;
	while(aux!=NULL)
	{
		nr++;
		aux=aux->next;
	}
}
int main(int argc, char* argv[])
{
	struct nod *base,*tail;
	int nr,i,val;
	base=tail=NULL;
//	base=creare();
	cout<<"Cite numere aveti?\n";
	cin>>nr;
	for(i=0;i<nr;i++)
	{
		cin>>val;
		adaugare(&base,&tail,val);
	}
	tiparire(base);
	cout<<"dupa care element doriti sa inserati ";cin>>nr;
	cout<<"valoarea ";cin>>val;
	ainsert(&base,&tail,nr,val);
	tiparire(base);
	cout<<"inainta carui element doriti sa inserati ";cin>>nr;
	cout<<"valoarea ";cin>>val;
	binsert(&base,&tail,nr,val);
	tiparire(base);
	cout<<"Ce valoare doriti sa stergeti?";cin>>val;
	stergere(&base,&tail,val);
	tiparire(base);
	nr=numarare(base);
	cout<<"Lista are "<<nr<<" elemente\n";
	stergerelista();
	return 0;
}
