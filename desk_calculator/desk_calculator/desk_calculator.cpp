// desk_calculator.cpp : Defines the entry point for the console application.
//

#include "StdAfx.h"
#include "Driver.h"
/*
Modify the desk calculator program into a module in the style of §2.4 using namespaces.
Don’t use any global usingdirectives.
Keep a record of the mistakes you made. Suggest ways
of avoiding such mistakes in the future.
*/
/*
Allow a user to define functions in the calculator. Hint: Define a function as a sequence of
operations just as a user would have typed them. Such a sequence can be stored either as a
character string or as a list of tokens. Then read and execute those operations when the function
is called. If you want a userdefined
function to take arguments, you will have to invent a notation
for that.
Convert the desk calculator to use a s y m b o l structure instead of using the static variables
n u m b e r _ v a l u e and s t r i n g _ v a l u e .
*/
/*
Add functions such as s q r t (), l o g (), and s i n () to the desk calculator from §6.1. Hint:
Predefine the names and call the functions through an array of pointers to functions. Don’t forget
to check the arguments in a function call.
*/
int _tmain(int argc, _TCHAR* argv[])
{
	Driver::init();
	Driver::run();
	return 0;
}

