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
		int count=0;
		while(i<n){
			if(A[i]>b){
				A[p]=A[i];
				b=A[i];
				p++;
				count=0;
			}
			else{
				if(count==0){
					A[p]=A[i];
					b=A[i];
					p++;
					count++;
				}
			}
			i++;
		}
		return p;
    }
};
/*
没写测试用例就通过了*/