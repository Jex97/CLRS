#include "common.h"

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
* FindMaxSubArray: Ѱ��һ���������ı������,�����ؿ�����
* A: ����������;
* res: ���ص������������Ϣ;
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
* FindMaxCrossingSubArray: ������Խmid�����������
* A: ��������;
* low: ��ǰ��Ҫ����������������˵�;
* mid: ��ǰ��Ҫ���������������Ҷ˵�;
* high: ��ǰ��Ҫ���������������Ҷ˵�;
* res: ����������������Ϣ;
* ��������: [low, mid]; ��������: [mid+1, high];
*/
void static FindMaxCrossingSubArray(const vector<int>& A, int low, int mid, int high, struct SubArrayInfo& res) {
    // ��֤ low < high
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
* FindMaxSubArray: Ѱ��һ���������������, �����ؿ�����
* A: ��������;
* low: ��ǰ��Ҫ�������������˵�;
* right: ��ǰ��Ҫ������������Ҷ˵�;
* res: ����������������Ϣ;
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