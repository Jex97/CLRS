#include "common.h"

using namespace std;
/*
* add: 将两个n位二进制并保存在n位数组中的数进行加操作，并保存于n+1位数组;
* v1: 待加的第一个数组;
* v2: 待加的第二个数组;
* v: 加法的结果
*/
void add(const vector<int>& v1, const vector<int>& v2, vector<int>& v){
    int n = v1.size();
    v.resize(n + 1, 0);
    int c = 0;
    for(int i = n-1; i >= 0; --i){
        v[i+1] = (v1[i] + v2[i] + c) % 2;
        c = (v1[i] + v2[i] + c) / 2;
    }
    v[0] = c;
}
