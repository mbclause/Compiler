/*
File: stack.h
*/

#ifndef stack_h
#define stack_h

using namespace std;

const  int  STACK_SIZE = 1000;

enum STACK_ERR { SUCCESS, STACK_EMPTY, STACK_FULL, BAD_INDEX };

template<class T>
class Stack
{
private:
	// the values in the stack
	T  values[STACK_SIZE];

	// the size of the stack
	int  size;

public:
	// default constructor
	Stack() { size = 0; };

	// pushes a value on top of the stack
	STACK_ERR   push(T val);

	// removes a value from the top of the stack
	STACK_ERR   pop();

	// returns the value on the top of the stack
	T    peek(STACK_ERR& success);

	// peek value from stack using the index. Return success false if out of range, else true
	T peek(int index, STACK_ERR& success);

	int   getStackSize() { return size; };
};

#include "stack.cpp"

#endif
#pragma once
