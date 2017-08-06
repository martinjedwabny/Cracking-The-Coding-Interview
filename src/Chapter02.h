/*
 * Chapter02.h
 *
 *  Created on: Aug 4, 2017
 *      Author: martinjedwabny
 */

#ifndef CHAPTER02_H_
#define CHAPTER02_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

// LINKED LIST DATA STRUCTURE

class linked_list_node {
public:
	int value;
	linked_list_node* next;
	linked_list_node(int v);
	linked_list_node(int* v, int n);
	~linked_list_node();
	int size();
	void print();

	//EXERCISES
	void removeDuplicates();
	int nthToLast(int n);
	void removeFromMiddle();
	linked_list_node* sumLists(linked_list_node* n1);
	linked_list_node* loopBegin();
};

//TESTS
void testChapter02();
void testRemoveDuplicatesNode();
void testSumLists();
void testLoopBegin();

#endif /* CHAPTER02_H_ */
