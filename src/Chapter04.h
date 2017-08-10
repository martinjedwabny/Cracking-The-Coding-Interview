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
#include <queue>

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
	bool balanced();
};

bool is_there_route(vector< list<int> >& adjacency_list, int i, int j);
Tree<int>* create_minimum_height_tree(int* array, int n);
vector< list< Tree<int>* > >group_by_depth(Tree<int>* t);
Tree<int>* next_tree_node(Tree<int>* root, Tree<int>* node);

void testChapter04();
void test_basic();
void test_balanced();
void test_is_there_route();
void test_min_height_tree();
void test_group_by_depth();
void test_next_tree_node();

#endif /* CHAPTER04_H_ */
