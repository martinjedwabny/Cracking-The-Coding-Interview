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

void removeDuplicatesList(list<int>& l);
void removeDuplicatesList2(list<int>& l);
void removeDuplicatesList3(list<int>& l);
void testRemoveDuplicatesList();

int nthToLast(list<int>& l, int n);
void testNthToLast();

list<int> sumLists(list<int>& l1, list<int>& l2);
void testSumList();

int loopBeginList(list<int>& l);
void testLoopBeginList();

void testNode();

#endif /* CHAPTER02_H_ */
