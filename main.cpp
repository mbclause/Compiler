//-------------------------------------------------------------------------------------------------------------------------
// File: main.cpp
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
