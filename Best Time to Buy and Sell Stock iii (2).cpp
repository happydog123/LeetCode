#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size()<2)
			return 0;
		if(prices.size()==2)
			return prices[1]-prices[0]>0?prices[1]-prices[0]:0;
		vector<int> before;
		int min=prices[0];
		int profit=prices[1]-min;
		if(prices[1]<prices[0]){
			min=prices[1];
			profit=0;  
		}
		before.push_back(0);
		before.push_back(profit);
		for(int i=2;i<prices.size();i++){
			if(prices[i]-min>profit)
				profit=prices[i]-min;
			if(prices[i]<min)
				min=prices[i];
			before.push_back(profit);
		}

		vector<int> after;
		int max=prices[prices.size()-1];
		profit=max-prices[prices.size()-2];
		if(prices[prices.size()-2]>prices[prices.size()-1]){
			max=prices[prices.size()-2];
			profit=0;
		}
		after.push_back(0);
		after.push_back(profit);
		for(int i=prices.size()-3;i>=0;i--){
			if(max-prices[i]>profit)
				profit=max-prices[i];
			if(prices[i]>max)
				max=prices[i];
			after.push_back(profit);
		}
		profit=before[before.size()-1];
		for(int i=0;i<before.size()-1;i++){
			if(before[i]+after[before.size()-i-1]>profit)
				profit=before[i]+after[before.size()-i-1];
		}
		return profit;
    }
    int maxProfit_one(vector<int> &prices) {
		if(prices.size()==2)
			return prices[1]-prices[0];
		int min=prices[0];
		int profit=prices[1]-min;
		for(int i=2;i<prices.size();i++){
			if(prices[i]-min>profit)
				profit=prices[i]-min;
			if(prices[i]<min)
				min=prices[i];
		}
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
}
/*
今天状态不好，一天了就AC了这么一道题，还是看了参考思路以后*/