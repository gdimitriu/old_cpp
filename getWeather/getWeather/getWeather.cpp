// getWeather.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Weather.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CWeather weather;
	weather.openFile("weather.dat");
	weather.findAndPrintSmallSpread();
	weather.closeFile();
	return 0;
}

