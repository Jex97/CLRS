#include "AlgorithmTest.h"

#include<algorithm>
#include<ctime>

#define GET_VARIABLE_NAME(Variable) (#Variable)

using namespace std;
void SortTest(void (*SortMethod) (std::vector<int>& v), int TestRank) {
	
	vector<int> TestSizes{ 100,1000,10000, 100000};
	
	if (TestRank >= TestSizes.size()) {
		cout << "Error: TestRank must less than " << TestSizes.size() << "!" <<endl;
		return;
	}
	srand((unsigned)time(NULL));
	for (int i = 0; i <= TestRank; ++i) {
		bool success = true;

		// 初始化待排序数组 
		vector<int> v1(TestSizes[i]);
		vector<int> v2(TestSizes[i]);
		for (int j = 0; j < TestSizes[i]; ++j) {
			v1[j] = rand() % INT_MAX;
			v2[j] = rand() % TestSizes[i];
		}
		vector<int> v1ans(v1);
		vector<int> v2ans(v2);
		sort(v1ans.begin(), v1ans.end());
		sort(v2ans.begin(), v2ans.end());

		clock_t st, ed;
		st = clock();
		SortMethod(v1);
		SortMethod(v2);
		ed = clock();
		success = (v1 == v1ans) && (v2 == v2ans);
		cout << "------------------------------------" << endl;
		cout << "TestSizes = " << TestSizes[i] << ": " << endl;
		cout << "SortResult: ";
		success ? (cout << "true") : (cout << "false");
		cout << endl;
		cout << "CostTime: " << (ed - st) << "ms" << endl;
		
	}
	cout << endl;
}