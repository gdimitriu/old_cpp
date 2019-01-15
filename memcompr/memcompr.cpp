// memcompr.cpp : Defines the entry point for the console application.
//

#include"zlib.h"
#include"stdafx.h"
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"gzMFile.h"

int main(int argc, char* argv[])
{
	CgzMFile mfile;
	mfile.open(true,false);
	int i;
	char input[200];
	unsigned long len[6];
	double in[10];
	int r=3;
	for(i=0;i<r;i++)
	{
		for(int j=0;j<200;j++) input[j]='\0';
		gets(input);
		len[i]=strlen(input);
		mfile.write(input,len[i]);
	}
	for(i=0;i<10;i++) in[i]=(double)rand()/RAND_MAX;
	mfile.write(in,10*sizeof(double));
	mfile.close();
	cout<<"write end\n";cout.flush();
	//de aici citesc
	mfile.open(true,true);
	for(i=0;i<r;i++)
	{
		for(int j=0;j<200;j++) input[j]='\0';
		mfile.read(input,len[i]);
		cout<<input<<endl;cout.flush();
	}
	for(i=0;i<10;i++) in[i]=0.0;
	mfile.read(in,10*sizeof(double));
	for(i=0;i<10;i++) cout<<in[i]<<" ";
	cout<<endl;cout.flush();
	mfile.reset();
	unsigned long dim;
	int part=7;
	int j,k;
	dim=0;
	for(i=0;i<r;i++) dim+=len[i];
	for(j=0;j<200;j++) input[j]='\0';
	for(k=0;k<part;k++)
		mfile.read(&input[k*dim/part],dim/part);
	cout<<input<<endl;cout.flush();
	mfile.reset();
	part=7;
	for(j=0;j<200;j++) input[j]='\0';
	mfile.read(input,dim/part);
	mfile.seek(false,dim/part);
	for(k=2;k<part;k++)
		mfile.read(&input[k*dim/part-dim/part],dim/part);
	cout<<input<<endl;cout.flush();
	mfile.close();
	return 0;
}
