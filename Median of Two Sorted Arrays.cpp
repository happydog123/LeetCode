#include<iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int middle=(m+n)/2;
		if((m+n)%2==0)
			middle--;
		int a=0,b=0;
		int count=0;
		while(count<middle){
			if(a<m&&b<n){
				if(A[a]<B[b])
					a++;
				else
					b++;
			}
			else if(a<m){
				a++;
			}
			else{
				b++;
			}
			count++;
		}
		if((m+n)%2!=0){
			if(a<m&&b<n){
				if(A[a]<B[b])
					return (double)A[a];
				else
					return (double)B[b];
			}
			else if(a<m){
				return (double)A[a];
			}
			else
				return (double)B[b];
		}
		else{
			double temp1;
			double temp2;
			if(a<m&&b<n){
				if(A[a]<B[b]){
					temp1=(double)A[a];
					a++;
				}
				else{
					temp1=(double)B[b];
					b++;
				}
			}
			else if(a<m){
				temp1=(double)A[a];
				a++;
			}
			else{
				temp1=(double)B[b];
				b++;
			}

			if(a<m&&b<n){
				if(A[a]<B[b])
					temp2=(double)A[a];
				else
					temp2=(double)B[b];
			}
			else if(a<m){
				temp2=(double)A[a];
			}
			else
				temp2=(double)B[b];
			return (double)(temp1+temp2)/2;
		}

    }
};