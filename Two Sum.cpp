#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
		map<int,int> m;
		for(int i=0;i<numbers.size();i++){
			if(m.find(target-numbers[i])!=m.end()){
				if(i<m[target-numbers[i]]){
					result.push_back(i+1);
					result.push_back(m[target-numbers[i]]+1);
				}
				else{
					result.push_back(m[target-numbers[i]]+1);
					result.push_back(i+1);
				}
				return result;
			}
			else{
				m[numbers[i]]=i;
			}
		}
		return result;
    }
};

/*
暴力解决大集合不行所以用hashmap*/