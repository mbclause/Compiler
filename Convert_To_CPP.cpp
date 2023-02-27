/*
File: Convert_To_CPP.cpp
Description: Contains the function definitions that implement part three of the project.
*/


#include "Convert_To_CPP.h"



/*
Function: ConvertToCPP
Description: Takes the program and converts it into C++.
*/
void ConvertToCPP(void)
{
    ifstream final_p2;
    ofstream final_p3;
    string token;
    string v;
    int  numCommas = 0;

    final_p2.open("finalp2.txt");
    final_p3.open("finalp3.cpp");

    
    vector<string> variables;
    vector<string>::iterator  ptr;


    while (final_p2 >> token)
    {
        if (token == "program")
        {
            final_p3 << "#include<iostream>\nusing namespace std;\nint main() {\n"
                << endl;

            while (final_p2 >> token)
            {
                if (token == ";")
                    break;
            }
        }

        else if (token == "var")
        {
            while (final_p2 >> token)
            {

                if (token == "," || token == ":")
                {
                    if (token == ",")
                        numCommas++;

                    continue;
                }

                if (token == "integer")
                {
                    break;
                }

                variables.push_back(token);
            }

            final_p3 << "int ";

            for (ptr = variables.begin(); ptr < variables.end(); ptr++)
            {
                final_p3 << *ptr;

                if (numCommas > 0)
                    final_p3 << " , ";

                numCommas--;
            }
        }

        //   ELSE IF token = ;   print it and then new line   
        else if (token == ";")
            final_p3 << token << '\n';

        //  ELSE IF token = "print", print "cout <<"
        else if (token == "print")
        {
            final_p3 << "cout << ";

            //     loop through input until we read ')'
            while (final_p2 >> token)
            {

                if (token == ")")
                {
                    final_p3 << " endl"; // add final_p3 << " endl "
                    break;
                }

                //       IF input is a comma ignore it
                else if (token == "," || token == "(")
                {
                    continue;
                }

                //       ELSE print token 
                else
                {
                    final_p3 << token << " << ";
                }
            }
        }

        //   ELSE IF token = end.  print "return 0; }"
        else if (token == "end.") 
        {
            final_p3 << "return 0;\n}" << endl;
        }

        else if(token == "begin")
        {
            continue;
        }

        else
        {
            final_p3 << token << " ";
        }
    }
}