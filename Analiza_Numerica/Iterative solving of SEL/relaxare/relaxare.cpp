// relaxare.cpp : Defines the entry point for the console application.
//Copyrigth Gabriel Dimitriu 2005.
//Relaxation method for solving LEQ
#include<iostream.h>
#include<fstream.h>
#include<math.h>
#include<stdlib.h>


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
	double lmin,lmax;
	cout<<"Introduceti valorile minime si maxime ale parametrilor lambda\n";
	cout<<"Lambda minim=";cin>>lmin;
	cout<<"Lambda maxim=";cin>>lmax;
	double q=(lmax-lmin)/(lmax+lmin);
	double alpha=2/(lmin+lmax);
	ofstream file;
	if(type==1 || type==2) file.open("relaxare.dat");
	int crt=0;
	double count=q/(1-q);
	double *xn_1;
	xn_1=new double[N];
	for(i=0;i<N;i++) xn_1[i]=0;
	//calculam primul pas
	for(i=0;i<N;i++)
	{
		xn[i]=alpha*va[i]/mat[i][i]+(1-alpha)*xn_1[i];
		for(j=0;j<N;j++)
			if(i!=j) xn[i]-=alpha*mat[i][j]/mat[i][i]*xn_1[j];
	}
	//calculam eroarea
	double sum;
	sum=0.0;
	for(i=0;i<N;i++) sum+=mat[i][i]*(xn[i]-xn_1[i]);
	sum=sqrt(sum);
	sum=sum*count;
	crt++;
	cout<<"q="<<q<<endl;
	if(type==1 || type==2)
	{
		file<<"q="<<q<<endl;
		file<<"pas=0 err="<<sum<<endl;
		if(type==2) cout<<"pas=0 err="<<sum<<endl;
		for(i=0;i<N;i++)
		{
			file<<"x["<<i<<"]="<<xn[i]<<endl;
			if(type==2) cout<<"x["<<i<<"]="<<xn[i]<<endl;
		}
	}
	while(sum>err)
	{
		for(i=0;i<N;i++) xn_1[i]=xn[i];
		for(i=0;i<N;i++)
		{
			xn[i]=alpha*va[i]/mat[i][i]+(1-alpha)*xn_1[i];
			for(j=0;j<N;j++)
				if(i!=j) xn[i]-=alpha*mat[i][j]/mat[i][i]*xn_1[j];
		}
		//calculam eroarea
		sum=0.0;
		for(i=0;i<N;i++) sum+=mat[i][i]*(xn[i]-xn_1[i])*(xn[i]-xn_1[i]);
		sum=sqrt(sum);
		sum=sum*count;
		if(type==1 || type==2)
		{
			file<<"q="<<q<<endl;
			file<<"pas="<<crt<<" err="<<sum<<endl;
			if(type==2) cout<<"pas="<<crt<<" err="<<sum<<endl;
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
	//eliberez memorie
	delete[] xn;
	delete[] va;
	delete[] xn_1;
	free(*mat);
	free(mat);
	return 0;
}
