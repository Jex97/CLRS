#include " common.h"

using namespaces std;

/*
* SelectionSort: 选择排序;
* v: 待排序的序列;
*/
void SelectionSort(vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n; ++i){
        int id = i;
        for(int j = i+1; j < n; ++j){
            if(v[j] < v[id]){
                id = j;
            }
        }
        swap(v[i], v[id]);
    }
}
