#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
class Solution {
private:
	map<string,int> m;
	vector<int> result;
public:
    vector<int> grayCode(int n) {
		if(n==0){
			result.push_back(0);
			return result;
		}
		string s="";
		for(int i=0;i<n;i++)
			s=s+'0';
		helper(s);
		/*result.push_back(0);
		map<string,int>::iterator it;
		for(it=m.begin();it!=m.end();++it){
			if(it->second!=0)
				result.push_back(it->second);
		}*/
		return result;
    }
	void helper(string s){
		if(m.find(s)!=m.end())
			return;
		m[s]=convert(s);
		result.push_back(m[s]);
		for(int i=s.length()-1;i>=0;i--){
			string temp;
			temp=s;
			if(s[i]=='0')
				temp[i]='1';
			else
				temp[i]='0';
			helper(temp);
		}
	}
	int convert(string s){
		int result=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='0')
				result=result*2;
			else
				result=result*2+1;
		}
		return result;
	}
};