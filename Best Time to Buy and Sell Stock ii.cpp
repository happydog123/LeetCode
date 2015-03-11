#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size()==0||prices.size()==1)
			return 0;
		if(prices.size()==2){
			if(prices[0]>=prices[1])
				return 0;
			else
				return prices[1]-prices[0];
		}
		int profit=0;
		int begin=prices[0];
		int end=prices[0];
		for(int i=1;i<prices.size();i++){
			if(prices[i]>=prices[i-1]){
				end=prices[i];
				if(i==prices.size()-1)
					profit=profit+end-begin;
			}
			else{
				profit=profit+end-begin;
				begin=prices[i];
				end=prices[i];
			}
		}
		if(profit<=0)
			profit=0;
		return profit;
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
	Solution test;
	while(1){
		input=setdata();
		cout<<test.maxProfit(input)<<endl;
	}
	return 0;
}
/*
wrong case: [1,2,4]
找所有递增子序列的和*/