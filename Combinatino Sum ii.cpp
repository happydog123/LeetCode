#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		vector<vector<int>> result;
		sort(candidates.begin(),candidates.end());
		result=helper(candidates,target,0);
		return result;
    }

	vector<vector<int>> helper(vector<int> &candidates,int sum,int begin){
		vector<vector<int>> result;
		if(sum<=0||begin>=candidates.size())
			return result;
		for(int i=begin;i<candidates.size();i++){
			if(i==begin||(i!=begin&&candidates[i]!=candidates[i-1])){
				if(candidates[i]>sum){
					return result;
				}
				else if(candidates[i]==sum){
					vector<int> temp;
					temp.push_back(candidates[i]);
					result.push_back(temp);
					return result;
				}
				else if(candidates[i]<sum){
					vector<vector<int>> temp;
					temp=helper(candidates,sum-candidates[i],i+1);
					for(int j=0;j<temp.size();j++){
						temp[j].insert(temp[j].begin(),candidates[i]);
						result.push_back(temp[j]);
					}
				}
			}
		}
		return result;
	}
};

vector<int> getInt(string buf){
	vector<int> num;
	int temp=0;
	char c;
	for(int i=0;i!=buf.size();i++){
		if(buf[i]!=','){
			c=buf.at(i);
			temp=temp*10+atoi(&c);
		}
		else{
			num.push_back(temp);
			temp=0;
		}
	}
	num.push_back(temp);
	return num;
}

vector<int> setdata(){
	string temp;
	cin>>temp;
	return getInt(temp);
}

int main(){
	int target;
	Solution test;
	vector<int> input;
	vector<vector<int>> output;
	while(1){
		input=setdata();
		cin>>target;
		output=test.combinationSum2(input,target);
		for(int i=0;i<output.size();i++){
			for(int j=0;j<output[i].size();j++)
				cout<<output[i][j]<<" , ";
			cout<<endl;
		}
	}
	return 0;
}