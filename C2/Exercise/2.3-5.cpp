#include "common.h"

using namespace std;

/*
* BinarySearch: 二分查找迭代版本，找不到的返回-1;
* v: 待查找的有序序列; 
* x: 待查找的元素;
*/
int BinarySearch(const vector<int>& v, int x){
    int l = 0;
    int r = v.size()-1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(v[mid] == x) return mid;
        else if(v[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    retutn -1;
}


/*
* BinarySearch: 二分查找递归版本，找不到的返回-1;
* v: 待查找的有序序列; 
* l: 有效序列的开始下标;
* r: 有效序列的结束下标;
* x: 待查找的元素;
*/
int BinarySearch(const vector<int>& v, int l, int r, int x){
    if(l <= r){
        int mid = (l + r) / 2;
        if(v[mid] == x) return mid;
        else if(v[mid] > x) return BinarySearch(v,l,mid-1,x);
        else return BinarySearch(v,mid+1,r,x);
    }
    retutn -1;
}
