#include"common.h"
using namespace std;

struct SubArrayInfo {
    int left;              // ���������˵�
    int right;             // ��������Ҷ˵�
    int sum;               // ������ĺ�
    bool operator<=(const struct SubArrayInfo& _rhs) const {
        return sum <= _rhs.sum;
    }
};

/*
*/

void static FindMaxSubArray(const vector<int>& A, SubArrayInfo& res) {
    int n = A.size();
    res.left = res.right = -1;
    res.sum = 0;
    int pre = -1;
    int left = -1;
    for (int i = 0; i < n; ++i) {
        if (pre <= 0) {
            pre = A[i];
            left = i;
        }
        else {
            pre = A[i] + pre;
        }
        if (pre > res.sum) {
            res.left = left;
            res.right = i;
            res.sum = pre;
        }
    }
}