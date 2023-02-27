//-------------------------------------------------------------------------------------------------------------------------
// Group names: Edgardo Arteaga, Michael Clausen, Dulcie Hang
//
// Assignment : Final Project
//
// Due date : 12/06/22
//
// Purpose: This program takes as input a file written in a simple programming language. The program has three parts.
// 1. In part one, the program removes comments and blank lines. It also trims white space so that there is one space after
//    every token.
// 2. In part two, the program traces through the cleaned up input file and determines if it is accepted or rejected
//    by the languages grammar. Displays "PROGRAM IS ACCEPTED" if it's accepted and "PROGRAM IS REJECTED" if it's rejected
//    along with certain specific error messages.
// 3. In part three, if the program is accepted in part two, the input file is converted into C++.
//--------------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <string>
#include <fstream>
#include "compiler.h"
#include "Convert_to_CPP.h"
#include "part_1.h"

using namespace std;



// main
int main(void)
{
	ifstream    in;

	ofstream    out;
  
	bool  retVal = false;

	out.open("output.txt");

	if (out.fail())
	{
		cerr << "File failed to open\n";

		exit(1);
	}

  // Part I
  // call PartOne()
  PartOne();

  in.open("finalp2.txt");

  	if (in.fail())
	{
		cerr << "File failed to open\n";

		exit(1);
	}

  // Part II
	retVal = Trace(in, out);

	if (retVal == true)
	{
		cout << "PROGRAM IS ACCEPTED!\n";

    // Part III
		ConvertToCPP();

	}

	else
		cout << "PROGRAM IS REJECTED\n";

	in.close();

	out.close();

	return 0;
} // end "main"