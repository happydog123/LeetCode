#include<iostream>
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
        //zeroEnd�Ƿ�0�ǲ��ֵ�β��������twoEnd�Ƿ�2�ǲ��ֵ��ײ�����
        //����0�ŵ�zeroEnd+1��������2�ŵ�twoEnd-1��������1ָ�����
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
�������Ҫ�ǳ���*/