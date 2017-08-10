/*
 * Chapter04.cpp
 *
 *  Created on: Aug 9, 2017
 *      Author: martinjedwabny
 */

#include "Chapter04.h"
#include <stack>
#include <unordered_map>

void testChapter04() {
//	test_basic();
//	test_balanced();
//	test_is_there_route();
//	test_min_height_tree();
//	test_group_by_depth();
	test_next_tree_node();
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

void test_min_height_tree() {
	int array[5] = {1,2,3,4,5};
	Tree<int>* t = create_minimum_height_tree(array, 5);
	t->print_inorder(); cout << "\n";
	delete t;
}

void test_group_by_depth() {
	int array[5] = {1,2,3,4,5};
	Tree<int>* t = create_minimum_height_tree(array, 5);
	vector<list <Tree<int>* > > vlt = group_by_depth(t);
	int depth = 0;
	for (auto l : vlt) {
		cout << "depth " << depth <<": ";
		for (auto t : l)
			cout << t->value << " ";
		depth++;
		cout << "\n";
	}
	delete t;
}

void test_next_tree_node() {
	int array[5] = {1,2,3,4,5};
	Tree<int>* t = create_minimum_height_tree(array, 5);
	Tree<int>* succ = next_tree_node(t, t->right);
	cout << succ->value << "\n";
	delete t;
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

//EXERCISE 3

Tree<int>* create_minimum_height_tree(int* array, int n) {
	Tree<int>* res = new Tree<int>(array[0]);
	int h = n / 2;
	if (h > 0)
		res->left = create_minimum_height_tree(array+1, h);
	if (n-h-1 > 0)
		res->right = create_minimum_height_tree(array+h+1, n-h-1);
	return res;
}

//EXERCISE 4

vector< list< Tree<int>* > >group_by_depth(Tree<int>* t) {
	vector< list< Tree<int>* > > res = vector< list< Tree<int>* > >(max_depth(*t));
	res.push_back(list< Tree<int>* >());
	res[0].push_back(t);
	int depth = 1;
	while ((int)(res[depth-1].size()) > 0) {
		for (Tree<int>* t : res[depth-1]) {
			if (t->left != nullptr)
				res[depth].push_back(t->left);
			if (t->right != nullptr)
				res[depth].push_back(t->right);
		}
		depth++;
	}
	return res;
}

//EXERCISE 5

bool is_leaf(Tree<int> node) {
	return node.left != nullptr || node.right != nullptr;
}

Tree<int>* next_tree_node(Tree<int>* root, Tree<int>* node) {
	stack< Tree<int>* > dfs = stack< Tree<int>* >();
	unordered_map< Tree<int>*, int > visited = unordered_map< Tree<int>*, int >();
	dfs.push(root);
	bool found = false;
	while ((int)dfs.size() > 0) {
		Tree<int>* current = dfs.top(); dfs.pop();
		if (found && visited[current] == 0)
			return current;
		visited[current] = 1;
		if (current == node)
			found = true;
		if (current->right != nullptr && visited[current->right] == 0)
			dfs.push(current->right);
		if (current->left != nullptr && visited[current->left] == 0)
			dfs.push(current->left);
	}
	return nullptr;
}
