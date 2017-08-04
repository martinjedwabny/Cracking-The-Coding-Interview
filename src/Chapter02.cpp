/*
 * Chapter02.cpp
 *
 *  Created on: Aug 4, 2017
 *      Author: martinjedwabny
 */

#include "Chapter02.h"

#include <map>
#include <algorithm>
#include <unordered_set>

// DATA STRUCTURE

class node {
public:
	int value;
	node* next;
	node(int v) {value = v; next = nullptr;}
	void removeDuplicates() {
		node* cur = this;
		while (cur->next != nullptr) {
			if (cur->next->value == this->value) {
				cur->next = cur->next->next;
			} else {
				cur = cur->next;
			}
		}
	}
	int size() {
		return next == nullptr ? 1 : 1 + next->size();
	}
	int nthToLast(int n) {
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
	void print() {
		cout << value << " ";
		if (next != nullptr)
			next->print();
	}
};

void testNode(){
	node *n1 = new node(1), *n2 = new node(2), *n3 = new node(1), *n4 = new node(4);
	n1->next = n2; n2->next = n3; n3->next = n4;
	n1->print(); cout << endl;
	n1->removeDuplicates();
	n1->print(); cout << endl;
	cout << n1->nthToLast(1) << endl;
	delete n1; delete n2; delete n3; delete n4;
}

//EXERCISE 1

void removeDuplicatesList(list<int>& l) {
	map<int,int> occurs = map<int,int>();
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		int element = *it;
		if (occurs.count(element) == 0) {
			occurs[element] = 1;
		} else {
			it = l.erase(it);
			it--;
		}
	}
}

void removeDuplicatesList2(list<int>& l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		int e1 = *it;
		list<int>::iterator it2 = it;
		it2++;
		while (it2 != l.end()) {
			int e2 = *it2;
			if (e1 == e2) {
				l.erase(it2);
			}
			it2++;
		}
	}
}

void removeDuplicatesList3(list<int>& l) {
	l.sort();
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		list<int>::iterator nextit = it; nextit++;
		if (nextit != l.end() && *it == *nextit)
			it = l.erase(it);
	}
}

list<int> testList() {
	list<int> testList = list<int>();
	testList.push_back(3);
	testList.push_back(1);
	testList.push_back(2);
	testList.push_back(3);
	testList.push_back(2);
	testList.push_back(1);
	return testList;
}

void testRemoveDuplicatesList() {
	list<int> l = testList();
	removeDuplicatesList3(l);
	for (auto i : l)
		cout << i << " ";
}

//EXERCISE 2

int nthToLast(list<int>& l, int n) {
	if (n-1 > (int)l.size())
		return -1;
	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it) {
		if (n==0)
			return *it;
		n--;
	}
}


void testNthToLast() {
	list<int> l = testList();
	cout << nthToLast(l,5) << " ";
}

//EXERCISE 4

list<int> sumLists(list<int>& l1, list<int>& l2) {
	list<int> sum = list<int>();
	int add = 0;
	list<int>::iterator it1 = l1.begin();
	list<int>::iterator it2 = l2.begin();
	for (int i = 0; i < (int)l1.size(); ++i) {
		int dig = add;
		if (it1 != l1.end()) {
			dig += *it1;
			it1++;
		}
		if (it2 != l2.end()) {
			dig += *it2;
			it2++;
		}
		sum.push_back(dig%10);
		add = dig/10;
	}
	return sum;
}

void testSumList() {
	list<int> l1 = list<int>(); l1.push_back(3); l1.push_back(1); l1.push_back(5); l1.push_back(1);
	list<int> l2 = list<int>(); l2.push_back(5); l2.push_back(9); l2.push_back(4);
	list<int> l3 = sumLists(l1,l2);
	for (auto i : l3)
			cout << i << " ";
}

//EXERCISE 5

int loopBeginList(list<int>& l) {
	unordered_set<int> elems = unordered_set<int>();
	for (int e : l) {
		if (elems.find(e)!=elems.end())
			return e;
		elems.insert(e);
	}
}

void testLoopBeginList() {
	list<int> l1 = list<int>(); l1.push_back(3); l1.push_back(1); l1.push_back(5); l1.push_back(1);
	cout << loopBeginList(l1) << endl;
}

