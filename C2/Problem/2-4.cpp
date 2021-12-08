#include "common.h"

using namespace std;

// 寻找逆序对的个数(归并排序)
// 时间复杂度: O(nlogn);

int Merge(vector<int>& v, int l, int mid, int r) {
    int ans = 0;
    vector<int> L(v.begin() + l, v.begin() + mid + 1);
    vector<int> R(v.begin() + mid + 1, v.begin() + r + 1);
    int ptrL = 0;
    int ptrR = 0;
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);
    for (int i = l; i <= r; ++i) {
        if (L[ptrL] <= R[ptrR]) v[i] = L[ptrL++];
        else {
            v[i] = R[ptrR++];
            ans += (L.size() - ptrL - 1);
        }
    }
    return ans;
}
int MergeInversions(vector<int>& v, int l, int r) {
    if (l == r) return 0;
    int ans = 0;
    int mid = (l + r) / 2;
    ans += MergeInversions(v, l, mid);
    ans += MergeInversions(v, mid + 1, r);
    ans += Merge(v, l, mid, r);
    return ans;
}
