#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int plus=0;
		vector<int> result;
		int temp;
		for(int i=digits.size()-1;i>=0;i--){
			temp=plus+digits[i];
			if(i==digits.size()-1)
				temp++;
			plus=temp/10;
			result.push_back(temp%10);
		}
		if(plus>0)
			result.push_back(plus);
		vector<int> fresult;
		for(int i=result.size()-1;i>=0;i--)
			fresult.push_back(result[i]);
		return fresult;
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
	vector<int> result;
	while(1){
		input=setdata();
		result=test.plusOne(input);
		for(int i=0;i<result.size();i++)
			cout<<result[i]<<",";
		cout<<endl;
	}
}