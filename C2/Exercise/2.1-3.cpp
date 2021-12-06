#include"common.h"

using namespace std;
/*
* LinearSearch: 线性查找下标，找不到的返回-1;
* v: 待遍历的序列;
* x: 待查找的元素;
*/
int LinearSearch(const vector<int>& v, int x){
    for(int i = 0; i < v.size(); ++i){
        if(v[i] == x) return i;   
    }
    retutn -1;
}
