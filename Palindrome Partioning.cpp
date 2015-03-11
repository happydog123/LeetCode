#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
		const int len=s.size();
		vector<vector<string>> result;
		if(len<=1){
			vector<string> temp;
			temp.push_back(s);
			result.push_back(temp);
			return result;
		}
		vector<vector<bool>> dp;
		for(int i=0;i<len;i++){
			vector<bool> temp;
			for(int j=0;j<len;j++)
				temp.push_back(false);
			dp.push_back(temp);
		}
		dp[0][0]=true;
		for(int i=1;i<len;i++){
			dp[i][i]=true;
			dp[i][i-1]=true;
		}
		for(int k=2;k<=len;k++){
			for(int i=0;i<=len-k;i++){
				if(s[i]==s[i+k-1]&&dp[i+1][i+k-2])
					dp[i][i+k-1]=true;
			}
		}
		result=helper(s,dp,0,len-1);
    }
	vector<vector<string>> helper(string s,vector<vector<bool>> dp,int begin,int end){
		if(begin>end){
			vector<vector<string>> result;
			return result;
		}
		if(begin==end){
			vector<string> temp;
			temp.push_back(s.substr(begin,1));
			vector<vector<string>> result;
			result.push_back(temp);
		}
		vector<vector<string>> result;
		for(int k=0;k<=end-begin;k++){
			if(dp[begin][begin+k]){
				vector<vector<string>> temp=helper(s,dp,begin+k+1,end);
				for(int i=0;i<temp.size();i++){
					temp[i].insert(temp[i].begin(),s.substr(begin,k));
					result.push_back(temp[i]);
				}
			}
		}
		return result;
	}
};

int main(){
	string input;
	vector<vector<string>> result;
	Solution test;
	while(1){
		cin>>input;
		result=test.partition(input);
		for(int i=0;i<result.size();i++){
			for(int j=0;j<result[i].size();j++)
				cout<<result[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}