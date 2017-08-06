/*
 * Chapter03.h
 *
 *  Created on: Aug 6, 2017
 *      Author: martinjedwabny
 */

#ifndef CHAPTER03_H_
#define CHAPTER03_H_

#include <stdio.h>
#include <iostream>

using namespace std;

//STACK DATA STRUCTURE

class stack {
public:
	class stack_node {
	public:
		int value;
		stack_node* substack;
		stack_node(int v, stack_node* s) {value = v; substack = s;}
	};
	stack_node* top_node;
	stack();
	stack(int* values, int n);
	~stack();
	void push(int v);
	void pop();
	int top();
};

//THREE STACK ARRAY DATA STRUCTURE

class three_stack_array {
public:
	int* array;
	int n;
	int* size;
	three_stack_array(int n);
	~three_stack_array();
	bool push(int v, int stack);
	void pop(int stack);
	int top(int stack);
};

//TESTS

void testChapter03();
void testTSA();

#endif /* CHAPTER03_H_ */
