# CPSC 323 Final Project - Compiler Using Predictive Parsing


This is a compiler for a simplified programming language written by the professor. Two other people worked on the project, but all of the code seen here is mine.

The grammar of the language is defined in the "grammar.pdf" file. A sample input is also given in "finalp1.txt." 

The program has three parts:

1. In part one, the program removes comments and blank lines. It also trims white space so that there is one space after
every token.

2. In part two, the program traces through the cleaned up input file and determines if it is accepted or rejected
by the languages grammar using a predictive parsing table. It displays "PROGRAM IS ACCEPTED" if the input is accepted and "PROGRAM IS REJECTED" if not. If rejected, specific error messages are given.

3. In part three, if the program is accepted in part two, the input file is converted into C++.
