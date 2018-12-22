/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is arbori_echilibrati.cpp Fisier pentru crearea, stergerrea si parcurgerea AVL.

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
	int bal;
	int contor;
	struct nod *left,*right;
};
void LRR(struct nod *top) //RLR Root Left Right pentru normal recursiva
{
	if(top!=NULL)
	{
		LRR(top->left);
		cout<<top->info<<" de "<<top->contor<<" ori si are bal="<<top->bal<<endl;
		cout.flush();
		LRR(top->right);
	}
}
void arbore(struct nod *top) //afisare leg arbori
{
	if(top!=NULL)
	{
		arbore(top->left);
		cout<<top->info<<" de "<<top->contor<<" ori si are bal="<<top->bal;
		if(top->left!=NULL)
			cout<<" si fiul "<<(top->left)->info;
		if(top->right!=NULL) 
			cout<<" si fiul "<<(top->right)->info;
		cout<<endl;
		cout.flush();
		arbore(top->right);
	}
}
void search_avl(int x,bool *h,struct nod **p)
{
	struct nod *q,*r;
	if (*p==NULL) //inseram primul nod
	{
		*p=new struct nod;
		(*p)->info=x;
		(*p)->bal=0;
		(*p)->left=NULL;
		(*p)->right=NULL;
		(*p)->contor=1;
		*h=true;
		return;
	}
	if(x<(*p)->info) //insertie si reechilibrare in arborele sting
	{
		search_avl(x,h,&((*p)->left));
		if(*h==true) //adincimea arborelui s-a modificat
		{
			switch((*p)->bal)
			{
			case 0: //inaltimea subarborelui sting a crescut cu o unitate
				{
					(*p)->bal=-1;
					break;
				}
			case 1: //acum cei doi arbori au adincimi egale
				{
					(*p)->bal=0;
					*h=false; //nu exista modificari
					break;
				}
			case -1: //acum incepem reechilibrarea
				{
					q=(*p)->left; //adresa nodului B descendent sting al lui A
					if(q->bal==-1) //trebuie rotatie SS
					{
						cout<<"Facem rotatie SS\n";
						(*p)->left=q->right;
						q->right=*p;
						(*p)->bal=0;
						q->bal=0;
						*p=q;
					}
					else //trebuie rotatie SD
					{
						cout<<"Facem rotatie SD\n";
						r=q->right;
						q->right=r->left;
						r->left=q;
						(*p)->left=r->right;
						r->right=*p;
						if(r->bal==-1) //s-a inserat un x pe r->left
						{
							q->bal=0;
							(*p)->bal=1;
						}
						else //s-a inserat un Y pe r->right
						if(r->bal==1)
						{
							q->bal=-1;
							(*p)->bal=0;	
						}
						*p=r;
						(*p)->bal=0;
					}
					//ramura stinga nu a crescut deci nu sunt modificari
					*h=false; 
					break;
				}
			}
		}
		return;
	}
	if(x==(*p)->info) //am gasit valoarea deja in arbore
	{
		(*p)->contor++;
		*h=false;
		return;
	}
	if(x>(*p)->info) //insertie si echilibrare in subarborele drept
	{
		search_avl(x,h,&((*p)->right));
		if(*h==true) //a crescut adincimea ramurii drepte
		{
			switch((*p)->bal)
			{
			case 0: //ramura dreapta este mai lunga
				{
					(*p)->bal=1;
					break;
				}
			case -1: //cele doua ramuri sunt egale
				{
					(*p)->bal=0;
					*h=false;
					break;
				}
			case 1: //este necesare reechilibrarea
				{
					q=(*p)->right; //creem adresa catre B descendent drept al nodului A
					if(q->bal==1) //rotatie DD
					{
						cout<<"Facem rotatie DD\n";
						(*p)->right=q->left;
						q->left=*p;
						(*p)->bal=0;
						q->bal=0;
						*p=q;
					}
					else //rotatie DS
					{
						cout<<"Facem rotatie DS\n";
						r=q->left; //pointer catre C descendent sting al lui B
						q->left=r->right;
						r->right=q;
						(*p)->right=r->left;
						r->left=*p;
						if(r->bal==1) //inserare X
						{
							(*p)->bal=-1;
							q->bal=0;
						}
						else //inserare Y
						{
							q->bal=1;
							(*p)->bal=0;
						}
						*p=r;
						(*p)->bal=0;
					}
					//ramura dreapta nu a crescut deci nu sunt modificari
					*h=false;
					break;
				}
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int nr,val,i;
	bool h;
	cout<<"Cite date aveti de introdus nr=";cin>>nr;
	struct nod *root;
	root=NULL;
	for(i=0;i<nr;i++)
	{
		cin>>val;
		search_avl(val,&h,&root);
	}
	cout<<"Arborele final echilibrat\n";
	arbore(root);
	return 0;
}
