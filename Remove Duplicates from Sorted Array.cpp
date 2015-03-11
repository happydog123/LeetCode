#include<iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0||n==1)
			return n;
		int p=1;
		int i=1;
		int b=A[0];
		int length=n;
		while(i<n){
			if(A[i]>b){
				A[p]=A[i];
				b=A[i];
				p++;
			}
			i++;
		}
		return p;
    }
};
/*
没写测试用例就通过了*/