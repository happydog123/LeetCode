#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
		result=helper(n,k,1);
		return result;
    }

	vector<vector<int>> helper(int n,int k,int begin){
		vector<vector<int>> result;
		if(k==0)
			return result;
		if(k==1){
			for(int i=begin;i<=n;i++){
				vector<int> temp;
				temp.push_back(i);
				result.push_back(temp);
			}
			return result;
		}
		for(int i=begin+1;n-i>=k-2;i++){
			vector<vector<int>> temp1=helper(n,k-1,i);
			for(int j=0;j<temp1.size();j++){
				temp1[j].insert(temp1[j].begin(),i-1);
				result.push_back(temp1[j]);
			}
		}
		return result;
	}
};

int main(){
	int n,k;
	Solution test;
	vector<vector<int>> result;
	while(1){
		cin>>n;
		cin>>k;
		result=test.combine(n,k);
		for(int i=0;i<result.size();i++){
			for(int j=0;j<result[i].size();j++)
				cout<<result[i][j]<<" , ";
			cout<<endl;
		}
	}
}