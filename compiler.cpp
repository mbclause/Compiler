/*
File: compiler.cpp
Description: This file contains the functions that implement part two of the project.
*/

#include "compiler.h"




/*
Function: CheckVariable
Description: This function checks if the given variable has been declared earlier in the program.
*/
bool     CheckVariable(vector<string>  IDList, string  ID)
{
    vector<string>::iterator   IDPtr;

    // loop through variable list
    for (IDPtr = IDList.begin(); IDPtr < IDList.end(); IDPtr++)
    {
        // break if there's a match
        if (*IDPtr == ID)
            break;
    }

    // if we looped through the whole list, no match
    if (IDPtr == IDList.end())
    {
        return false;
    }

    return true;
} // end "CheckVariable"



/*
Function: GetStateString
Description: Converts variables of type STATE into a string
*/
string   GetStateString(STATE   state)
{
    string  word;

    if (state == REJECT)
        word = " ";

    else if (state == LAMBDA)
        word = "lambda";

    else if (state == INT_STATE)
        word = "integer";

    else if (state == STAT_MORE_SLIST)
        word = "<stat><more-slist>";

    else if (state == STAT_LIST_STATE)
        word = "<stat-list>";

    else if (state == WRITE_STATE)
        word = "<write>";

    else if (state == PRINT_VAL_ID)
        word = "print ( <value> <identifier> ) ;";

    else if (state == TERM_EPRIME)
        word = "<term><eprime>";

    else if (state == PLUS_TERM_EPRIME)
        word = "+<term><e-prime>";

    else if (state == FACTOR_TPRIME)
        word = "<factor><t-prime>";

    else if (state == NUM_STATE)
        word = "<number>";

    else if (state == SIGN_DIGIT_MDIGITS)
        word = "<sign><digit><more-digits>";

    else if (state == PLUS_STATE)
        word = "+";

    else if (state == MINUS_TERM_EPRIME)
        word = "-<term><e-prime>";

    else if (state == MINUS_STATE)
        word = "-";

    else if (state == TIMES_FACTOR_TPRIME)
        word = "*<factor><t-prime>";

    else if (state == DIV_FACTOR_TPRIME)
        word = "/<factor><t-prime>";

    else if (state == PAREN_EXPR)
        word = "(<expr>)";

    else if (state == LETTER_MORE)
        word = "<letter><more>";

    else if (state == DEC_COL_TYPE)
        word = "<dec> : <type>";

    else if (state == ID_MORE_DEC)
        word = "<identifier><more-dec>";

    else if (state == ASSIGN_STATE)
        word = "<assign>";

    else if (state == ID_EQUALS_EXPR)
        word = "<identifier> = <expr>";

    else if (state == ID_STATE)
        word = "<identifier>";

    else if (state == LETTERS_STATE)
        word = "abcdf";

    else if (state == DIGIT_MORE)
        word = "<digit><more>";

    else if (state == DIGIT_MDIGITS)
        word = "<digit><more-digits>";

    else if (state == DIGITS_STATE)
        word = "0...9";

    else if (state == COMMA_DEC)
        word = ", <dec>";

    else if (state == VALUE_EQUALS_STATE)
        word = "\"value=\"";

    else if (state == PROG_TO_END)
        word = "program <identifier> ; var <dec-list> begin <stat-list> end.";

    else
    {
        cerr << state << " is Invalid state for GetStateString\n";

        exit(1);
    }

    return word;
} // end "GetStateString"



/*
Function: GetSymbolString
Description: Takes a parameter of type SYMBOL and converts it into a string.
*/
string   GetSymbolString(SYMBOL  symbol)
{
    string word;

    if (symbol == PROG)
        word = "<prog>";
        
    else if (symbol == ID)
    {
        word = "<identifier>";
    }
        
    else if (symbol == MORE)
    {
        word = "<more>";
    }
        
    else if (symbol == DEC_LIST)
    {
        word = "<dec-list>";
    }
        
    else if (symbol == DEC)
    {
        word = "<dec>";
    }
        
    else if (symbol == MORE_DEC)
    {
        word = "<more-dec>";
    }
        
    else if (symbol == TYPE)
    {
        word = "<type>";
    }
        
    else if (symbol == STAT_LIST)
    {
        word = "<stat-list>";
    }
        
    else if (symbol == MORE_SLIST)
    {
        word = "<more-slist>";
    }
        
    else if (symbol == STAT)
    {
        word = "<stat>";
    }
        
    else if (symbol == WRITE)
    {
        word = "<write>";
    }
        
    else if (symbol == VALUE)
    {
        word = "<value>";
    }
        
    else if (symbol == ASSIGN)
    {
        word = "<assign>";
    }
        
    else if (symbol == EXPR)
    {
        word = "<expr>";
    }
        
    else if (symbol == E_PRIME)
    {
        word = "<e-prime>";
    }
        
    else if (symbol == TERM)
    {
        word = "<term>";
    }

    else if (symbol == T_PRIME)
    {
        word = "<t-prime>";
    }
        
    else if (symbol == FACTOR)
    {
        word = "<factor>";
    }
        
    else if (symbol == NUMBER)
    {
        word = "<number>";
    }
        
    else if (symbol == MORE_DIGITS)
    {
        word = "<more-digits>";
    }
        
    else if (symbol == SIGN)
    {
        word = "<sign>";
    }
        
    else if (symbol == DIGIT)
        word = "<digit>";
        
    else if(symbol == LETTER)
        word = "<letter>";

    else if (symbol == BEGIN)
        word = "begin";
        
    else if(symbol == END)
        word = "end.";
        
    else if(symbol == VAR)
        word = "var";
        
    else if (symbol == INT)
        word = "integer";
        
    else if(symbol == PRINT)
        word = "print";
        
    else if(symbol == PLUS)
        word = "+";
        
    else if(symbol == MINUS)
        word = "-";
        
    else if (symbol == TIMES)
        word = "*";
        
    else if(symbol == DIV)
        word = "/";
        
    else if (symbol == L_PAREN)
        word = "(";
        
    else if(symbol == R_PAREN)
        word = ")";
        
    else if (symbol == EQUALS)
        word = "=";
        
    else if (symbol == ABCDF)
        word = "abcdf";
        
    else if (symbol == ZERO_TO_NINE)
        word = "0...9";
        
    else if (symbol == COLON)
        word = ":";
        
    else if (symbol == SEMI_COLON)
        word = ";";

    else if (symbol == COMMA)
        word = ",";
        
    else if (symbol == VALUE_EQUALS)
        word = "\"value=\"";
        
    else if (symbol == PROGRAM)
        word = "program";

    else
    {
    cerr << symbol << " is Invalid symbol for GetSymbolString\n";

    exit(1);
 }

    return word;
} // end "GetSymbolString



/*
Function: GetSymbol
Description: Takes a string token and converts it into type SYMBOL
*/
SYMBOL   GetSymbol(string  word)
{
    SYMBOL symbol;

    if (word.length() == 1 && isalpha(word[0]))
    {
        if (word == "a" || word == "b" || word == "c" || word == "d" || word == "f")
            symbol = ABCDF;

        else
        {
            cerr << "Letters must be abcdf\n";

            exit(1);
        }
    }

    else if (isdigit(word[0]))
        symbol = ZERO_TO_NINE;

    else
    {
        if (word == "begin")
            symbol = BEGIN;

    else if (word == "end.")
        symbol = END;

    else if (word == "var")
    symbol = VAR;

    else if (word == "integer")
    symbol = INT;

    else if (word == "print")
    symbol = PRINT;

    else if (word == "+")
    symbol = PLUS;

    else if (word == "-")
    symbol = MINUS;

    else if (word == "*")
    symbol = TIMES;

    else if (word == "/")
    symbol = DIV;

    else if (word == "(")
    symbol = L_PAREN;

    else if (word == ")")
    symbol = R_PAREN;

    else if (word == "=")
    symbol = EQUALS;

    else if (word == ":")
    symbol = COLON;

    else if (word == ";")
    symbol = SEMI_COLON;

    else if (word == ",")
    symbol = COMMA;

    else if (word == "\"value=\"")
    symbol = VALUE_EQUALS;

    else if (word == "program")
    symbol = PROGRAM;

    else
    {
    cerr << word << " is Invalid input for GetSymbol\n";

    exit(1);
    }
    }

    return symbol;
} // end "GetSymbol"



/*
Function: printStack
Description: Prints out the stack.
*/
void  printStack(Stack<SYMBOL>  stack, ofstream  &out)
{
    SYMBOL   symbol;

    string  c;

    STACK_ERR  success;

    out << "   ";

    for (int i = 0; i < stack.getStackSize(); i++)
    {
        symbol = stack.peek(i, success);

        c = GetSymbolString(symbol);

        out << c << " ";
    }

    out << endl;
}



/*
Function: PushStack
Description: Takes an entry from the parsing table and pushes all of it's symbols onto the stack in reverse order
*/
void  PushStack(STATE state, Stack<SYMBOL>* stack,  ofstream  &out)
{
    // push "integer"
    if (state == INT_STATE)
    {
        out << "   Push INTEGER\n";

        stack->push(INT);
    }
        
    // push <more-slist><stat>
    else if (state == STAT_MORE_SLIST)
    {
        out << "   Push <more-slist><stat>\n";

        stack->push(MORE_SLIST);

        stack->push(STAT);
    }
        
    else if (state == STAT_LIST_STATE)
    {
        out << "   Push <stat-list>\n";

        stack->push(STAT_LIST);
    }
        
    else if (state == WRITE_STATE)
    {
        out << "   Push <write>\n";

        stack->push(WRITE);
    }


    // push ; ) <identifier> <value> ( print
    else if (state == PRINT_VAL_ID)
    {
        out << "   Push ; ) <identifier> <value> ( print\n";

        stack->push(SEMI_COLON);

        stack->push(R_PAREN);

        stack->push(ID);

        stack->push(VALUE);

        stack->push(L_PAREN);

        stack->push(PRINT);
    }
    
    // push <e-prime><term>
    else if (state == TERM_EPRIME)
    {
        out << "   Push <e-prime><term>\n";

        stack->push(E_PRIME);

        stack->push(TERM);
    }
        
    // push <e-prime><term>+
    else if (state == PLUS_TERM_EPRIME)
    {
        out << "   Push <e-prime> <term> +\n";

        stack->push(E_PRIME);

        stack->push(TERM);

        stack->push(PLUS);
    }
    
    // push <t-prime><factor>
    else if (state == FACTOR_TPRIME)
    {
        out << "   Push <t-prime><factor>\n";

        stack->push(T_PRIME);

        stack->push(FACTOR);
    }
        
    else if (state == NUM_STATE)
    {
        out << "   Push <number>\n";

        stack->push(NUMBER);
    }
    
    // Push <more-digits><digits><sign>
    else if (state == SIGN_DIGIT_MDIGITS)
    {
        out << "   Push <more-digits><digits><sign>\n";

        stack->push(MORE_DIGITS);

        stack->push(DIGIT);

        stack->push(SIGN);
    }
        
    else if (state == PLUS_STATE)
    {
        out << "   Push +\n";

        stack->push(PLUS);
    }
     
    // Push <e-prime><term>-
    else if (state == MINUS_TERM_EPRIME)
    {
        out << "   Push <e-prime><term>-\n";

        stack->push(E_PRIME);

        stack->push(TERM);

        stack->push(MINUS);
    }
       
        
    else if (state == MINUS_STATE)
    {
        out << "   Push -\n";

        stack->push(MINUS);
    }

    // push <t-prime> <factor> *
    else if (state == TIMES_FACTOR_TPRIME)
    {
        out << "   Push <t-prime> <factor> *\n";

        stack->push(T_PRIME);

        stack->push(FACTOR);

        stack->push(TIMES);
    }
        
    else if (state == DIV_FACTOR_TPRIME)
    {
        out << "   Push <t-prime> <factor> / \n";

        stack->push(T_PRIME);

        stack->push(FACTOR);

        stack->push(DIV);
    }
        
    // Push ) <expr> (
    else if (state == PAREN_EXPR)
    {
        out << "   Push ) <expr> (\n";

        stack->push(R_PAREN);

        stack->push(EXPR);

        stack->push(L_PAREN);
    }
        
    // Push <more> <letter>
    else if (state == LETTER_MORE)
    {
        out << "   Push <more> <letter>\n";

        stack->push(MORE);

        stack->push(LETTER);
    }
        
    // Push ; <type> : <dec>
    else if (state == DEC_COL_TYPE)
    {
    out << "   Push ; <type> : <dec>\n";

    stack->push(SEMI_COLON);

    stack->push(TYPE);

    stack->push(COLON);

    stack->push(DEC);
 }
        
 // Push <more-dec> <identifier>
    else if (state == ID_MORE_DEC)
        {
        out << "   Push <more-dec> <identifier>\n";

        stack->push(MORE_DEC);

        stack->push(ID);
 }
        
    else if (state == ASSIGN_STATE)
        {
        out << "   Push <assign>\n";

        stack->push(ASSIGN);
 }
        
 // Push ; <expr> = <identifier>
    else if (state == ID_EQUALS_EXPR)
        {
        out << "   Push ; <expr> = <identifier>\n";

        stack->push(SEMI_COLON);

        stack->push(EXPR);

        stack->push(EQUALS);

        stack->push(ID);
 }
        
    else if (state == ID_STATE)
    {
    out << "   Push <identifier>\n";

    stack->push(ID);
 }
        
    else if (state == LETTERS_STATE)
        {
        out << "   Push abcdf\n";

        stack->push(ABCDF);
 }

 // Push <more> <digit>
    else if (state == DIGIT_MORE)
        {
        out << "   Push <more> <digit>\n";

        stack->push(MORE);

        stack->push(DIGIT);
 }

        // Push <more-digits> <digit>
    else if (state == DIGIT_MDIGITS)
        {
        out << "   Push <more-digits> <digit>\n";

        stack->push(MORE_DIGITS);

        stack->push(DIGIT);
 }
        
    else if (state == DIGITS_STATE)
        {
        out << "   Push 0...9\n";

        stack->push(ZERO_TO_NINE);
 }
        
    else if (state == COMMA_DEC)
        {
        out << "   Push <dec> ,\n";

        stack->push(DEC);

        stack->push(COMMA);
 }
        
    else if (state == VALUE_EQUALS_STATE)
        {
        out << "   Push , \"value=\"\n";

        stack->push(COMMA);

        stack->push(VALUE_EQUALS);
 }
     // program <identifier> ; var <dec-list> begin <stat-list> end.
     // Push end. <stat-list> begin <dec-list> var ; <idengifier> program
    else if (state == PROG_TO_END)
    {
    out << "   Push end. <stat-list> begin <dec-list> var ; <idenTifier> program\n";

    stack->push(END);

    stack->push(STAT_LIST);

    stack->push(BEGIN);

    stack->push(DEC_LIST);

    stack->push(VAR);

    stack->push(SEMI_COLON);

    stack->push(ID);

    stack->push(PROGRAM);
 }

    else
    {
    cerr << "Invalid state passed to PushStack\n";

    exit(1);
 }
} // end "PushStack"



/*
Function: Trace
Description: Takes a program in a file stream as input and determines if it's accepted or rejected by the grammar.
Prints specific error messeges.
*/
bool   Trace(ifstream& in, ofstream  &out)
{
    string   token;

    string   PrevToken;

    string   nextToken;

    vector<SYMBOL>  symbolList;

    vector<string>  IDList;

    vector<SYMBOL>::iterator  SymPtr;

    int   LocationFlags = 0;

    int  column;

    bool  isResWord = false;

    bool  firstToken = true;

    bool  prevVar = false;

    Stack<SYMBOL>  stack;

    Stack<string>  ParenStack;

    SYMBOL  stackTop;

    SYMBOL  CurrSymbol;

    STACK_ERR   success;

    STATE  state;


    // make sure last token is "end."
    while (in >> token)
    {
    }

    if (token != "end.")
    {
        if (token == "end")
            cout << ". is missing\n";

        else
            cout << "END. is expected\n";

        return false;
    }

    // go back to beginning of file
    in.clear();

    in.seekg(0);




    // <prog>
    stack.push(PROG);

    out << "Push <prog>\n";

    // while there are tokens to read
    while (in >> token)
    {
        out << "READ TOKEN: " << token << endl << endl;

        // CHECK RESERVED WORDS
        // make sure the first token = "program"
        if (firstToken)
        {
            if (token != "program")
            {
                cout << "PROGRAM is expected\n";

                return false;
            }

            firstToken = false;
        }

        // if we are still just in Program and PrevToken = ; then "var" is expected
        if (LocationFlags == InProgram && PrevToken == ";")
        {
            if (token != "var")
            {
                cout << "VAR is expected\n";

                return false;
            }
        }

        // if we are in declarations and Previous Token is ;  "begin" is expected
        if ((LocationFlags == InProgram + InDeclarations) && (PrevToken == ";"))
        {
            if (token != "begin")
            {
                cout << "BEGIN is expected\n";

                return false;
            }
        }

        // if we are in declarations and Previous Token is :  "integer" is expected
        if ((LocationFlags == InProgram + InDeclarations) && (PrevToken == ":"))
        {
            if (token != "integer")
            {
                cout << "INTEGER is expected\n";

                return false;
            }
        }



        // CHECK LOCATION
        // if we read "program" we are in the program
        if (token == "program")
            LocationFlags |= InProgram;

        // if we read "var" then we are in the declaration list
        if (token == "var")
            LocationFlags |= InDeclarations;

        // if we read "begin" we are in the statements list
        if (token == "begin")
            LocationFlags |= InStatements;




        // set a flag if token is a reserved word
        if (token == "\"value=\"" || token == "program" || token == "var" || token == "begin" || token == "end." ||
            token == "integer" || token == "print")
            isResWord = true;





        //CHECK PUNCTUATION
        // check for semi colons, if we miss a semi-colon at the end of a line (excluding begin and var), then print error
        if ((token != "var") && (token != "begin") && (token != "end.") && in.peek() == '\n')
        {
            if (token != ";")
            {
                cout << "; is missing\n";

                return false;
            }
        }

        // check for commas, if we miss a comma after "value=" or between variable declarations print error
        if ((PrevToken == "\"value=\"") || (prevVar && token != ":" && token != "integer"))
        {
            if ((token != ","))
            {
                cout << ", is missing\n";

                return false;
            }
        }

        // CHECK PARENTHESES
        // if we miss a ( after "print", error
        if (PrevToken == "print")
        {
            if (token != "(")
            {
                cout << "( is missing\n";

                return false;
            }
        }

        // push all ( onto the stack
        if (token == "(")
            ParenStack.push("(");

        // if we read )  pop the stack, if stack is empty, we're missing a (
        if (token == ")")
        {
            if (ParenStack.getStackSize() <= 0)
            {
                cout << "( is missing\n";

                return false;
            }

            ParenStack.pop();
        }







        // CHECK VARIABLES
        // store variables when they're defined
        if ((LocationFlags == InProgram + InDeclarations) && isalpha(token[0]) && !isResWord)
        {
            IDList.push_back(token);

            prevVar = true;
        }

        else
        {
            prevVar = false;
        }

        // if a variable is used in a statement, check that it's been defined
        if ((LocationFlags == InProgram + InDeclarations + InStatements) && isalpha(token[0]) && !isResWord)
        {
            if (!CheckVariable(IDList, token))
            {
                in >> nextToken;

                if (nextToken == "(")
                {
                    cout << "PRINT expected\n";
                }

                else
                    cout << "Unknown variable - " << token << endl;

                return false;
            }
        }



        // if input is just a character, save it in symbol table
        if (token.length() == 1)
            symbolList.push_back(GetSymbol(token));

        // if input is a word...
        else if(token.length() > 1)
        { 
            // if input is a reserved word, save it in table
            if (isResWord)
                symbolList.push_back(GetSymbol(token));

            // if input is an ID or number, save each character in table
            else
            {
                for (int i = 0; i < token.length(); i++)
                {
                    string  s(1, token[i]);

                    symbolList.push_back(GetSymbol(s));
                }
            }
        }


        // loop through symbol table
        for (SymPtr = symbolList.begin(); SymPtr < symbolList.end(); SymPtr++)
        {
            // get top of stack and pop it
            stackTop = stack.peek(success);

            stack.pop();

            out << "Pop " << GetSymbolString(stackTop) << endl;

            // read next symbol
            CurrSymbol = *SymPtr;

            out << "Read " << GetSymbolString(CurrSymbol) << endl;

            // while the top of the stack and current symbol don't match
            while (stackTop != CurrSymbol)
            {
                column = CurrSymbol - 23;

                // make sure indices are in range
                if (stackTop < 23 && stackTop >= 0)
                {
                    // look up state in parsingTable[stack top][symbol]
                    state = ParseTable[stackTop][column];
                }

                else
                {
                    // if we're at the beginning of <write>, "print" is expected
                    if (token == "(" && (PrevToken == ";" || PrevToken == "begin"))
                        cout << "PRINT is expected\n";

                    // if paren stack isn't empty, we did not have a matching ) for all (
                    else if (ParenStack.getStackSize() > 0)
                        cout << ") is missing\n";

                    return false;
                }

                out << "   [" << GetSymbolString(stackTop) << "][" << GetSymbolString(CurrSymbol) << "] = "
                    << GetStateString(state) << endl;

                // if parsing table entry is blank, reject
                if (state == REJECT)
                {
                    // if we're at the beginning of <write>, "print" is expected
                    if (token == "(" && (PrevToken == ";" || PrevToken == "begin"))
                        cout << "PRINT is expected\n";

                    // if paren stack isn't empty, we did not have a matching ) for all (
                    else if (ParenStack.getStackSize() > 0)
                        cout << ") is missing\n";

                    return false;
                }

                // if table entry is lambda, skip, if no, push state onto stack in reverse order
                if (state != LAMBDA)
                    PushStack(state, &stack, out);

                printStack(stack, out);

                // pop stack
                stackTop = stack.peek(success);

                stack.pop();

                out << "Pop " << GetSymbolString(stackTop) << endl;
            } // end "while"

            out << "Match! " << GetSymbolString(stackTop) << " = " << GetSymbolString(CurrSymbol) << endl;

            printStack(stack, out);

            out << endl;

            if ((stackTop == END) && (CurrSymbol == END))
            {
                return true;
            }
        } // end "for"

        isResWord = false;
        
        // clear the symbol table
        symbolList.clear();

        // save previous token
        PrevToken = token;
    } // end "while"
} // end "trace"

