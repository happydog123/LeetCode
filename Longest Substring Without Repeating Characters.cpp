#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int max_length=0;
		map<char,int> m;
		vector<char> v;
		for(int i=0;i<s.length();i++){
			if(m.find(s[i])==m.end()){
				m[s[i]]=i;
				v.push_back(s[i]);
			}
			else{
				if(max_length<v.size())
					max_length=v.size();
				while(!v.empty()&&v[0]!=s[i]){
					m.erase(v[0]);
					v.erase(v.begin());
				}
				if(!v.empty())
					v.erase(v.begin());
				m[s[i]]=i;
				v.push_back(s[i]);
			}
		}
		if(max_length<v.size())
			max_length=v.size();
		return max_length;
    }
};