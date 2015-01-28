#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		int dotnum1,dotnum2;
		vector<int> num1,num2;
		dotnum1=split(version1,num1);
		dotnum2=split(version2,num2); 
		int dotnum3=min(dotnum1,dotnum2);
		for(int i=0;i<dotnum3;i++){
			if(num1[i]<num2[i])
				return -1;
			if(num1[i]>num2[i])
				return 1;
		}
		if(dotnum1<dotnum2&&num2[dotnum2-1]!=0)
			return -1;
		if(dotnum1>dotnum2&&num1[dotnum1-1]!=0)
			return 1;
		return 0;
    }
	int split(string s,vector<int> &num){
		string temp;
		int count=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='.'){
				int t;
				stringstream ss(temp);
				ss>>t;
				num.push_back(t);
				count++;
				temp.erase(0,temp.size());
			}
			else
				temp+=s[i];
		}
		int t;
		stringstream ss(temp);
		ss>>t;
		num.push_back(t);
		count++;
		return count;
	}
};

int main(){
	Solution test;
	string input1,input2;
	cin>>input1>>input2;
	cout<<test.compareVersion(input1,input2)<<endl;
	while(1);
	return 0;
}