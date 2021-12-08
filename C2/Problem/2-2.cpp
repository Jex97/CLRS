#include "common.h"

using namespace std;

/*
* BubbleSort: 冒泡排序;
* 时间复杂度: O(n^2);
* 空间复杂度: O(1);
* 稳定;
*/
void BubbleSort(vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n; ++i){
        for(int j = n-1; j > i; --j){
            if(v[j] < v[j-1]) swap(v[j], v[j-1]);
        }
    }
}
