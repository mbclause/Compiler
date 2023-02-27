/*
File: part_1.cpp
Description: Implements the first part of the program.
Formats the input file by removing extra white space and
comments.
*/

#include "part_1.h"



/*
Function: PartOne
Description: Takes the input file and formats it by
removing extra white space, blank lines, and comments.
*/
void   PartOne()
{
	ifstream   in;

	ofstream   out;

	string   token;

	string   line;

	string   buffer;

	bool  inComment = false;

	bool  needNewLine = false;

	bool  lineHasCode = false;

	vector<string>  tokensInString;

	vector<string>::iterator   ptr;

	in.open("finalp1.txt");

	out.open("finalp2.txt");

  // read each line in the input file
	while (getline(in, line))
	{
    // skip blank lines
		if (line.empty())
			needNewLine = false;

		else
		{
			stringstream  ln(line);

      // read each token in the line
			while (ln >> token)
			{
        // if we reach the beginning or end of a comment...
				if (token == "**")
				{
					// if we're in a comment, we've now finished the comment
					if (inComment)
						inComment = false;

					// otherwise, it's the beginning of a comment
					else
						inComment = true;

					continue;
				}

        // if we're in a comment, don't ouput
				if (inComment)
				{
					if (!lineHasCode)
						needNewLine = false;

					continue;
				}

        // not in a comment
				else
				{
          // if token is a single character, output it
					if (token.length() == 1)
					{
						buffer += token;

						buffer += " ";
					}

					else
					{
            // if string contains multiple tokens
						if (token.find(";") != string::npos || token.find(",") != string::npos || token.find(":") != string::npos
							|| token.find("=") != string::npos || token.find("(") != string::npos || token.find(")") != string::npos ||
							token.find("*") != string::npos || token.find("/") != string::npos || token.find("+") != string::npos ||
							token.find("-") != string::npos)
						{
              // get each individual token
							TrimString(tokensInString, token);

              // print each token
							for (ptr = tokensInString.begin(); ptr < tokensInString.end(); ptr++)
							{
								string s = *ptr;

								if (s[0] >= 33)
								{
									buffer += s;

									buffer += " ";
								}

								else
									continue;
							}
						}

            // print individual token
						else
						{
							buffer += token;

							buffer += " ";
						}
					}

					lineHasCode = true;

					needNewLine = true;
				}

				tokensInString.clear();
			}
		}

    // print line
		if (!buffer.empty())
		{
			buffer.pop_back();

			out << buffer;

			buffer.clear();
		}

		if (needNewLine)
			out << endl;

		lineHasCode = false;

		needNewLine = false;
	}

	in.close();

	out.close();
} // end "PartOne"



/*
Function: TrimString
Description: Takes a string and extracts each token from it.
*/
void    TrimString(vector<string>& tokensInString, string token)
{
	string   temp;

  // loop through input string
	for (int i = 0; i < token.length(); i++)
	{
    // if start of a word or number
		if (isalnum(token[i]))
		{
      // get token
			while (isalnum(token[i]))
			{
				temp += token[i];

				i++;
			}

      // save it
			tokensInString.push_back(temp);

      // save whatever's left of the string as well
			string s(1, token[i]);

			tokensInString.push_back(s);
		}

		// if we hit quotation marks, get "value=" and store it
		else if (token[i] == '"')
		{
			temp += token[i];

			i += 1;

			while (token[i] != '"')
			{
				temp += token[i];

				i++;
			}

			temp += token[i];

			tokensInString.push_back(temp);
		}

    // if we get a single character, save it
		else
		{
			string s(1, token[i]);

			tokensInString.push_back(s);
		}

		temp.clear();
	}
} // end "TrimString"