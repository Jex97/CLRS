#include "common.h"

using namespace std;

/*
* HornerRule: 霍纳规则，多项式求值;
* y = a_0 * x^0 + a_1 * x^1 + ... + a_n * x^n;
* x: 未知数;
* a: 已知系数向量;
* y: 求和结果;
*/
int HornerRule(int x, const vector<int>& a){
    int n = a.size();
    int y = 0;
    for(int i = n-1; i >= 0; ++i){
         y = a[i] + x*y;
    }
    return y;
}
