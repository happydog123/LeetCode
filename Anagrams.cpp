#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<iterator>
#include<vector>
using namespace std;

class Solution {
public:
vector<string> anagrams(vector<string> &strs) {
	vector<string> vst;
	if (strs.size() < 2) return vst;

	map<string, vector<string> > msvs;

	for (int i = 0; i < strs.size(); i++)
	{
		string s = strs[i];
		sort(s.begin(), s.end());//精华，最巧妙的地方：排序后作为map的关键字。黄绢幼妇外孙！
		msvs[s].push_back(strs[i]);
	}

	for (auto it:msvs)
	{
		if (it.second.size() > 1)
			vst.insert(vst.end(),it.second.begin(), it.second.end());
	}
	return vst;
}
};
/*
理解这个思想，但是程序不是自己编的*/