#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k=k%n;
		if(k==0)
			return;
		vector<int> temp;
		for(int i=n-k;i<n;i++)
			temp.push_back(nums[i]);
		for(int i=n-k-1;i>=0;i--)
			nums[i+k]=nums[i];
		for(int i=0;i<temp.size();i++)
			nums[i]=temp[i];

    }
};