/*
 * Chapter04.cpp
 *
 *  Created on: Aug 9, 2017
 *      Author: martinjedwabny
 */

#include "Chapter04.h"

void testChapter04() {
//	test_basic();
//	test_balanced();
	test_is_there_route();
}

void test_basic() {
	int inorder[7] = {4,2,5,1,6,3,7};
	int preorder[7] = {1,2,4,5,3,6,7};
	Tree<int> t = Tree<int>(preorder, inorder, 7);
	t.print_inorder();
	cout << "\n";
	t.print_preorder();
	cout << "\n";
}

void test_balanced() {
	int inorder[7] = {4,2,5,1,6,3,7};
	int preorder[7] = {1,2,4,5,3,6,7};
	Tree<int> t = Tree<int>(preorder, inorder, 7);
	cout << t.balanced() << "\n";
	int inorder2[3] = {1,2,3};
	int preorder2[3] = {3,2,1};
	Tree<int> t2 = Tree<int>(preorder2, inorder2, 3);
	cout << t2.balanced() << "\n";
}

void test_is_there_route() {
	vector< list<int> >adj = vector< list<int> >(4);
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[3].push_back(1);
	adj[2].push_back(1);
	cout << is_there_route(adj, 1, 3) << "\n";
	cout << is_there_route(adj, 3, 1) << "\n";
	cout << is_there_route(adj, 3, 0) << "\n";

	adj = vector< list<int> >(6);
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[0].push_back(3);
	adj[4].push_back(5);
	adj[5].push_back(4);
	cout << is_there_route(adj, 0, 3) << "\n";
	cout << is_there_route(adj, 4, 5) << "\n";
	cout << is_there_route(adj, 0, 5) << "\n";
}

//TREE DATA STRUCTURE

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

//EXERCISE 1

template <typename T>
bool Tree<T>::balanced() {
	int max = max_depth(*this);
	int min = min_depth(*this);
	return max-min <= 1;
}

template <typename T>
int max_depth(Tree<T>& t) {
	if (t.left == nullptr && t.right == nullptr)
		return 0;
	int left = 0;
	if (t.left != nullptr)
		left = 1+max_depth(*(t.left));
	int right = 0;
	if (t.right != nullptr)
		right = 1+max_depth(*(t.right));
	return left > right ? left : right;
}

template <typename T>
int min_depth(Tree<T>& t) {
	if (t.left == nullptr && t.right == nullptr)
		return 0;
	int left = 0;
	if (t.left != nullptr)
		left = 1+min_depth(*(t.left));
	int right = 0;
	if (t.right != nullptr)
		right = 1+min_depth(*(t.right));
	return left < right ? left : right;
}

//EXERCISE 2

bool aux_is_there_route(vector< list<int> >& adj, int i, int j, int n, vector<bool>& visited) {
	if (i == j)
		return true;
	for (int k : adj[i]) {
		if (!visited[k]) {
			visited[k] = true;
			if (aux_is_there_route(adj, k, j, n, visited))
				return true;
		}
	}
	return false;
}

bool is_there_route(vector< list<int> >& adjacency_list, int i, int j) {
	int n = adjacency_list.size();
	vector<bool> visited = vector<bool>(n, false);
	visited[i] = true;
	return aux_is_there_route(adjacency_list, i, j, n, visited);
}
