/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is vectori_liste_rare.cpp Oratii asupra a doi vectori rari 
	sub forma de liste dinamice.

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
	int val;
	int pos;
	struct nod *next;
};
struct nod *adunare(struct nod *heada,struct nod *headb)
{
	struct nod *parca,*parcb,*prez,*aux,*headrez;
	parca=heada;
	parcb=headb;
	headrez=NULL;
	prez=NULL;
	if(parca==NULL && parcb==NULL) return NULL;
	while(parca!=NULL || parcb!=NULL) //cit timp avem o lista nevida
	{
		if(parca!=NULL && parcb!=NULL) //daca ambele liste sunt nevide
		{
			if(parca->pos==parcb->pos) //daca avem doua elemente nenule pe acceasi pozitie
			{
				aux=new (struct nod);
				aux->next=NULL;
				aux->pos=parca->pos;
				aux->val=parca->val+parcb->val;
				if(prez!=NULL) prez->next=aux;
				else headrez=aux;
				parca=parca->next;
				parcb=parcb->next;
				prez=aux;
			}
			else if(parca->pos<parcb->pos)
			//daca pozitia din a < pozitia din b atunci punem elementul din a
			{
				aux=new (struct nod);
				aux->next=NULL;
				aux->pos=parca->pos;
				aux->val=parca->val;
				if(prez!=NULL) prez->next=aux;
				else headrez=aux;
				parca=parca->next;
				prez=aux;
			}
			else if(parcb->pos>parcb->pos)
			//daca pozitia din b < pozitia din a atunci punem elementul din b
			{
				aux=new (struct nod);
				aux->next=NULL;
				aux->pos=parcb->pos;
				aux->val=parcb->val;
				if(prez!=NULL) prez->next=aux;
				else headrez=aux;
				parcb=parcb->next;
				prez=aux;
			}
		}
		else
		{
			if(parca==NULL)
			//daca lista a este vida copiem intraga lista b ramasa
				while(parcb!=NULL)
				{
					aux=new (struct nod);
					aux->next=NULL;
					aux->pos=parcb->pos;
					aux->val=parcb->val;
					if(prez!=NULL) prez->next=aux;
					else headrez=aux;
					parcb=parcb->next;
					prez=aux;
				}
			if(parcb==NULL)
			//daca lista b este vida copiem intraga lista a ramasa
				while(parca!=NULL)
				{
					aux=new (struct nod);
					aux->next=NULL;
					aux->pos=parca->pos;
					aux->val=parca->val;
					if(prez!=NULL) prez->next=aux;
					else headrez=aux;
					parca=parca->next;
					prez=aux;
				}
		}
	}
	return headrez;
}

struct nod *dotprod(struct nod *heada,struct nod *headb)
{
	struct nod *parca,*parcb,*prez,*aux,*headrez;
	parca=heada;
	parcb=headb;
	headrez=NULL;
	if(parca==NULL && parcb==NULL) return NULL;
	while(parca!=NULL && parcb!=NULL) //cit timp avem ambele liste nevide
	{
		if(parca->pos==parcb->pos) //daca avem doua elemente nenule pe acceasi pozitie
		{
			aux=new (struct nod);
			aux->next=NULL;
			aux->pos=parca->pos;
			aux->val=parca->val*parcb->val;
			if(headrez!=NULL) prez->next=aux;
			else headrez=aux;
			parca=parca->next;
			parcb=parcb->next;
			prez=aux;
		}
		else
		{
			if(parca->pos<parcb->pos) parca=parca->next;
			else parcb=parcb->next;
		}
	}
	return headrez;
}
int inmultire(struct nod *heada,struct nod *headb)
{
	struct nod *parca,*parcb;
	int rez;
	parca=heada;
	parcb=headb;
	rez=0;
	if(parca==NULL && parcb==NULL) return NULL;
	while(parca!=NULL && parcb!=NULL) //cit timp avem ambele liste nevide
	{
		if(parca->pos==parcb->pos) //daca avem doua elemente nenule pe acceasi pozitie
		{
			rez=rez+parca->val*parcb->val;
			parca=parca->next;
			parcb=parcb->next;
		}
		else
		{
			if(parca->pos<parcb->pos) parca=parca->next;
			else parcb=parcb->next;
		}
	}
	return rez;
}

struct nod *creare(void)
{
	struct nod *aux,*head,*parc;
	int nr,val,i;
	head=NULL;
	parc=NULL;
	cout<<"Cite elemente are vectorul\n";cin>>nr;
	for(i=0;i<nr;i++)
	{
		cin>>val;
		if(val!=0)
		{
			aux=new (struct nod);
			aux->val=val;
			aux->next=NULL;
			aux->pos=i;
			if(parc==NULL) head=parc=aux;
			else
			{
				parc->next=aux;
				parc=aux;
			}
		}
	}
	return head;
}
void printare(struct nod *head)
{
	struct nod *parc;
	int pos=0;
	parc=head;
	while(parc!=NULL)
	{
		if(pos<parc->pos) //daca nu exista element pe respectiva pozitie el trebuie sa fi fost zero
		{
			cout<<"0 ";
			pos++;
		}
		else
		{
			cout<<parc->val<<" ";
			parc=parc->next;
			pos++;
		}
	}
}
int main(int argc, char* argv[])
{
	struct nod *a,*b,*c,*d;
	int prod;
	a=creare();
	b=creare();
	c=adunare(a,b);
	cout<<"Adunarea celor doi vectori are rezultatul\n";
	printare(c);
	d=dotprod(a,b);
	cout<<"\nProdusul elementelor celor doi vectori are rezultatul\n";
	printare(d);
	prod=inmultire(a,b);
	cout<<"\nInmultirea celor doi vectori are rezultatul "<<prod<<endl;
	return 0;
}
