/*
 * Chapter01.h
 *
 *  Created on: Aug 3, 2017
 *      Author: martinjedwabny
 */

#ifndef CHAPTER01_H_
#define CHAPTER01_H_

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

bool hasUniqueCharacters(string s);
void testHasUniqueCharacters();

void reverseString(char* str);
void testReverseString();

void removeDuplicates(string& s);
void testRemoveDuplicates();

bool anagrams(string s1, string s2);
void testAnagrams();

bool replaceSpaces(string& s);
void testReplaceSpaces();

void rotate90(vector< vector<int> >& vec);
void testRotate90();

void zeroRowsAndCols(vector< vector<int> >& matrix);
void testZeroAndCols();

void testRotation();

#endif /* CHAPTER01_H_ */
