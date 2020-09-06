// fileio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "C13_1.h"
#include "C13_2.h"
#include "C16_3.h"
#include "C16_4.h"
#include "C16_5.h"
#include "Weather.h"
#include "Football.h"
#include "MailForms.h" 
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	C13_1 ex_13_1;
	if(ex_13_1.FileOpen()<0)
	{
		return -1;
	}
	ex_13_1.countLines();
	ex_13_1.FileClose();
	/* copy a file and convert tabs into spaces */
	C13_2 ex_13_2(8);
	if(ex_13_2.OpenInFile()<0)
	{
		return -1;
	}
	if(ex_13_2.OpenOutFile()<0)
	{
		ex_13_2.CloseInFile();
		return -1;
	}
	ex_13_2.CopyFile();
	ex_13_2.CloseInFile();
	ex_13_2.CloseOutFile();

	cout<<"get weather test\n";
	CWeather getWeather;
	getWeather.open("weather.dat");
	getWeather.DayWithSmallestSpread();
	getWeather.close();

	cout<<"get football test\n";
	CFootball getFootball;
	getFootball.open("football.dat");
	string team=getFootball.getTeamWithMinimumSpread();
	cout<<team<<endl;
	getFootball.close();

	cout<<"creates two files from the numbers.txt\n";
	C16_3 divide3;
	divide3.OpenFiles("numbers.txt","divided3.txt","restnumbers.txt");
	divide3.CreateFiles();
	divide3.CloseFiles();

	cout<<"creates a binary file of the numbers.txt \n";
	C16_4 createBinary;
	createBinary.convertToBinary("numbers.txt","binaryNumbers.dat");
	createBinary.convertToText("binaryNumbers.dat","reznumbers.txt");

	cout<<"copy from a file only the characters which have not the highest bit set is 0x80 or €\n";
	C16_5 copySet;
	copySet.OpenFiles("getFile.txt","setFile.txt");
	copySet.CopyAndConvert();
	
	cout<<"test the mail form class\n";
	CMailForms mail;
	mail.OpenFiles("persons.txt");
	return 0;
}

