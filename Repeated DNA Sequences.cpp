#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
		map<int,int> m;
		if(s.length()<10)
			return result;
		for(int i=0;i<=s.length()-10;i++){
			int temp=transmit(s.substr(i,10));
			//cout<<s.substr(i,10)<<" is "<<temp<<endl;
			if(m.find(temp)==m.end()){
				m[temp]=1;
			}
			else{
				if(m[temp]==1){
					result.push_back(s.substr(i,10));
					m[temp]=2;
				}
			}
		}
		return result;
    }
	int transmit(string s){
		int result=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='A'){
				result<<=2;
				result+=0;
			}
			else if(s[i]=='C'){
				result<<=2;
				result+=1;
			}
			else if(s[i]=='G'){
				result<<=2;
				result+=2;
			}
			else if(s[i]=='T'){
				result<<=2;
				result+=3;
			}
		}
		return result;
	}
};
int main(){
	string input;
	Solution test;
	while(1){
		cin>>input;
		vector<string> result=test.findRepeatedDnaSequences(input);
		for(int i=0;i<result.size();i++)
			cout<<result[i]<<endl;
	}
}
/*
使用位运算，防止Memory Limit Exceed*/