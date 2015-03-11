#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int m=BinarySearch(A,n,target);
		vector<int> result;
		if(m==-1){
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		else{
			int k=m;
			for(int i=m-1;i>=0;i--){
				if(A[i]==target)
					k=i;
			}
			result.push_back(k);
			k=m;
			for(int i=m+1;i<n;i++){
				if(A[i]==target)
					k=i;
			}
			result.push_back(k);
			return result;
		}
    }
	int BinarySearch(int v[],int len,int value){
		if(len<=0)
			return -1;
		int low=0;
		int high=len-1;
		while(low<=high){
			int mid=low+(high-low)/2;
			if(v[mid]==value)
				return mid;
			else if(v[mid]>value)
				high=mid-1;
			else
				low=mid+1;
		}
		return -1;
	}
};

int main(){
	int A[20];
	int n;
	int m;
	Solution test;
	vector<int> result;
	while(1){
		cin>>n;
		cin>>m;
		for(int i=0;i<n;i++)
			cin>>A[i];
		result=test.searchRange(A,n,m);
		cout<<"result is "<<endl;
		cout<<result[0]<<endl;
		cout<<result[1]<<endl;
	}
}