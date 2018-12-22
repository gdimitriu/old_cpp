/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is arbori_cautare.cpp fisier pentru arbori de cautare cu si fara marcaj.

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
	int info,contor;
	struct nod *left,*right;
};
struct nod *nmarcaj;
//cautare cu insertie normala recursiva
void cautare_ins(int val,struct nod **root)
{
	if((*root)==NULL) //val nu a fost gasita si trebuie inserata
	{
		struct nod *temp;
		temp=new (struct nod);
		*root=temp;
		(*root)->info=val;
		(*root)->contor=1;
		(*root)->left=NULL;
		(*root)->right=NULL;
	}
	else
	{
		if((*root)->info<val) cautare_ins(val,&((*root)->right));
		else if((*root)->info>val) cautare_ins(val,&((*root)->left));
		else //val a fost gasita
			(*root)->contor++;
	}
}
//cautare cu insertie cu marcaj recursiva
void cautare_ins_marcaj(int val,struct nod **root)
{
	if((*root)==nmarcaj)
	{
		struct nod *temp;
		temp=new (struct nod);
		*root=temp;
		(*root)->info=val;
		(*root)->contor=1;
		(*root)->left=nmarcaj;
		(*root)->right=nmarcaj;
		return;
	}
	if(val<(*root)->info) cautare_ins_marcaj(val,&((*root)->left));
	else if(val>(*root)->info) cautare_ins_marcaj(val,&((*root)->right));
	else //nu am ajuns la nodul marcaj deci am gasit valoarea chiar intr-unul din nodurile arborelui
		(*root)->contor++;
}
			
void LRR(struct nod *top) //RLR Root Left Right pentru normal recursiva
{
	if(top!=NULL)
	{
		LRR(top->left);
		cout<<top->info<<" de "<<top->contor<<" ori\n";
		cout.flush();
		LRR(top->right);
	}
}

void LRR_marcaj(struct nod *top) //RLR Root Left Right pentru marcaj recursiva
{
	if(top!=nmarcaj)
	{
		LRR_marcaj(top->left);
		cout<<top->info<<" de "<<top->contor<<" ori\n";
		cout.flush();
		LRR_marcaj(top->right);
	}
}
//aflarea minimului dintr-un arbore normal
struct nod *min(struct nod *top)
{
	struct nod *parc;
	parc=top;
	while(parc->left!=NULL)
		parc=parc->left;
	return parc;
}
//aflarea maximului dintr-un arbore normal
struct nod *max(struct nod *top)
{
	struct nod *parc;
	parc=top;
	while(parc->right!=NULL)
		parc=parc->right;
	return parc;
}
//functia de stergere recursiva a unui nod partea interioara
void sterge_rec1(struct nod **aux,struct nod **aux1)
//aux este valoarea anterioara
//aux1 este valoarea curenta
//aux este pe stiva functiei apelante
{
	if((*aux1)->right!=NULL) sterge_rec1(aux1,&((*aux1)->right));
	else
	{
		(*aux)->info=(*aux1)->info;
		(*aux)->contor=(*aux1)->contor;
		*aux=*aux1;
		if((*aux1)->left!=NULL)	*aux1=(*aux1)->left;
		else delete *aux1;
	}
}
//functia de stergere recursiva a unui nod partea principala
void sterge_rec(int val,struct nod **parc)
{
	struct nod *aux; //!! aceasta ramine pe stiva fiecarui apel dar este vazuta si modificata de sterge_rec1
	if((*parc)==NULL) cout<<"Nu am gasit valoarea";
	else if(val<(*parc)->info) sterge_rec(val,&((*parc)->left));
	else if(val>(*parc)->info) sterge_rec(val,&((*parc)->right));
	else //pot sterge nodul parc
	{
		aux=*parc;
		if(aux->right==NULL) *parc=aux->left;
		else if(aux->left==NULL) *parc=aux->right;
		else sterge_rec1(&aux,&(aux->left));
	}
}
//functia de stergere iterativa a unui nod cind avem un singur fiu
void sterge_iter1(struct nod **parc)
{
	struct nod *aux;
	aux=*parc;
	if((*parc)->left==NULL) *parc=(*parc)->right;
	else *parc=(*parc)->left;
	delete aux;
}
//functia de stergere iterativa a unui nod cind avem 2 fii
void sterge_iter2(struct nod **parc,int *d)
/*
	se parcurge arborele in ordine pina cind se gaseste predecesorul lui parc->info
	deci pina cind se gaseste nodul cu cea mai mica inf mai mare ca parc->info
	d=-1 daca mergem la stinga si d=1 daca mergem la dreapta.
*/
{
	struct nod *aux1,*aux2;
	aux1=*parc;
	aux2=(*parc)->left;
	*d=-1;
	while(aux2->right!=NULL)
	{
		aux1=aux2;
		aux2=aux2->right;
		*d=1;
	}
	(*parc)->info=aux2->info;
	(*parc)->contor=aux2->contor;
	if(*d==-1) aux1->left=aux2->left;
	else aux1->right=aux2->right;
	delete aux2;
}
//functia de stergere iterativa a unui nod partea principala
void sterge_iter(int val,struct nod **root)
//d=-1 daca mergem la stinga si d=1 daca mergem la dreapta.
{
	struct nod *aux,*parc1,*parc2;
	int d;
	bool found;
	aux=new (struct nod); //nod auxiliar de marcaj
	aux->right=*root;
	parc2=aux;
	parc1=*root;
	d=1;
	found=false;
	while(parc1!=NULL && found==false) //cauta elementul de sters
	{
		if(val<parc1->info)
		{
			parc2=parc1;
			parc1=parc1->left;
			d=-1;
		}
		else if(val>parc1->info)
		{
			parc2=parc1;
			parc1=parc1->right;
			d=1;
		}
		else found=true;
	}
	if(!found) cout<<"Nu am gasit valoarea\n";
	else //trebuie sa stergem valoarea
	{
		if(parc1->left==NULL)
		{
			sterge_iter1(&parc1);
			//reactualizez pointerii de la nodul parinte
			if(d==1) parc2->right=parc1;
			else parc2->left=parc1;
		}
		else if(parc1->right==NULL)
		{
			sterge_iter1(&parc1);
			//reactualizez pointerii de la nodul parinte
			if(d==-1) parc2->left=parc1;
			else parc2->right=parc1;
		}
		else sterge_iter2(&parc1,&d);
	}
	delete aux; //sterg nodul auxialiar de marcaj
}

int main(int argc, char* argv[])
{
	int nr,val,i;
	cout<<"Cite date aveti de introdus nr=";cin>>nr;
	struct nod *root1,*root2,*minval,*maxval;
	root1=NULL;
	nmarcaj=new (struct nod);
	nmarcaj->left=NULL;
	nmarcaj->right=NULL;
	root2=nmarcaj;
	for(i=0;i<nr;i++)
	{
		cin>>val;
		cautare_ins(val,&root1);
		cautare_ins_marcaj(val,&root2);
	}
	cout<<"Arborele fara marcaj\n";
	LRR(root1);
	cout<<"Arborele cu marcaj\n";
	LRR_marcaj(root2);
	minval=min(root1);
	cout<<"Minumul este "<<minval->info<<" si exista de "<<minval->contor<<" ori\n";
	maxval=max(root1);
	cout<<"Maximul este "<<maxval->info<<" si exista de "<<maxval->contor<<" ori\n";
	cout<<"Dati valoarea de sters\n";cin>>val;
//	sterge_rec(val,&root1);
	sterge_iter(val,&root1);
	cout<<"Dupa stergere\n";
	LRR(root1);
	return 0;
}
