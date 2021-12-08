#include "common.h"

using namespace std;
// 二分插入排序
// 稳定
// 时间复杂度: O(n^2)
// 空间复杂度: O(1)


/*
* BinaryInertSort: 插入排序;
* v: 待排序的数组;
*/
void BinaryInertSort(vector<int>& v){
    for(int i = 1; i < v.size(); ++i){
        int key = v[i];
        int l = 0;
        int r = i-1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(v[mid] <= key)  l = mid + 1;
            else r = mid + 1;
        }
        for(int j = i; j > l; --j) v[j] = v[j-1];
        v[l] = key;
    }
}
