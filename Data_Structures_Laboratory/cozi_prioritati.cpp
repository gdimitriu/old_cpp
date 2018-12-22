/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is cozi_prioritati.cpp. Fisier pentru crearea si eliminarea unui element dintr-o coada cu prioritati

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
	int prioritate;
	struct nod * next;
	float info;
};
struct nod * head, *tail, *parc,*p1,*aux;
void adaug(float x,int p)
{
	if(head==NULL) //daca coada este goala
	{
		head=new struct nod;
		head->info=x;
		head->prioritate=p;
		head->next=NULL;
		tail=head;
		return;
	}
	aux=new struct nod;
	aux->info=x;
	aux->prioritate=p;
	if(tail->prioritate==p) //daca ultimul element din coada are prioritatea necesara
	{
		aux->next=NULL;
		tail->next=aux;
		tail=aux;
		return;
	}
	//parcurg lista pina cind gasesc un element >= cu prioritatea necesara sau termin lista
	parc=head;
	while((parc->next!=NULL) && (parc->prioritate<p)) parc=parc->next;
	if(parc->next==NULL) //daca nu am gasit nici un element cu prioritatea >= cu cea ceruta
	{
		aux->next=NULL; //fac insertia la sfirsit
		tail->next=aux;
		tail=aux;
	}
	else //daca am gasit un element cu prioritatea >= prioritatea ceruta
	{
		if(parc->next->prioritate>p) //daca prioritatea ceruta nu exista
		{
			aux->next=parc->next;
			parc->next=aux;
		}
		else
		{
			//caut sfirsitul cozii de prioritate ceruta
			p1=parc->next;
			while(p1->next->prioritate==p) p1=p1->next;
			aux->next=p1->next;
			p1->next=aux;
		}
	}
}

void stergere(int p,float x)
{
	if(head==NULL)
	{
		cout<<"Underflow\n";
	}
	else if((head==tail) &&(head->prioritate==p) && (head->info==x))
	{//daca am un singur element si el este cel cautat
		delete head;
		head=tail=NULL;
	}
	else if(head==tail) cout<<"Nod neconvenabil\n"; //daca am un singur element si el nu este cel cautat
	else
	{
		if(tail->prioritate<p) cout<<"Nu exista\n"; //daca elementul din coada are prioritatea mai mica decit cea ceruta
		else
		{
			//parcurg lista pina cind gasesc un element cu prioritatea ceruta sau se termina lista
			parc=head;
			while((parc->next!=NULL)&& (parc->prioritate!=p)) parc=parc->next;
			if(parc->next==NULL) cout<<"Nu exista\n"; //daca s-a terminat lista nu avem element
			else
			{
				//parcurg lista de prioritate ceruta pina cind gasesc elementul cerut s-au se termina
				while((parc->next->info!=x) && (parc->next->prioritate==p)) parc=parc->next;
				if(parc->next->prioritate!=p) cout<<"Nu exista\n"; //nu exista elementul
				else
				{
					//refac legaturile
					aux=parc->next;
					if(parc->next!=tail) parc->next=aux->next;
					else
					{
						parc=parc->next;
						tail=parc;
					}
					delete aux;
				}
			}
		}
	}
}
void parcurgere(void)
{
	parc=head;
	while(parc!=NULL)
	{
		cout<<"elementul cu val x="<<parc->info<<" are prioritatea p="<<parc->prioritate<<endl;
		parc=parc->next;
	}
}
int main(int argc, char* argv[])
{
	float x;
	int i,n,prioritate;
	head=tail=NULL;
	cout<<"Cite elemente aveti\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Dati elementul ";
		cin>>x;
		cout<<"Dati prioritatea elementului ";
		cin>>prioritate;
		adaug(x,prioritate);
	}
	cout<<"Dupa introducerea datelor lista este\n";
	parcurgere();
	cout<<"Dati elementul de sters x=";
	cin>>x;
	cout<<"Cu ce prioritate p=";
	cin>>prioritate;
	stergere(prioritate,x);
	cout<<"Dupa stergere lista este\n";
	parcurgere();
	return 0;
}
