#include "common.h"

using namespace std;

void static Merge(vector<int>& v, int l, int mid, int r){
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
void static MergeSort(vector<int>& v, int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        MergeSort(v,l,mid);
        MergeSort(v,mid+1,r);
        Merge(v,l,mid,r);
    }
}

/*
* 两数之和: 排序 + 双指针;
* 时间复杂度: O(NlogN);
*/
bool twoSum(vector<int>& v, int x){
    MergeSort(v,0,v.size()-1);
    int l = 0;
    int r = v.size()-1;
    while(l < r){
        if(v[l] + v[r] == x) return true;
        else if(v[l] + v[r] < x) l++;
        else r--;
    }
    return false;
}
