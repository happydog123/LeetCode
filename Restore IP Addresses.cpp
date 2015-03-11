#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
		result=helper(s,4);
		return result;
    }

	vector<string> helper(string s,int n){
		vector<string> result;
		if(n==4&&(s.length()<=3||s.length()>12))
			return result;
		else if(n==3&&(s.length()<=2||s.length()>9))
			return result;
		else if(n==2&&(s.length()<=1||s.length()>6))
			return result;
		else if(n==1&&(s.length()==0||s.length()>3))
			return result;
		else if(n==0&&s.length()>=0)
			return result;

		if(n==1){
			if(check(s))
				result.push_back(s);
		}
		else{
			if(s.length()>=1&&check(s.substr(0,1))){//要加s.length()判断否则会RuntimeError
				string s1=s.substr(0,1)+".";
				string s2=s.substr(1,s.length()-1);
				vector<string> temp=helper(s2,n-1);
				for(int i=0;i<temp.size();i++)
					result.push_back(s1+temp[i]);
			}
			if(s.length()>=2&&check(s.substr(0,2))){
				string s1=s.substr(0,2)+".";
				string s2=s.substr(2,s.length()-2);
				vector<string> temp=helper(s2,n-1);
				for(int i=0;i<temp.size();i++)
					result.push_back(s1+temp[i]);
			}
			if(s.length()>=3&&check(s.substr(0,3))){
				string s1=s.substr(0,3)+".";
				string s2=s.substr(3,s.length()-3);
				vector<string> temp=helper(s2,n-1);
				for(int i=0;i<temp.size();i++)
					result.push_back(s1+temp[i]);
			}
		}
		return result;
	}
	bool check(string s){
		stringstream ss;
		int n;
		if(s.length()==1){
			ss<<s;
			ss>>n;
			if(n>=0&&n<=9)
				return true;
			else
				return false;
		}
		else if(s.length()==2){
			ss<<s;
			ss>>n;
			if(n>=10&&n<=99)
				return true;
			else
				return false;
		}
		else if(s.length()==3){
			ss<<s;
			ss>>n;
			if(n>=100&&n<=255)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};