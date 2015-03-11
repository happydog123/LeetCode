#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
private: vector<vector<int>> f;//0 false, 1 true, -1 unvisited
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
		if(s.size()==0)
			return false;
		for(int i=0;i<s.length();i++){
			vector<int> temp;
			for(int j=0;j<s.length();j++){
				temp.push_back(-1);
			}
			f.push_back(temp);
		}
		return helper(s,dict,0,s.size()-1);
    }

	bool helper(string s, unordered_set<string>&dict,int begin,int end){
		if(f[begin][end]==1)
			return true;
		if(f[begin][end]==0)
			return false;
		unordered_set<string>::iterator it=dict.find(s.substr(begin,end-begin+1));
		if(it!=dict.end()){
			f[begin][end]=1;
			return true;
		}
		for(int i=begin+1;i<=end;i++){
			if(helper(s,dict,begin,i-1)&&helper(s,dict,i,end)){
				f[begin][end]=1;
				return true;
			}
		}
		f[begin][end]=0;
		return false;
	}
};
/*
看了参考程序才做出来的*/