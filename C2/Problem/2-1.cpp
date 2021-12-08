#include "common.h"

using namespace std;

// 归并排序，规模小时使用插入排序
const int MinLength = 5;

void InsertSort(vector<int>& v, int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= l && v[j] > key) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = key;
    }
}
void Merge(vector<int>& v, int l, int mid, int r) {
    vector<int> L(v.begin() + l, v.begin() + mid + 1);
    vector<int> R(v.begin() + mid + 1, v.begin() + r + 1);
    L.push_back(INT_MAX);                            //引入哨兵，简化编程。 注意添加的元素必须严格大于数组中的所有元素；
    R.push_back(INT_MAX);
    int ptrL = 0;
    int ptrR = 0;
    for (int i = l; i <= r; ++i) {
        if (L[ptrL] <= R[ptrR]) v[i] = L[ptrL++];
        else v[i] = R[ptrR++];
    }
}
void MergeInsertSort(vector<int>& v, int l, int r) {
    if (r - l + 1 >= MinLength) {
        int mid = (l + r) / 2;
        MergeInsertSort(v, l, mid);
        MergeInsertSort(v, mid + 1, r);
        Merge(v, l, mid, r);
    }
    else {
        InsertSort(v, l, r);
    }
}
