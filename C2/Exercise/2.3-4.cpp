#include "common.h"

using namespace std;
// 插入排序递归版本
// 稳定
// 时间复杂度: O(n^2)

/*
* InertSort: 插入排序;
* v: 待排序的数组;
* k: 下标为k及以前的序列保持有序
*/
void InsertSort(vector<int>& v, int k){
    if(k > 1){
        InsertSort(v,k-1);
        int key = v[k];
        int i = k - 1;
        while(i >= 0 && v[i] < key){
            if(v[i] > key) v[i+1] = v[i];
        }
        v[i+1] = key;
    }
}
