#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
		if(word1.length()==0)
			return word2.length();
		if(word2.length()==0)
			return word1.length();
		int column=word2.length()+1;
		int row=word1.length()+1;
		vector<vector<int>> result;
		vector<int> temp1;
		for(int i=0;i<column;i++){
			temp1.push_back(i);
		}
		result.push_back(temp1);
		for(int i=1;i<row;i++){
			vector<int> temp2;
			temp2.push_back(i);
			result.push_back(temp2);
		}
		for(int i=1;i<row;i++){
			for(int j=1;j<column;j++){
				int a=result[i-1][j-1];
				if(word1[i-1]!=word2[j-1])
					a++;
				int b=result[i][j-1]+1;
				int c=result[i-1][j]+1;
				result[i].push_back(min_three(a,b,c));
			}
		}
		return result[row-1][column-1];
    }
	int min_three(int a, int b, int c){
		if(a<=b&&a<=c)
			return a;
		if(b<=a&&b<=c)
			return b;
		if(c<=a&&c<=b)
			return c;
	}
};
/*
wrong case: "b", ""*/