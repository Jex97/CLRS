#include "common.h"

using namespace std;

/*
* InsertSort: 实现降序排序
* v: 待排序的数组
*/
void InsertSort(vector<int>& v){
    for(int i = 1; i < v.size(); ++i){
        int key = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = key;
    }
}
