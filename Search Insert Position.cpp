#include<iostream>
using namespace std;
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n<=0)
			return -1;
		int low=0;
		int high=n-1;
		while(low<=high){
			int mid=low+(high-low)/2;
			if(A[mid]==target)
				return mid;
			else if(A[mid]>target)
				high=mid-1;
			else
				low=mid+1;
		}
		return high+1;
    }
};
int main(){
	int A[20];
	int n;
	int m;
	Solution test;
	while(1){
		cin>>n;
		cin>>m;
		for(int i=0;i<n;i++)
			cin>>A[i];
		cout<<test.searchInsert(A,n,m)<<endl;
	}
}