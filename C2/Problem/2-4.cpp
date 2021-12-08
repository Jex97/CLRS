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


// 寻找逆序对数量(树状数组)
// 时间复杂度 O(nlogn);
class BIT{
public:
    vector<int> tree;
    unordered_map<int,int> newID;
    BIT(const vector<int>& v){
        discretize(v);
        tree.resize(newID.size()+1, 0);
    }
    void discretize(const vector<int>& v){
        set<int> st;
        int id = 1;
        for(const auto& x : v) st.insert(x);
        for(const auto& x : st) newID[x] = id++;
    }
    inline int lowbit(int x){
        return x & -x;
    }
    void add(int i, int x){
        i = newID[i];
        for(int pos = i; pos < tree.size(); pos += lowbit(pos)){
            tree[pos] += x;
        }
    }
    int query(int i){
        i = newID[i];
        int ans = 0;
        for(int pos = i; pos > 0; pos -= lowbit(pos)){
            ans += tree[pos];   
        }
        return ans;
    }
};

int CountInversions(const vector<int>& v){
    BIT bit(v);
    int ans = 0;
    for(int i = 0; i < v.size(); ++i){
        bit.add(v[i], 1);
        ans += (i+1 - bit.query(v[i]));
    }
    return ans;
}

