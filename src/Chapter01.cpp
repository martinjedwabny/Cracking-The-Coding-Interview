/*
 * Chapter01.cpp
 *
 *  Created on: Aug 3, 2017
 *      Author: martinjedwabny
 */

#include "Chapter01.h"

//EXERCISE 1

bool hasUniqueCharacters(string s) {
	if (s.size() > 256)
		return false;
	bool appears[256] = { 0 };
	for (char c : s) {
		if (appears[c])
			return false;
		appears[c] = true;
	}
	return true;
}

void testHasUniqueCharacters() {
	string test_string[6] = {"hola", "aaa", "", "hello", "1234567890", "123456789012345678901234567890"};
	bool test_res[6] = {true,false,true,false,true,false};
	for (int i = 0; i < 6; ++i)
		cout << (hasUniqueCharacters(test_string[i])==test_res[i]) << endl;
}

//EXERCISE 2

void reverseString(char* str) {
	int length = strlen(str);//not counting last pointer
	int middle = length / 2;
	for (int i = 0; i < middle; ++i) {
		char tmp = str[length-i-1];
		str[length-i-1] = str[i];
		str[i] = tmp;
	}
}

void testReverseString() {
	string test_strings[4] = {"hola", "", "aaaaddaaaa", "qweds"};
	for (int i = 0; i < 4; ++i) {
		string s = test_strings[i];
		char* cstr = new char[s.length()+1];
		strcpy(cstr, s.c_str());//const copy
		reverseString(cstr);
		cout << cstr << endl;
	}
}

//EXERCISE 3

void removeDuplicates(string& s) {
	int index = 0;
	for (int cur = 0; cur < s.length(); ++cur) {
		bool duplicate = false;
		for (int goback = cur-1; goback >= 0; --goback) {
			if (s[cur]==s[goback]) {
				duplicate = true;
				break;
			}
		}
		if (!duplicate) {
			s[index] = s[cur];
			index++;
		}
	}
	while (index < s.length()) {
		s[index] = ' ';
		index++;
	}
}

void testRemoveDuplicates() {
	string test_strings[5] = {"asddsa", "1111111", "", "assa", "afa"};
	for (int i = 0; i < 5; ++i) {
		string s = test_strings[i];
		removeDuplicates(s);
		cout << s << endl;
	}
}

//EXERCISE 4

bool anagrams(string s1, string s2) {
	if (s1.length() != s2.length())
		return false;
	int letters[256] = { 0 };
	for (char c : s1)
		letters[(int)c]++;
	for (char c : s2)
		letters[(int)c]--;
	for (int i = 0; i < 256; ++i) {
		if (letters[i]!=0)
			return false;
	}
	return true;
}

void testAnagrams() {
	string test_s1[5] = {"hola", "asdasdasd", "aaa", "", "asd"};
	string test_s2[5] = {"aloh", "dsadsadsa", "aab", "", "bb"};
	for (int i = 0; i < 5; ++i) {
		cout << anagrams(test_s1[i], test_s2[i]) << endl;
	}
}

//EXERCISE 5

bool replaceSpaces(string& s) {
	int countSpaces = 0;
	for (char c : s)
		countSpaces = c == ' ' ? countSpaces+1 : countSpaces;
	int indexOriginal = s.length()-1;
	s.resize(s.length()+countSpaces*2);
	int indexNew = s.length()-1;
	while (indexOriginal >= 0) {
		if (s[indexOriginal]==' ') {
			s[indexNew] = '0';s[indexNew-1] = '2';s[indexNew-2] = '%';
			indexNew -= 3;
		} else {
			s[indexNew] = s[indexOriginal];
			indexNew --;
		}
		indexOriginal--;
	}
}

void testReplaceSpaces() {
	string s = "this is an interview";
	cout << s << endl;
	replaceSpaces(s);
	cout << s << endl;
}

//EXERCISE 6

void printMatrix(vector< vector<int> >& vec) {
	for (int i = 0; i < vec.size(); i++){
		for (int j = 0; j < vec[0].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

vector< vector<int> > matrixToVector(int* matrix, int n, int m) {
	vector< vector<int> > vec = vector< vector<int> >(n, vector<int>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			vec[i][j] = matrix[i * n + j];
		}
	}
	return vec;
}

void swapFour(vector< vector<int> >& vec, int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
	int tmp = vec[xd][yd];
	vec[xd][yd] = vec[xc][yc];
	vec[xc][yc] = vec[xb][yb];
	vec[xb][yb] = vec[xa][ya];
	vec[xa][ya] = tmp;
}

void rotate90(vector< vector<int> >& vec) {
	int n = vec.size();
	for (int row = 0; row < n/2; row++) {
		for (int col = row; col < n-1-row; col++) {
			swapFour(vec,
					row,col,
					col,n-1-row,
					n-1-row,n-1-col,
					n-1-col,row);
		}
	}
}

void testRotate90(){
	vector< vector<int> > vec = vector< vector<int> >(3, vector<int>(3, 1));
	vec[0][0] = 1; vec[0][1] = 2; vec[0][2] = 3;
	vec[1][0] = 4; vec[1][1] = 5; vec[1][2] = 6;
	vec[2][0] = 7; vec[2][1] = 8; vec[2][2] = 9;
	rotate90(vec);
	printMatrix(vec);
	int matrix[5][5] ={{ 1,  2,  3,  4,  5},
	                   { 6,  7,  8,  9, 10},
	                   {11, 12, 13, 14, 15},
	                   {16, 17, 18, 19, 20},
	                   {21, 22, 23, 24, 25}};
	vec = matrixToVector((int*)matrix, 5, 5);
	rotate90(vec);
	printMatrix(vec);
}

//EXERCISE 7

void zeroRowsAndCols(vector< vector<int> >& matrix) {
	int n = matrix.size();
	if (n == 0)
		return;
	int m = matrix[0].size();
	if (m == 0)
		return;
	vector<bool> rows = vector<bool>(n, 0);
	vector<bool> cols = vector<bool>(m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] == 0) {
				rows[i] = true;
				cols[j] = true;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (rows[i]||cols[j])
				matrix[i][j] = 0;
		}
	}
}

void testZeroAndCols() {
	int matrix[5][5] ={{    1, 0, 3, 4, 5},
		                   {6, 7, 8, 9, 1},
		                   {1, 1, 3, 4, 5},
		                   {1, 1, 8, 9, 2},
		                   {1, 2, 3, 4, 5}};
	vector< vector<int> > vec = matrixToVector((int*)matrix, 5, 5);
	zeroRowsAndCols(vec);
	printMatrix(vec);
}

//EXERCISE 8

bool isSubstring(string s1, string s2) {
	for (int i = 0; i < s2.length()-s1.length()+1; ++i) {
		bool res = true;
		for (int j = 0; j < s1.length(); ++j) {
			if (s1[j]!=s2[i+j]) {
				res = false;
				break;
			}
		}
		if (res)
			return true;
	}
	return false;
}

bool isRotation(string s1, string s2) {
	if (s1.length()!=s2.length())
		return false;
	string s1dup = s1+s1;
	return isSubstring(s2,s1dup);
}

void testRotation(){
	cout << isRotation("asdas", "dasas");
}
