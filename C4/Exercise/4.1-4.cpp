#include "common.h"

using namespace std;


struct SubArrayInfo {
    int left;              // 子数组的左端点
    int right;             // 子数组的右端点
    int sum;               // 子数组的和
    bool operator<=(const struct SubArrayInfo& _rhs) const {
        return sum <= _rhs.sum;
    }
};
/*
* FindMaxSubArray: 寻找一个最大数组的暴力求解,允许返回空数组
* A: 待求解的数组;
* res: 返回的最大子数组信息;
*/
void static FindMaxSubArray(const vector<int>& A, struct SubArrayInfo& res) {
    int n = A.size();
    int maxSum = 0;
    res.left = res.right = -1;
    res.sum = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += A[j];
            if (sum > maxSum) {
                res.left = i; res.right = j; res.sum = sum;
                maxSum = sum;
            }
        }
    }
}



/*
* FindMaxCrossingSubArray: 搜索跨越mid的最大子数组
* A: 整体数组;
* low: 当前需要处理的左子数组的左端点;
* mid: 当前需要处理的左子数组的右端点;
* high: 当前需要处理的右子数组的右端点;
* res: 返回最大子数组的信息;
* 左子数组: [low, mid]; 右子数组: [mid+1, high];
*/
void static FindMaxCrossingSubArray(const vector<int>& A, int low, int mid, int high, struct SubArrayInfo& res) {
    // 保证 low < high
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; --i) {
        sum += A[i];
        if (sum > leftSum) {
            res.left = i;
            leftSum = sum;
        }
    }
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; ++i) {
        sum += A[i];
        if (sum > rightSum) {
            res.right = i;
            rightSum = sum;
        }
    }
    res.sum = (rightSum + leftSum);
}

/*
* FindMaxSubArray: 寻找一个最大连续子数组, 允许返回空数组
* A: 整体数组;
* low: 当前需要处理的子数组左端点;
* right: 当前需要处理的子数组右端点;
* res: 返回最大子数组的信息;
*/

void static FindMaxSubArray(const vector<int>& A, int low, int high, struct SubArrayInfo& res) {
    if (low == high) {
        if (A[low] > 0) {
            res.left = res.right = low;
            res.sum = A[low];
        }
        else {
            res.left = res.right = -1;
            res.sum = 0;
        }
            
        return;
    }
    int mid = (low + high) / 2;
    struct SubArrayInfo leftmaxsub, rightmaxsub, crossmaxsub;

    FindMaxSubArray(A, low, mid, leftmaxsub);
    FindMaxSubArray(A, mid + 1, high, rightmaxsub);
    FindMaxCrossingSubArray(A, low, mid, high, crossmaxsub);

    if (leftmaxsub <= crossmaxsub && rightmaxsub <= crossmaxsub) res = crossmaxsub;
    else if (crossmaxsub <= leftmaxsub && rightmaxsub <= leftmaxsub) res = leftmaxsub;
    else res = rightmaxsub;
}