/*
 * Chapter03.cpp
 *
 *  Created on: Aug 6, 2017
 *      Author: martinjedwabny
 */

#include "Chapter03.h"

//TESTS

void testChapter03() {
	testTSA();
}

void testTSA() {
	three_stack_array tsa = three_stack_array(3);
	tsa.push(1,0);
	tsa.push(2,0);
	tsa.push(3,1);
	tsa.push(4,2);
	tsa.push(5,2);
	tsa.push(6,2);
	cout << tsa.top(0) << endl;
	cout << tsa.top(1) << endl;
	cout << tsa.top(2) << endl;
	tsa.pop(0); tsa.pop(1); tsa.pop(2);
	cout << tsa.top(0) << endl;
	cout << tsa.top(1) << endl;
	cout << tsa.top(2) << endl;
	tsa.pop(0); tsa.pop(1); tsa.pop(2);
	cout << tsa.top(0) << endl;
	cout << tsa.top(1) << endl;
	cout << tsa.top(2) << endl;
	tsa.pop(0); tsa.pop(1); tsa.pop(2);
}

//STACK DATA STRUCTURE

stack::stack() {
	top_node = nullptr;
}

stack::stack(int* values, int n) {
	//preconditions: values is a int array of size n > 0
	top_node = nullptr;
	for (int i = n-1; i >= 0; --i)
		push(values[i]);
}

stack::~stack() {
	while (top_node != nullptr)
		pop();
}

void stack::push(int v) {
	stack_node* n = new stack_node(v, top_node);
	top_node = n;
}

void stack::pop() {
	if (top_node != nullptr) {
		stack_node* n = top_node;
		top_node = n->substack;
		delete n;
	}
}

int stack::top() {
	return top_node->value;
}

//THREE STACK ARRAY DATA STRUCTURE
three_stack_array::three_stack_array(int n) {
	array = new int[3 * n];
	this->n = n;
	size = new int[3];
	size[0] = size[1] = size[2] = 0;
}

three_stack_array::~three_stack_array() {
	delete array;
}

bool three_stack_array::push(int v, int stack) {
	if (size[stack] >= n)
		return false;
	array[n * stack + size[stack]] = v;
	size[stack]++;
	return true;
}

void three_stack_array::pop(int stack) {
	if (size[stack] == 0)
		return;
	size[stack]--;
}

int three_stack_array::top(int stack) {
	int index = n * stack + size[stack] - 1;
	if (size[stack]==0)
		return -1;
	return array[index];
}
