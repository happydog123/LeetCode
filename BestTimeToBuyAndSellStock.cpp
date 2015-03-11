#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size()==0)
			return 0;
		if(prices.size()==1)
			return 0;
		if(prices.size()==2){
			int n=prices[1]-prices[0];
			if(n<=0)
				return 0;
			return prices[1]-prices[0];
		}
		int min=prices[0];
		int profit=0;
		for(int i=1;i<prices.size();i++){
			if(prices[i]-min>profit)
				profit=prices[i]-min;
			if(prices[i]<min)
				min=prices[i];
		}
		if(profit<=0)
			return 0;
		return profit;
    }
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
};

int main(){
	Solution test;
	while(1){
		cout<<test.maxProfit(test.setdata())<<endl;
	}
	return 0;
}