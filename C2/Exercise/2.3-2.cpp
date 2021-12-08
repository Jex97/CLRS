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
    int ptrL = 0;
    int ptrR = 0;                // 不使用哨兵
    for(int i = l; i <= r; ++i){
      if(ptrL < L.size() && ptrR < R.size()){
          if(L[ptrL] <= R[ptrR]) v[i] = L[ptrL++];
          else v[i] = R[ptrR++];
      }else if(ptrL < L.size()){
          v[i] = L[ptrL++];
      }else{
          v[i] = R[ptrR++];
      }
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
