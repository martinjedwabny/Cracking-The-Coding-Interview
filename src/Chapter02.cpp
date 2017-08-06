/*
 * Chapter02.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: martinjedwabny
 */

#include "Chapter02.h"

#include <algorithm>
#include <unordered_set>

node::node(int v) {
	value = v;
	next = nullptr;
}

node::node(int* v, int n) {
	value = v[0];
	next = nullptr;
	node* cur = this;
	for (int i = 1; i < n; ++i) {
		node* next = new node(v[i]);
		cur->next = next;
		cur = next;
	}
}

node::~node() {
	delete next;
}

int node:: size() {
	return next == nullptr ? 1 : 1 + next->size();
}

void node:: print() {
	cout << value << " ";
	if (next != nullptr)
		next->print();
}

//EXERCISE 1
void node::removeDuplicates() {
	node* first = this;
	while (first != nullptr) {
		node* n = first;
		while (n!= nullptr && n->next != nullptr) {
			if (first->value == n->next->value) {
				node* todelete = n->next;
				n->next = n->next->next;
				todelete->next = nullptr;
				delete todelete;
			}
			n = n->next;
		}
		first = first->next;
	}
}

//EXERCISE 2
int node::nthToLast(int n) {
	int lastIndex = size()-1;
	int index = lastIndex-n;
	if (index <= lastIndex) {
		node* cur = this;
		while (index > 0) {
			cur = cur->next;
			index--;
		}
		return cur->value;
	}
	return -1;
}

//EXERCISE 3
void node::removeFromMiddle() {
	value = next->value;
	node* todelete = next;
	next = next->next;
	todelete->next = nullptr;
	delete todelete;
}

//EXERCISE 4
node* node::sumLists(node* n1) {
	node* n2 = this;
	if (n1 == nullptr && n2 == nullptr)
		return new node(0);
	node *res = nullptr;
	node *cur = nullptr;
	int digit = 0;
	while (n1 != nullptr || n2 != nullptr) {
		if (n1 != nullptr)
			digit += n1->value;
		if (n2 != nullptr)
				digit += n2->value;
		node *nextNode = new node(digit%10);
		digit = digit / 10;
		if (res == nullptr)
			res = nextNode;
		if (cur == nullptr) {
			cur = nextNode;
		} else {
			cur->next = nextNode;
			cur = cur->next;
		}
		if (n1 != nullptr)
			n1 = n1->next;
		if (n2 != nullptr)
			n2 = n2->next;
	}
	return res;
}

//EXERCISE 5
node* node::loopBegin() {
	unordered_set<node*> nodes = unordered_set<node*>();
	nodes.insert(this);
	node* cur = this->next;
	while (cur != this) {
		if (nodes.find(cur) != nodes.end())
			return cur;
		nodes.insert(cur);
		cur = cur->next;
	}
	return nullptr;
}

//TESTS
void testChapter02() {
	testRemoveDuplicatesNode();
	testSumLists();
	testLoopBegin();
}

void testRemoveDuplicatesNode() {
	int values[5] = {1, 2, 1, 4, 2};
	node* n = new node(values, 5);
	n->print(); cout << endl;
	n->removeDuplicates();
	n->print(); cout << endl;
	delete n;
}

void testSumLists() {
	int values1[3] = {3, 1, 5};
	node* n1 = new node(values1, 3);
	int values2[3] = {5, 9, 2};
	node* n2 = new node(values2, 3);
	node* n3 = n1->sumLists(n2);
	n3->print(); cout << endl;
	delete n1; delete n2; delete n3;
}

void testLoopBegin() {
	int values[5] = {1, 2, 1, 4, 2};
	node* n = new node(values, 5);
	n->next->next->next->next->next = n->next->next->next;
	cout << n->loopBegin()->value << endl;
	n->next->next->next->next->next = nullptr;
	delete n;
}
