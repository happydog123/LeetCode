#include<iostream>
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
        //zeroEnd是放0那部分的尾部索引，twoEnd是放2那部分的首部索引
        //碰到0放到zeroEnd+1处，碰到2放到twoEnd-1处，碰到1指针后移
        int zeroEnd = -1, twoBegin = n, i = 0;
        while(i < twoBegin)
        {
            if(A[i] == 0 && i != ++zeroEnd)
                swap(A[zeroEnd], A[i]);
            else if(A[i] == 2 && i != --twoBegin)
                swap(A[twoBegin], A[i]);
            else
                i++;
        }
    }
};
/*
这道题需要是抄的*/