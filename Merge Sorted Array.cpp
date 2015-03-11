#include<iostream>
using namespace std;
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
		int idx1=m-1;
		int idx2=n-1;
		int len=m+n-1;
		while(idx1>=0&&idx2>=0){
			if(A[idx1]>B[idx2])
				A[len--]=A[idx1--];
			else
				A[len--]=B[idx2--];
		}
		while(idx2>=0)
			A[len--]=B[idx2--];
    }
};

