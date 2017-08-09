/*
 * Chapter04.h
 *
 *  Created on: Aug 9, 2017
 *      Author: martinjedwabny
 */

#ifndef CHAPTER04_H_
#define CHAPTER04_H_

#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T>
class Tree{
public:
	T value;
	Tree<T>* left;
	Tree<T>* right;
	Tree(T v);
	~Tree();
	Tree(T* preorder, T* inorder, int n);
	void print_inorder();
	void print_preorder();
};

void testChapter04();

#endif /* CHAPTER04_H_ */
