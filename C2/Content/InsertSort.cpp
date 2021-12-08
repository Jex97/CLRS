#include "common.h"

using namespace std;
// 插入排序
// 稳定
// 时间复杂度: O(n^2)
// 空间复杂度: O(1)


/*
* InertSort: 插入排序;
* v: 待排序的数组;
*/
void InsertSort(vector<int>& v){
    for(int i = 1; i < v.size(); ++i){
        int key = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] < key){
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = key;
    }
}
