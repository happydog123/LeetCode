#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
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