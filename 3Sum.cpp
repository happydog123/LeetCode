#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
		if(num.size()<3)
			return result;
		sort(num.begin(),num.end());
		for(int i=0;i<=num.size()-3;i++){
			if(num[i]>0)
				break;
			if(i!=0&&num[i]==num[i-1])
				continue;
			vector<vector<int>> temp=twoSum(num,abs(num[i]),i+1);
			for(int k=0;k<temp.size();k++){
				temp[k].insert(temp[k].begin(),num[i]);
				result.push_back(temp[k]);
			}
		}
		return result;
    }
	vector<vector<int>> twoSum(vector<int> &numbers, int target,int begin) {
        vector<vector<int>> result;
		for(int i=begin;i<=numbers.size()-1;i++){
			if(numbers[i]>target)
				break;
			if(i!=begin&&numbers[i]==numbers[i-1])
				continue;
			for(int j=i+1;j<numbers.size();j++){
				if(j!=i+1&&numbers[j]==numbers[j-1])
					continue;
				if(numbers[i]+numbers[j]>target)
					break;
				if(numbers[i]+numbers[j]==target){
					vector<int> temp;
					temp.push_back(numbers[i]);
					temp.push_back(numbers[j]);
					result.push_back(temp);
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
	vector<int> input;
	vector<vector<int>> output;
	Solution test;
	int count;
	while(1){
		cin>>count;
		for(int i=0;i<count;i++){
			int n;
			cin>>n;
			input.push_back(n);
		}
		output=test.threeSum(input);
		cout<<"now print final result"<<endl;
		for(int i=0;i<output.size();i++){
			for(int j=0;j<output[0].size();j++){
				cout<<output[i][j]<<" , ";
			}
			cout<<endl;
		}
	}
	return -1;
}
/*
wrong case: [0,0,0]*/