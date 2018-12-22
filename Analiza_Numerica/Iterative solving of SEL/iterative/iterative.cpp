// Jacobi.cpp : Defines the entry point for the console application.
// Jacobi and Gauss-Siedel Method
// Copyright Gabriel Dimitriu 2005.
//

#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <stdlib.h>
int jacobi_row(double **mat,double *va,double *xn,double err,long N,int type)
/*
	returneaza 0 in caz de succes si -1 in caz de insucces.
	mat este matricea A, va este vectorul termenilor liber, xn este solutia
	err este eroarea cu care dorim sa calculam solutia sistemului
	N este dimensiunea sistemului
	type: 
	0 daca se doreste doar rezultatul
	1 daca se doreste rezultatul si pasii intermediari scosi in fisierul jacobi_row.dat
	2 daca se doreste rezultatul si pasii intermediari scosi in fisierul jacobi_row.dat si pe ecran
*/
{
	double *xn_1;
	double max,sum,q;
	long i,j,crt;
	double count;
	for(i=0;i<N;i++)
	{
		sum=0.0;
		for(j=0;j<N;j++) if(j!=i) sum+=fabs(mat[i][j]);
		if(fabs(mat[i][i])<sum)
		{
			cout<<"Sistemul nu poate fi rezolvat deoarece nu este dominant diagonal pe linii\n";
			return -1;
		}
	}
	xn_1=new double[N];
	ofstream file;
	if(type==1 || type==2) file.open("jacobi_row.dat");
	//calculam q
	q=0.0;
	for(j=1;j<N;j++) q+=fabs(mat[0][j]/mat[0][0]);
	for(i=1;i<N;i++)
	{
		sum=0.0;
		for(j=0;j<N;j++) if(j!=i) sum+=fabs(mat[i][j]/mat[i][i]);
		if(q<sum) q=sum;
	}
	max=fabs(va[0]/mat[0][0]);
	for(i=1;i<N;i++) if(max<fabs(va[i]/mat[i][i])) max=fabs(va[i]/mat[i][i]);
	count=q*max/(1-q);
	for(i=0;i<N;i++) xn[i]=va[i]/mat[i][i];
	cout<<"q="<<q<<endl<<"max="<<max<<endl<<"count="<<fabs(count)<<endl;
	if(type==1 || type==2)
	{
		file<<"q="<<q<<endl;
		file<<"pas=0 err="<<count<<endl;
		if(type==2) cout<<"pas=0 err="<<count<<endl;
		for(i=0;i<N;i++)
		{
			file<<"x["<<i<<"]="<<xn[i]<<endl;
			if(type==2) cout<<"x["<<i<<"]="<<xn[i]<<endl;
		}
	}
	crt=1;
	while(fabs(count)>err)
	{
		for(i=0;i<N;i++) xn_1[i]=xn[i];
		for(i=0;i<N;i++)
		{
			xn[i]=va[i]/mat[i][i];
			for(j=0;j<N;j++) if(i!=j) xn[i]-=mat[i][j]/mat[i][i]*xn_1[j];
		}
		max=fabs(xn[0]-xn_1[0]);
		for(i=1;i<N;i++) if(max<fabs(xn[i]-xn_1[i])) max=fabs(xn[i]-xn_1[i]);
		count=q*max/(1-q);
		if(type==1 || type==2)
		{
			file<<"pas="<<crt<<" err="<<count<<endl;
			if(type==2) cout<<"pas="<<crt<<" err="<<count<<endl;
			for(i=0;i<N;i++)
			{
				file<<"x["<<i<<"]="<<xn[i]<<endl;
				if(type==2) cout<<"x["<<i<<"]="<<xn[i]<<endl;
			}
		}
		crt++;
	}
	if(type==1 || type==2) file.close();
	//Afisez nr pasii
	cout<<"Dupa "<<crt<<" pasi avem solutia"<<endl;
	delete []xn_1;
	return 0;
}
int jacobi_collumn(double **mat,double *va,double *xn,double err,long N,int type)
/*
	returneaza 0 in caz de succes si -1 in caz de insucces.
	mat este matricea A, va este vectorul termenilor liber, xn este solutia
	err este eroarea cu care dorim sa calculam solutia sistemului
	N este dimensiunea sistemului
	type: 
	0 daca se doreste doar rezultatul
	1 daca se doreste rezultatul si pasii intermediari scosi in fisierul jacobi_col.dat
	2 daca se doreste rezultatul si pasii intermediari scosi in fisierul jacobi_col.dat si pe ecran
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
	ofstream file;
	if(type==1 || type==2) file.open("jacobi_col.dat");
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
	sum=0.0;
	for(i=0;i<N;i++) sum+=fabs(yn[i]);
	count=sum*q/(1-q);
	if(type==1 || type==2)
	{
		file<<"q="<<q<<endl;
		file<<"pas=0 err="<<count<<endl;
		if(type==2) cout<<"pas=0 err="<<count<<endl;
		for(i=0;i<N;i++)
		{
			file<<"x["<<i<<"]="<<yn[i]/mat[i][i]<<endl;
			if(type==2) cout<<"x["<<i<<"]="<<yn[i]/mat[i][i]<<endl;
		}
	}
	crt=1;
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
		if(type==1 || type==2)
		{
			file<<"pas="<<crt<<" err="<<count<<endl;
			if(type==2) cout<<"pas="<<crt<<" err="<<count<<endl;
			for(i=0;i<N;i++)
			{
				file<<"x["<<i<<"]="<<xn[i]<<endl;
				if(type==2) cout<<"x["<<i<<"]="<<xn[i]<<endl;
			}
		}
		crt++;
	}
	if(type==1 || type==2) file.close();
	delete []xn_1;
	delete []yn;
	delete []yn_1;
	//afisez numarul de pasi
	cout<<"Dupa "<<crt<<" pasi avem solutia"<<endl;
	return 0;
}
int gauss_siedel(double **mat,double *va,double *xn,double err,long N,int type)
/*
	returneaza 0 in caz de succes si -1 in caz de insucces.
	mat este matricea A, va este vectorul termenilor liber, xn este solutia
	err este eroarea cu care dorim sa calculam solutia sistemului
	N este dimensiunea sistemului
	type: 
	0 daca se doreste doar rezultatul
	1 daca se doreste rezultatul si pasii intermediari scosi in fisierul Gauss_Siedel.dat
	2 daca se doreste rezultatul si pasii intermediari scosi in fisierul Gauss_Siedel.dat si pe ecran
*/
{
	double sum1,sum2,*qi,q,max,count;
	double *xn_1;
	int i,j,crt;
	//verificam daca  conditiile de convergenta sunt indeplinite
	for(i=0;i<N;i++)
	{
		sum1=0.0;
		sum2=0.0;
		for(j=0;j<N;j++)
			if(i!=j) sum1+=fabs(mat[i][j]/mat[i][i]);
		for(j=i+1;j<N;j++)
			sum2+=fabs(mat[i][j]/mat[i][i]);
		if(!(sum1<=1 && sum2<1))
		{
			cout<<"Sistemul nu poate fi rezolvat cu metodat Gauss-Siedel\n";
			return -1;
		}
	}
	xn_1=new double[N];
	ofstream file;
	if(type==1 || type==2) file.open("Gauss_Siedel.dat");
	//calculam q-urile
	qi=new double[N];
	for(i=0;i<N;i++) qi[i]=0.0;
	for(i=0;i<N;i++)
	{
		sum1=0.0;
		for(j=i+1;j<N;j++)
		sum1+=fabs(mat[i][j]/mat[i][i]);
		for(j=0;j<i;j++)
			sum1+=fabs(mat[i][j]/mat[i][i])*qi[j];
		qi[i]=sum1;
	}
	//calculam maximul (adica q real)
	q=qi[0];
	for(i=1;i<N;i++) if(q<qi[i]) q=qi[i];
	delete[] qi;
	if(q>=1)
	{
		cout<<"Sistemul nu poate fi rezolvat cu metodat Gauss-Siedel";
		cout<<" deoarece q="<<q<<">=1\n";
		return -1;
	}
	//calculam primul pas
	for(i=0;i<N;i++) xn_1[i]=0.0;
	for(i=0;i<N;i++)
	{
		xn[i]=va[i]/mat[i][i];
		for(j=i+1;j<N;j++) xn[i]-=mat[i][j]/mat[i][i]*xn_1[j];
		for(j=0;j<i;j++) xn[i]-=mat[i][j]/mat[i][i]*xn[j];
	}
	max=fabs(xn[0]-xn_1[0]);
	for(i=1;i<N;i++)
		if(max<fabs(xn[i]-xn_1[i])) max=fabs(xn[i]-xn_1[i]);
	count=q*max/(1-q);
	cout<<"q="<<q<<endl<<"max="<<max<<endl;
	cout<<"count="<<fabs(count)<<endl;
	if(type==1 || type==2)
	{
		file<<"q="<<q<<endl;
		file<<"pas=0 err="<<count<<endl;
		if(type==2) cout<<"pas=0 err="<<count<<endl;
		for(i=0;i<N;i++)
		{
			file<<"x["<<i<<"]="<<xn[i]<<endl;
			if(type==2) cout<<"x["<<i<<"]="<<xn[i]<<endl;
		}
	}
	crt=1;
	while(fabs(count)>err)
	{
		for(i=0;i<N;i++) xn_1[i]=xn[i];
		for(i=0;i<N;i++)
		{
			xn[i]=va[i]/mat[i][i];
			for(j=i+1;j<N;j++) xn[i]-=mat[i][j]/mat[i][i]*xn_1[j];
			for(j=0;j<i;j++) xn[i]-=mat[i][j]/mat[i][i]*xn[j];
		}
		max=fabs(xn[0]-xn_1[0]);
		for(i=1;i<N;i++)
			if(max<fabs(xn[i]-xn_1[i])) max=fabs(xn[i]-xn_1[i]);
		count=q*max/(1-q);
		if(type==1 || type==2)
		{
			file<<"pas="<<crt<<" err="<<count<<endl;
			if(type==2) cout<<"pas="<<crt<<" err="<<count<<endl;
			for(i=0;i<N;i++)
			{
				file<<"x["<<i<<"]="<<xn[i]<<endl;
				if(type==2) cout<<"x["<<i<<"]="<<xn[i]<<endl;
			}
		}
		crt++;
	}
	if(type==1 || type==2) file.close();
	//Afisez nr pasii
	cout<<"Dupa "<<crt<<" pasi avem solutia"<<endl;
	delete []xn_1;
	return 0;
}
int main(int argc, char* argv[])
{
	double **mat,*xn,*va;
	double *temp;
	long i,j,N;
	double err;
	int type;
	cout<<"Introduceti N=";cout.flush();cin>>N;
	cout<<"Introduceti eroarea, err=";cout.flush();cin>>err;
	cout<<"Doriti rulare simpla=0\n";
	cout<<"Doriti rulare cu scoatere in fisier a pasilor intermediari=1\n";
	cout<<"Doriti rulare cu scoatere in fisier si la ecran a pasilor intermediari=2\n";
	cin>>type;
	/* aloc memorie */
	mat=(double **)calloc(N,sizeof(double *));
	temp=(double *)calloc(N*N,sizeof(double));
	for(i=0;i<N;i++)
	{
		mat[i]=temp;
		temp+=N;
	}
	xn=new double[N];
	va=new double[N];
	cout<<"Introduceti matricea sistemului\n";
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			cin>>mat[i][j];
	cout<<"Introduceti vectorul termenilor liberi\n";
	for(i=0;i<N;i++) cin>>va[i];
	int solutie;
	solutie=jacobi_collumn(mat,va,xn,err,N,type);
//	if(solutie==-1)
//	{
		//cout<<"Sistemul nu se poate rezolva cu metoda Jacobi pe coloane\n";
		solutie=jacobi_row(mat,va,xn,err,N,type);
/*		if(solutie==-1)
		{
			cout<<"Sistemul nu se poate rezolva cu metoda Jacobi pe rinduri vom incerca Gauss-Siedel\n";
		}	*/
		solutie=gauss_siedel(mat,va,xn,err,N,type);
/*		if(solutie==-1)
		{
			cout<<"Sistemul nu se poate rezolva prin metoda Gauss-Siedel\n";
			//eliberez memoria
			free(*mat);
			free(mat);
			delete []xn;
			delete []va;
			return 1;
		}	
	}	*/
	if(type==0)
	for(i=0;i<N;i++)
			cout<<"X["<<i<<"]="<<xn[i]<<endl;
	/* eliberez memoria */
	free(*mat);
	free(mat);
	delete []xn;
	delete []va;
	return 0;
}
