/*
 * Chapter04.cpp
 *
 *  Created on: Aug 9, 2017
 *      Author: martinjedwabny
 */

#include "Chapter04.h"
#include <unordered_map>


void testChapter04() {
	int inorder[7] = {4,2,5,1,6,3,7};
	int preorder[7] = {1,2,4,5,3,6,7};
	Tree<int> t = Tree<int>(preorder, inorder, 7);
	t.print_inorder();
	cout << "\n";
	t.print_preorder();
}

template <typename T>
Tree<T>::Tree(T v) {
	value = v;
	left = right = nullptr;
}

template <typename T>
Tree<T>::~Tree() {
	if (left != nullptr) delete left;
	if (right != nullptr) delete right;
}

template <typename T>
void initialize(Tree<T>& t, T* preorder, T* inorder, int start_preorder, int start_inorder, int n) {
	if (n <= 0) return;
	t.value = preorder[start_preorder];
	t.left = t.right = nullptr;
	if (n == 1) return;
	// inorder = left_inorder + value + right_inorder
	// preorder = value + left_preorder + right_preorder
	int index = 0;
	while (inorder[start_inorder+index] != preorder[start_preorder])
		index++;
	if (index > 0) {
		t.left = new Tree<T>(T());
		initialize(*(t.left), preorder, inorder, start_preorder+1, start_inorder, index);
	}
	if (n-1-index > 0) {
		t.right = new Tree<T>(T());
		initialize(*(t.right), preorder, inorder, start_preorder+index+1, start_inorder+index+1, n-1-index);
	}
}

template <typename T>
Tree<T>::Tree(T* preorder, T* inorder, int n) {
	initialize(*this, preorder, inorder, 0, 0, n);
}

template <typename T>
void Tree<T>::print_inorder() {
	cout << "[";
	if (left != nullptr)
		left->print_inorder();
	cout << "] " << value << " [";
	if (right != nullptr)
			right->print_inorder();
	cout << "]";
}

template <typename T>
void Tree<T>::print_preorder() {
	cout << value << " [";
	if (left != nullptr)
		left->print_preorder();
	cout << "] [";
	if (right != nullptr)
			right->print_preorder();
	cout << "]";
}
