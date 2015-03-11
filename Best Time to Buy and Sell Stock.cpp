#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
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
		test.maxProfit(test.setdata());
	}
	return 0;
}