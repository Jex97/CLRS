#include <iostream>
#include "AlgorithmTest/AlgorithmTest.h"
using namespace std;

void InsertSort(vector<int>& v);
void MergeSort(vector<int>& v);
void BubbleSort(vector<int>& v);
int main() {
	
	SortTest(BubbleSort,1);
	SortTest(InsertSort,2);
	SortTest(MergeSort,3);
	return  0;
}