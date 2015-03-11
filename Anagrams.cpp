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
		sort(s.begin(), s.end());//������������ĵط����������Ϊmap�Ĺؼ��֡��ƾ��׸����
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
������˼�룬���ǳ������Լ����*/