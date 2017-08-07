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
#include <list>
#include <vector>

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
	int size;
	stack();
	stack(int* values, int n);
	~stack();
	void push(int v);
	void pop();
	int top();
	bool empty();
	void push_back(int v); //O(n)
	void sort();
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

//MIN STACK DATA STRUCTURE

class min_stack {
public:
	stack* values;
	stack* mins;
	min_stack();
	~min_stack();
	void push(int v);
	void pop();
	int top();
	int min();
};

// SET OF PLATES DATA STRUCTURE

typedef int plate;

class set_of_plates {
public:
	list<stack*> set;
	int threshold;
	set_of_plates(int t);
	~set_of_plates();
	void push(plate p);
	void pop();
	plate top();
	void popAt(int index);
};

//TESTS

void testChapter03();
void testTSA();
void testMinStack();
void testSetOfPlates();
void testHanoi();
void testPushBack();
void testSortStack();

stack** towerOfHanoi(int n);

#endif /* CHAPTER03_H_ */
