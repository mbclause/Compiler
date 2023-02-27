/*
File: stack.cpp
*/

#include "stack.h"

#ifndef stack_cpp
#define stack_cpp

#include <climits>
#include <iostream>
using namespace std;




/*
Function: push

input: val - the value to be pushed onto the stack
output: True if successful and false if no

Description: This function pushes a value on top of the stack. Returns false if the stack is full, true is it is not.
*/
template<class T>
STACK_ERR   Stack<T>::push(T val)
{
	if (size > STACK_SIZE)
	{
		return STACK_FULL;
	}

	values[size] = val;

	size++;

	return SUCCESS;
}



/*
Function: pop

input: none
output: True if successful and false if no

Description: This function removes a value from the top of the stack. Returns true if stack is not empty and false if it is.
*/
template<class T>
STACK_ERR   Stack<T>::pop()
{
	if (size > 0)
	{
		size--;

		return STACK_EMPTY;
	}

	return SUCCESS;
}



/*
Function: peek

input/output: success - Is true or false if the operation is successful or no
output: the address of the value at the top of the stack

Description: This function returns the value at the top of the stack. If the stack is empty, 'success' is set to false and INT_MAX
is returned. 'Success' is set to true otherwise.
*/
template<class T>
T   Stack<T>::peek(STACK_ERR &success)
{
	if (size > 0)
	{
		success = SUCCESS;

		return values[size - 1];
	}

	success = STACK_EMPTY;

	return values[size - 1];
}


//** peek(index, success)
// peek value from stack using the index. Return success false if out of range and values[0],
//       else true and correct value
template<class T>
T Stack<T>::peek(int index, STACK_ERR& success) {
	T temp = values[0];
	success = SUCCESS;
	if (index < 0 || index >= size) {
		success = BAD_INDEX;
		return temp;
	}
	return values[index];
}





#endif