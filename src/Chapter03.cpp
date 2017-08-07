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
	testMinStack();
	testSetOfPlates();
	testHanoi();
	testPushBack();
	testSortStack();
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

void testMinStack() {
	min_stack ms = min_stack();
	ms.push(3);
	cout << ms.top() << endl;
	ms.push(2);
	cout << ms.top() << endl;
	ms.push(1);
	cout << ms.top() << endl;
	ms.pop();
	cout << ms.top() << endl;
	ms.pop();
	cout << ms.top() << endl;
}

void testSetOfPlates() {
	set_of_plates sop = set_of_plates(3);
	for (int i = 0; i < 3; ++i) {
		sop.push(1); sop.push(2); sop.push(3);
	}
	cout << sop.top() << endl; //3,2,1 ; 3,2,1 ; 3,2,1
	sop.pop();
	cout << sop.top() << endl; //3,2,1 ; 3,2,1 ; 2,1
	sop.popAt(1);
	cout << sop.top() << endl; //3,2,1 ; 2,1,2 ; 1
	sop.popAt(1);
	cout << sop.top() << endl; //3,2,1 ; 1,2,1
	sop.popAt(1);
	cout << sop.top() << endl; //3,2,1 ; 2,1
	sop.popAt(1);
	cout << sop.top() << endl; //3,2,1 ; 1
	sop.popAt(1);
	cout << sop.top() << endl; //3,2,1
}

void testHanoi() {
	stack ** toh = towerOfHanoi(4);
	for (int i = 0; i < 3; ++i) {
		cout << "stack: ";
		while (toh[i]->size > 0) {
			cout << toh[i]->top() << " ";
			toh[i]->pop();
		}
		cout << endl;
		delete toh[i];
	}
	delete toh;
}

void towerOfHanoiReArrange(stack& origin, stack& auxiliary, stack& target, int n) {
	if (n == 1) {
		target.push(origin.top());
		origin.pop();
	} else {
		towerOfHanoiReArrange(origin, target, auxiliary, n-1);
		target.push(origin.top());
		origin.pop();
		towerOfHanoiReArrange(auxiliary, origin, target, n-1);
	}
}

stack** towerOfHanoi(int n) {
	stack* stack1 = new stack();
	stack* stack2 = new stack();
	stack* stack3 = new stack();
	for (int i = n; i >= 1; --i)
		stack1->push(i);
	towerOfHanoiReArrange(*stack1, *stack2, *stack3, n);
	stack** result = new stack*[3];
	result[0] = stack1; result[1] = stack2; result[2] = stack3;
	return result;
}

void testPushBack() {
	stack s = stack();
	s.push_back(1);
	cout << s.top() << endl;
	s.push_back(2);
	s.pop();
	cout << s.top() << endl;
	s.push_back(3);
	s.pop();
	cout << s.top() << endl;
}

void testSortStack() {
	stack s = stack();
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top() << endl;
	s.sort();
	cout << s.top() << endl;
}

//STACK DATA STRUCTURE

stack::stack() {
	top_node = nullptr;
	size = 0;
}

stack::stack(int* values, int n) {
	//preconditions: values is a int array of size n > 0
	top_node = nullptr;
	size = 0;
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
	size++;
}

void stack::pop() {
	if (top_node != nullptr) {
		stack_node* n = top_node;
		top_node = n->substack;
		delete n;
		size--;
	}
}

int stack::top() {
	return top_node->value;
}

bool stack::empty() {
	return top_node == nullptr;
}

void stack::push_back(int v) {
	stack s = stack();
	while (size > 0) {
		s.push(top());
		pop();
	}
	push(v);
	while (s.size > 0) {
		push(s.top());
		s.pop();
	}
}

void insert_ordered(stack* s, int v) {
	if (s->empty() || s->top() >= v) {
		s->push(v);
	} else {
		int w = s->top();
		s->pop();
		insert_ordered(s, v);
		s->push(w);
	}
}

void stack::sort() {
	if (!empty()) {
		int v = top();
		pop();
		sort();
		insert_ordered(this, v);
	}
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

//MIN STACK DATA STRUCTURE

min_stack::min_stack() {
	values = new stack();
	mins = new stack();
}

min_stack::~min_stack() {
	delete values;
	delete mins;
}

void min_stack::push(int v) {
	values->push(v);
	int min = mins->empty() ? v : mins->top();
	min = min < v ? min : v;
	mins->push(min);
}

void min_stack::pop() {
	values->pop();
	mins->pop();
}

int min_stack::top() {
	return values->top();
}

int min_stack::min() {
	return mins->top();
}

//SET OF PLATES DATA STRUCTURE

set_of_plates::set_of_plates(int t) {
	set = list<stack*>();
	threshold = t;
}

set_of_plates::~set_of_plates() {
	while ((int)set.size() > 0) {
		stack* s = set.front();
		set.pop_front();
		delete s;
	}
}

void set_of_plates::push(plate p) {
	if (set.size() == 0 || set.back()->size == threshold) {
		stack* newstack = new stack();
		set.push_back(newstack);
	}
	set.back()->push(p);
}

void set_of_plates::pop() {
	if (set.size() > 0) {
		set.back()->pop();
		if (set.back()->size == 0)
			set.pop_back();
	}
}

plate set_of_plates::top() {
	return set.back()->top();
}

void set_of_plates::popAt(int index) {
	if (index < 0 || index > set.size() - 1)
		return;
	int i = 0;
	for (list<stack*>::iterator it = set.begin(); it != set.end();) {
		stack* cur = *it;
		if (i == index)
			cur->pop();
		it++;
		if (i >= index && it != set.end()) {
			stack* next = *it;
			if (cur->size < threshold && next->size > 0) {
				vector<int> copy = vector<int>(threshold-1);
				for (int j = 0; j < threshold - 1; j++) {
					copy[j] = cur->top();
//					cout << j << " " << copy[j] << endl;
					cur->pop();
				}
				cur->push(next->top());
				for (int j = threshold-2; j >= 0; j--) {
//					cout << j << " " << copy[j] << endl;
					cur->push(copy[j]);
				}
				next->pop();
			}
		}
		i++;
	}
	if (set.back()->size == 0)
		set.pop_back();
}
