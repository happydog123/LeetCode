#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        vector<vector<int>> help;
		for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix[i].size();j++){
				if(matrix[i][j]==0){
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(j);
					help.push_back(temp);
				}
			}
		}
		for(int i=0;i<help.size();i++){
			int row=help[i][0];
			int column=help[i][1];
			for(int j=0;j<matrix[row].size();j++)
				matrix[row][j]=0;
			for(int j=0;j<matrix.size();j++)
				matrix[j][column]=0;
		}
    }
};
/*
思路比较简单就没写测试用例*/