#include<iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int l=0;
		int r=n-1;
		while(l<=r){
			int m=(l+r)/2;
			if(target==A[m])
				return m;
			if(A[m]<A[r]){
				if(target>A[m]&&target<=A[r])
					l=m+1;
				else
					r=m-1;
			}
			else{
				if(target>=A[l]&&target<A[m])
					r=m-1;
				else
					l=m+1;
			}
		}
		return -1;
    }
};

int main(){
	int A[20];
	int n;
	int find;
	Solution test;
	while(1){
		cin>>n;
		cin>>find;
		for(int i=0;i<n;i++)
			cin>>A[i];
		cout<<test.search(A,n,find)<<endl;
	}
}