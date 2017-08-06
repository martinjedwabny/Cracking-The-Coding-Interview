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

// DATA STRUCTURE

class node {
public:
	int value;
	node* next;
	node(int v);
	node(int* v, int n);
	~node();
	int size();
	void print();

	//EXERCISES
	void removeDuplicates();
	int nthToLast(int n);
	void removeFromMiddle();
	node* sumLists(node* n1);
	node* loopBegin();
};

//TESTS
void testChapter02();
void testRemoveDuplicatesNode();
void testSumLists();
void testLoopBegin();

#endif /* CHAPTER02_H_ */
