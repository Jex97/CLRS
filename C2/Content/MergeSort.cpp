#include "common.h"

using namespace std;
// 归并排序
// Merge函数决定其稳定性
// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)


/*
* Merge: 将前后两段有序的序列合并为一个有序序列；
* v: 待合并的数组;
* l: 第一个数组的开始下标;
* mid: 第一个数组的结束下标;
* r: 第二个数组的结束下标;
* 注意：此处保证(l < r)
*/
void Merge(vector<int>& v, int l, int mid, int r){
    vector<int> L(v.begin()+l, v.begin()+mid+1);
    vector<int> R(v.begin()+mid+1, v.begin()+r+1);
    L.push_back(INT_MAX);                            //引入哨兵，简化编程。 注意添加的元素必须严格大于数组中的所有元素；
    R.push_back(INT_MAX);
    int ptrL = 0;
    int ptrR = 0;
    for(int i = l; i <= r; ++i){
        if(L[ptrL] <= R[ptrR]) v[i] = L[ptrL++];
        else v[i] = R[ptrR++];
    }
}

/*
* MergeSort: 归并排序;
* v: 待排序的数组，[l,r];
* l: 待排序数组的开始下标
* r: 待排序数组的结束下标;
*/
void MergeSort(vector<int>& v, int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        MergeSort(v,l,mid);
        MergeSort(v,mid+1,r);
        Merge(v,l,mid,r);
    }
}
