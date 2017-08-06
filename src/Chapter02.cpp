/*
 * Chapter02.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: martinjedwabny
 */

#include "Chapter02.h"

#include <algorithm>
#include <unordered_set>

linked_list_node::linked_list_node(int v) {
	value = v;
	next = nullptr;
}

linked_list_node::linked_list_node(int* v, int n) {
	value = v[0];
	next = nullptr;
	linked_list_node* cur = this;
	for (int i = 1; i < n; ++i) {
		linked_list_node* next = new linked_list_node(v[i]);
		cur->next = next;
		cur = next;
	}
}

linked_list_node::~linked_list_node() {
	delete next;
}

int linked_list_node:: size() {
	return next == nullptr ? 1 : 1 + next->size();
}

void linked_list_node:: print() {
	cout << value << " ";
	if (next != nullptr)
		next->print();
}

//EXERCISE 1
void linked_list_node::removeDuplicates() {
	linked_list_node* first = this;
	while (first != nullptr) {
		linked_list_node* n = first;
		while (n!= nullptr && n->next != nullptr) {
			if (first->value == n->next->value) {
				linked_list_node* todelete = n->next;
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
int linked_list_node::nthToLast(int n) {
	int lastIndex = size()-1;
	int index = lastIndex-n;
	if (index <= lastIndex) {
		linked_list_node* cur = this;
		while (index > 0) {
			cur = cur->next;
			index--;
		}
		return cur->value;
	}
	return -1;
}

//EXERCISE 3
void linked_list_node::removeFromMiddle() {
	value = next->value;
	linked_list_node* todelete = next;
	next = next->next;
	todelete->next = nullptr;
	delete todelete;
}

//EXERCISE 4
linked_list_node* linked_list_node::sumLists(linked_list_node* n1) {
	linked_list_node* n2 = this;
	if (n1 == nullptr && n2 == nullptr)
		return new linked_list_node(0);
	linked_list_node *res = nullptr;
	linked_list_node *cur = nullptr;
	int digit = 0;
	while (n1 != nullptr || n2 != nullptr) {
		if (n1 != nullptr)
			digit += n1->value;
		if (n2 != nullptr)
				digit += n2->value;
		linked_list_node *nextNode = new linked_list_node(digit%10);
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
linked_list_node* linked_list_node::loopBegin() {
	unordered_set<linked_list_node*> nodes = unordered_set<linked_list_node*>();
	nodes.insert(this);
	linked_list_node* cur = this->next;
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
	linked_list_node* n = new linked_list_node(values, 5);
	n->print(); cout << endl;
	n->removeDuplicates();
	n->print(); cout << endl;
	delete n;
}

void testSumLists() {
	int values1[3] = {3, 1, 5};
	linked_list_node* n1 = new linked_list_node(values1, 3);
	int values2[3] = {5, 9, 2};
	linked_list_node* n2 = new linked_list_node(values2, 3);
	linked_list_node* n3 = n1->sumLists(n2);
	n3->print(); cout << endl;
	delete n1; delete n2; delete n3;
}

void testLoopBegin() {
	int values[5] = {1, 2, 1, 4, 2};
	linked_list_node* n = new linked_list_node(values, 5);
	n->next->next->next->next->next = n->next->next->next;
	cout << n->loopBegin()->value << endl;
	n->next->next->next->next->next = nullptr;
	delete n;
}
