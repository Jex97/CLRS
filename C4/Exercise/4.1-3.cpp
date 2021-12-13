#include "common.h"

using namespace std;

/*
* FindMaxSubArray: 寻找一个最大数组的暴力求解;  
* 时间复杂度: O(n^2);
* 空间复杂度: O(1);
* 递归解法见 https://github.com/Jex97/CLRS/blob/main/C4/Content/FindMaxSubArray.cpp;
*/


/*
* SubArrayInfo: 记录子数组的信息
*/
struct SubArrayInfo{
    int left;              // 子数组的左端点
    int right;             // 子数组的右端点
    int sum;               // 子数组的和
    bool operator<=(const struct SubArrayInfo& _rhs) const{
        return sum <= _rhs.sum;
    }
};
/*
* FindMaxSubArray: 寻找一个最大数组的暴力求解;  
* A: 待求解的数组;
* res: 返回的最大子数组信息;
*/
void FindMaxSubArray(const vector<int>& A, struct SubArrayInfo& res){
    int n = A.size();
    int maxSum = INT_MIN;
    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = i; j < n; ++j){
            sum += A[j];
            if(sum > maxSum){
                res.left = i; res.right = j; res.sum = sum;
                maxSum = sum;
            }
        }
    }
}
