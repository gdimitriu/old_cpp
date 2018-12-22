// Jacobi_collumn.cpp : Defines the entry point for the console application.
//

#include <iostream.h>
#include <math.h>
#include <stdlib.h>
int jacobi_collumn(double **mat,double *va,double *xn,double err,long N)
/*
	returneaza 0 in caz de succes si -1 in caz de insucces.
	mat este matricea A, va este vectorul termenilor liber, xn este solutia
	err este eroarea cu care dorim sa calculam solutia sistemului
	N este dimensiunea sistemului
*/
{
	double *xn_1;
	double *yn,*yn_1;
	double max,sum,q;
	long i,j,crt;
	double count;
	for(i=0;i<N;i++)
	{
		sum=0.0;
		for(j=0;j<N;j++) if(j!=i) sum+=fabs(mat[j][i]);
		if(fabs(mat[i][i])<sum)
		{
			cout<<"Sistemul nu poate fi rezolvat deoarece nu este dominant diagonal pe coloane\n";

			return -1;
		}
	}
	xn_1=new double[N];
	yn=new double[N];
	yn_1=new double[N];
	//calculeaza q
	q=0.0;
	for(i=1;i<N;i++) q+=fabs(mat[i][0]/mat[i][i]);
	for(i=1;i<N;i++)
	{
		sum=0.0;
		for(j=0;j<N;j++) if(i!=j) sum+=fabs(mat[j][i]/mat[j][j]);
		if(q<sum) q=sum;
	}
	max=fabs(mat[0][0]);
	for(i=1;i<N;i++) if(max>fabs(mat[i][i])) max=fabs(mat[i][i]);
	count=q/(max*(1-q));
	for(i=0;i<N;i++) yn[i]=va[i];
	crt=1;
	sum=0.0;
	for(i=0;i<N;i++) sum+=fabs(yn[i]);
	count=count*sum;
	while(fabs(count)>err)
	{
		for(i=0;i<N;i++) yn_1[i]=yn[i];
		for(i=0;i<N;i++)
		{
			yn[i]=va[i];
			for(j=0;j<N;j++) if(i!=j) yn[i]-=mat[i][j]/mat[j][j]*yn_1[j];
			xn[i]=yn[i]/mat[i][i];
		}
		sum=0.0;
		for(i=0;i<N;i++) sum+=fabs(yn[i]-yn_1[i]);
		count=q*sum/(max*(1-q));
		crt++;
	}
	delete []xn_1;
	delete []yn;
	delete []yn_1;
	//print the values
	cout<<"Dupa "<<crt<<" pasi avem solutia"<<endl;
	return 0;
}
int main(int argc, char* argv[])
{
	double **mat, *z,*xn,*va;
	double *temp;
	long i,j,N;
	double sum,err;
	char test;
	cout<<"Input N=";cout.flush();cin>>N;
	cout<<"Input the error, err=";cout.flush();cin>>err;
	/* allocation of memory */
	mat=(double **)calloc(N,sizeof(double *));
	temp=(double *)calloc(N*N,sizeof(double));
	for(i=0;i<N;i++)
	{
		mat[i]=temp;
		temp+=N;
	}
	z=new double[N];
	xn=new double[N];
	va=new double[N];
	cout<<"Doriti random sau manual (r/m)?\n";
	cin>>test;
	do
	switch(test)
	{
	case 'r':
	{
		/* generam matricea ssi implicit sistemul de ecuatii */
		for(i=0;i<N;i++) z[i]=i+1; //generam solutia sistemului
		for(j=0;j<N;j++)
			for(i=0;i<N;i++)
			{
				if(i!=j)
				{
					mat[i][j]=20000*rand()/(double)RAND_MAX;
					if((rand()/(double)RAND_MAX)<0.5) mat[i][j]=-mat[i][j];
				}
			}
		for(i=0;i<N;i++)
		{
			sum=0.0;
			for(j=0;j<N;j++) if(j!=i) sum+=fabs(mat[j][i]);
			//creem elementul diagonal
			mat[i][i]=sum+(20000+sum)*rand()/(double)RAND_MAX+0.00001;
			if((rand()/(double)RAND_MAX)<0.5) mat[i][i]=-mat[i][i];
		}
		//generam termenul liber
		for(i=0;i<N;i++)
		{
			va[i]=0.0;
			for(j=0;j<N;j++) va[i]+=mat[i][j]*z[j];
		}
		//afisam matricea
		cout<<endl;
		cout<<"Doriti sa afisam matricea y/n ?";
		char test1;
		cin>>test1;
		if(test1=='y' || test1=='Y')
		{
			for(i=0;i<N;i++)
			{
				for(j=0;j<N;j++) cout<<mat[i][j]<<" ";
				cout<<"| "<<va[i]<<endl;
			}
			cout<<endl<<endl;
		}
		break;
	}
	case 'm':
	{
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				cin>>mat[i][j];
		cout<<"Input free term vector\n";
		for(i=0;i<N;i++) cin>>va[i];
		break;
	}
	default:
	{
		cout<<"Ati introdus gresit.\n";
		cout<<"Doriti random sau manual (r/m)?\n";
		cin>>test;
	}
	}
	while(test!='r' && test!='m');
	int solutie;
	solutie=jacobi_collumn(mat,va,xn,err,N);
	if(test=='m' && solutie==0)
		for(i=0;i<N;i++)
			cout<<"X["<<i<<"]="<<xn[i]<<endl;
	if(test=='r' && solutie==0)
		for(i=0;i<N;i++) if(fabs(xn[i]-z[i])>err) cout<<"eroare la "<<i<<"trebuia sa fie "<<z[i]<<"is este "<<xn[i];
	/* eliberez memoria */
	free(*mat);
	free(mat);
	delete []z;
	delete []xn;
	delete []va;
	return 0;
}
