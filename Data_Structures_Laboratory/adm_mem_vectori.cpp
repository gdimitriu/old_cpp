/*
	Copyright 2005 Gabriel Dimitriu

	This file is part of Data Structures Laboratory.
	This file is adm_mem_vectori.cpp lucrul cu stive, cozi in alocare statica.

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
#include<stdio.h>
#include<stdlib.h>
#define DIM 18
int stack[DIM];
/*
	Functiile pentru lucrul cu o singura stiva
	push pentru introducerea unui element in stiva
	pop pentru scoaterea unui element din stiva
*/
int push(int *stack,int val,int dim) 
//in dim se da valoarea elementelor utilizabile din stiva
//pe pozitia DIM (stack[DIM]) se afla contorul stivei
//returneaza 0 in caz de reusita si -1 in caz de esec
{
	if(stack[dim]+1>(dim-1)) //verific daca am overflow
	{
		printf("Overflow\n");
		return -1;
	}
	else
	{
		stack[dim]++; //incrementez pozitia top
		stack[stack[dim]]=val; //pun valoarea
		return 0;
	}
}
int pop(int *stack,int dim,int *val) 
//pe pozitia DIM (stack[DIM]) se afla contorul stivei
//in dim se da valoarea elementelor utilizabile din stiva
//returneaza valoarea prin pointerul val care ramine neschimbat in caz de underflow
//returneaza valoarea 0 in caz de reusita si -1 in caz de esec
{
	if(stack[dim]==-1) //verific daca am underflow
	{
		printf("Underflow\n");
		return -1;
	}
	else
	{
		stack[dim]--; //decrementez pozitia top
		*val=stack[stack[dim]+1]; //salvez valoarea
		return 0;
	}
}
/*
	Functii pentru lucrul cu coada circulara
	insert pentru insertia unui element
	extract pentru extragerea unui element
*/
int quelle[DIM];
int insert(int *quelle,int val,int dim)
//pe pozitia DIM se alfa head iar pe pozitia DIM+1 se afla tail
//se da in dim valoarea utila a cozii
//returneaza 0 in caz de reusita si -1 in caz de esec
{
	if(quelle[dim]==quelle[dim+1]) //coada este plina sau goala
	{
		if(quelle[dim]==-1 && quelle[dim+1]==-1) //coada este goala
		{
			quelle[dim+1]=0; //tail
			quelle[dim]=dim-1; //head
			quelle[0]=val;
			return 0;
		}
		else
		{
			printf("Coada este plina\n");
			return -1;
		}
	}
	else
	{
		if(quelle[dim+1]==dim-1) quelle[dim+1]=0; //resetez contorul pentru tail
		else quelle[dim+1]++; //repozitionez contorul
		quelle[quelle[dim+1]]=val; //pun valoarea
		return 0;
	}
}
int extract(int *quelle,int *val,int dim)
//pe pozitia DIM se alfa head iar pe pozitia DIM+1 se afla tail
//se da in dim valoarea utila a cozii
//returneaza 0 in caz de reusita si -1 in caz de esec
//returneaza valoarea din cuada in locatia data de pointerul val
{
	if(quelle[dim]==-1 && quelle[dim+1]==-1)
	{
		printf("Coada este goala\n");
		return -1;
	}
	else
	{
		if(quelle[dim]+1==(quelle[dim+1])) //daca am un singur element in coada
		{
			*val=quelle[quelle[dim]+1];
			quelle[dim]=quelle[dim+1]=-1; //spun ca, coada este goala
		}
		else
		{
			if(quelle[dim]==dim-1) quelle[dim]=0; //resetez contorul pentru head
			else quelle[dim]++; //repozitionez head
			*val=quelle[quelle[dim]]; //scot valoarea
		}
		return 0;
	}
}
/*
	Functiile pentru alocarea a mai multor stive in acelasi vector.
	pushn este introducerea unui element in stiva
	popn este pentru scoaterea unui element din stiva
*/
struct stackss
{
	int stack[DIM];
	int *base;
	int *top;
	int n;
	int dim;
};
int pushn(struct stackss *stacks,int val,int i)
//i este stiva in care fac push
//returneaza 0 in caz de succes si -1 in caz de eroare
{
	bool flag;
	int k,found;
	int test1,test2;
	flag=false;
	if(stacks->top[i]==-1) //stiva i este goala
	{
		//obs: intotdeauna vom putea avea un element in oricare stiva
		stacks->stack[stacks->base[i]]=val;
		stacks->top[i]=stacks->base[i];
		return 0;
	}
	else
	{
		if(i!=stacks->n-1 && i!=stacks->n-2) //pentru toate fara ultimele 2 stive
		{
			if(stacks->base[i+1]-stacks->top[i]>=2) //avem loc sa bagam un element
			{
				stacks->top[i]++;
				stacks->stack[stacks->top[i]]=val;
				return 0;
			}
			else
			{
				printf("Overflow la stiva %d\n",i);
				printf("Incercam deplasarile stivelor ls dreapta\n");
				//vom incerca sa gasim o stiva care are un element liber la dreapta stivei i
				flag=false;
				if(i!=(stacks->n-3))
				{
					for(k=i+1;k<(stacks->n-2);k++) //fara ultimile doua
					{
						//verificam daca stiva k este goala
						test2=stacks->top[k];
						if(test2==-1) test2=stacks->base[k];
						if(stacks->base[k+1]-test2>=2)
						{
							found=k;
							flag=true;
							break;
						}
					}
				}
				//toate stivele la dreapta in afara de ultimile 2 au fost testate si sunt pline sau
				//overflow a survenit la stiva n-3
				if(flag==false) 
				{
					//verificam daca stiva n-2 este goala
					test2=stacks->top[stacks->n-2];
					if(test2==-1) test2=stacks->base[stacks->n-2];
					//verificam daca stiva n-1 este goala
					test1=stacks->top[stacks->n-1];
					if(test1==-1) test1=stacks->base[stacks->n-1];
					if(test1-test2>=2)
					{
						found=stacks->n-2;
						flag=true;
					}
				}
			}	
		}
		else
		{
			if(stacks->top[stacks->n-2]==-1) test2=stacks->base[stacks->n-2];
			else test2=stacks->top[stacks->n-2];
			if(stacks->top[stacks->n-1]==-1) test1=stacks->base[stacks->n-1];
			else test1=stacks->top[stacks->n-1];
			if(test1-test2>=2) //avem loc
			{
				if(i!=stacks->n-2)
				{
					stacks->top[i]--;
					stacks->stack[stacks->top[i]]=val;
					return 0;
				}
				else
				{
					stacks->top[i]++;
					stacks->stack[stacks->top[i]]=val;
					return 0;
				}
			}
			else
			{
				printf("Overflow la stiva %d\n",i);
				//nu avem deplasari la dreapta ci numai la stinga
				flag=false;
			}
		}
	}
	if(flag==true) //avem o stiva la dreapta
	{
		test1=stacks->top[found];
		if(test1==-1) test1=stacks->base[found];
		for(k=test1;k>stacks->top[i];k--) //facem deplasarea la dreapta a datelor
			stacks->stack[k+1]=stacks->stack[k];
		for(k=found;k>i;k--) //facem deplasarea la dreapta a pointerilor
		{
			stacks->base[k]++;
			if(stacks->top[k]!=-1) stacks->top[k]++;
		}
		stacks->top[i]++;
		stacks->stack[stacks->top[i]]=val;
		return 0;
	}
	else //nu am gasit o stiva goala la dreapta
	{
		if(i==0)
		{
			printf("Overflow general la stiva %d\n",i);
			return -1;
		}
		else
		{
			printf("Incercam deplasarile stivelor la stinga deoarece nu am gasit o stiva la dreapta\n");
			//vom incerca sa gasim o stiva care are un element liber la stinga stivei i
			found=-1;
			for(k=i-1;k>=0;k--)
			{
				//verificam daca stiva k este goala
				if(stacks->top[k-1]==-1) test2=stacks->base[k-1];
				else test2=stacks->top[k-1];
				if(stacks->base[k]-test2>=2)
				{
					found=k;
					flag=true;
					break;
				}
			}
			if(flag==true) //facem deplasarile la stinga
			{
				if(i!=(stacks->n-1)) test1=stacks->top[i];
				else test1=stacks->top[i]-1;
				for(k=stacks->base[found];k<=test1;k++)
					stacks->stack[k-1]=stacks->stack[k];
				for(k=found;k<=i;k++) //facem deplasarea la stinga a pointerilor
				{
					if(k!=(stacks->n-1))
					{
						stacks->base[k]--;
						if(stacks->top[k]!=-1) stacks->top[k]--;
					}
				}
				if(i!=(stacks->n-1))	stacks->top[i]++;
				else stacks->top[i]--;
				stacks->stack[stacks->top[i]]=val;
				return 0;
			}
			else
			{
				printf("Overflow general la stiva %d\n",i);
				return -1;
			}
		}
	}
}
int popn(struct stackss *stacks,int *val,int i)
//i este stiva din care fac pop
//returneaza valoarea elementului in locatia data de pointerul val
//returneaza 0 in caz de succes si -1 in caz de eroare
{
	if(stacks->top[i]==stacks->base[i]) //avem un singur element in stiva i
	{
		*val=stacks->stack[stacks->base[i]]; //salvez elementul
		stacks->top[i]=-1; //spun ca stiva i este goala
		return 0;
	}
	if(i==stacks->n-1) //pentru ultima stiva
	{
		*val=stacks->stack[stacks->top[i]];
		stacks->top[i]++;
		return 0;
	}
	if(stacks->top[i]==-1)
	{
		printf("Stiva %d este goala deci underflow\n",i);
		return -1;
	}
	*val=stacks->stack[stacks->top[i]];
	stacks->top[i]--;
	return 0;
}
int main(int argc, char* argv[])
{
	int n,m,i,n1;
	int val,vals;
	struct stackss stacks;
/*	printf("Cite numere aveti\n");
	scanf("%d",&n);
	stack[DIM-1]=-1;
	quelle[DIM-2]=-1;
	quelle[DIM-1]=-1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		push(stack,val,DIM-1);
		insert(quelle,val,DIM-2);
	}
	printf("Elementele in stiva sunt\n");
	m=pop(stack,DIM-1,&val);
	while(m==0)
	{
		printf("%d\n",val);
		m=pop(stack,DIM-1,&val);
	}
	printf("Primele %d elemente din coada sunt\n",n/2);
	for(i=0;i<n/2;i++)
	{
		extract(quelle,&val,DIM-2);
		printf("%d\n",val);
	}
	printf("Cite elemente vreti sa mai introduceti ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		m=insert(quelle,val,DIM-2);
		if(m==-1) break;
	}
	printf("Restul de elemente din coada\n");
	m=extract(quelle,&val,DIM-2);
	while(m==0)
	{
		printf("%d\n",val);
		m=extract(quelle,&val,DIM-2);
	} */
	//pentru stive multiple
	printf("Cite stive aveti n=");
	scanf("%d",&n);
	//fac setarile pentru stive
	stacks.dim=DIM;
	stacks.n=n;
	for(i=0;i<DIM;i++) stacks.stack[i]=0; //initializez elementele cu zero
	//aloc memorie
	stacks.top=(int *)calloc(n,sizeof(int));
	stacks.base=(int *)calloc(n,sizeof(int));
	//setez bazele si virfurile initiale ale tuturor stivelor
	//calculez media dim pe stiva
	m=DIM/n;
	for(i=0;i<n;i++)
	{
		if(i==n-1) stacks.base[i]=DIM-1;
		else stacks.base[i]=i*m;
		stacks.top[i]=-1; //setez ca stiva este goala
	}
	//de aici se introduc datele
	printf("Cite elemente aveti de introdus n1=");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		printf("Dati elementul val=");scanf("%d",&val);
		printf("Dati stiva in care il introduceti vals=");scanf("%d",&vals);
		m=pushn(&stacks,val,vals);
		if(m==-1) break;
	}
	printf("Vectorul de stive are componenta\n");
	for(i=0;i<stacks.dim;i++) printf("%d ",stacks.stack[i]);
	printf("\n");
	printf("Cu bazele\n");
	for(i=0;i<n;i++) printf("%d ",stacks.base[i]);
	printf("\n si cu virfurile\n");
	for(i=0;i<n;i++) printf("%d ",stacks.top[i]);
	//eliberez memoria
	free(stacks.top);
	free(stacks.base);
	return 0;
}
