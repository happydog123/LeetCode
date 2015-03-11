#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		if(grid.size()==0)
			return 0;
		vector<vector<int>> result;
		for(int i=0;i<grid.size();i++){
			vector<int> temp;
			for(int j=0;j<grid[i].size();j++)
				temp.push_back(0);
			result.push_back(temp);
		}
		result[0][0]=grid[0][0];
		for(int j=1;j<grid[0].size();j++){
			result[0][j]=result[0][j-1]+grid[0][j];
		}
		for(int i=1;i<grid.size();i++){
			result[i][0]=result[i-1][0]+grid[i][0];
		}
		for(int i=1;i<grid.size();i++){
			for(int j=1;j<grid[0].size();j++){
				int temp=result[i-1][j]<result[i][j-1]?result[i-1][j]:result[i][j-1];
				result[i][j]=grid[i][j]+temp;
			}
		}
		return result[grid.size()-1][grid[0].size()-1];
    }
};
/*
过年时还不会做，现在就会啦哈哈哈
跟编辑距离的感觉很像
自然而然得去分析就会得出结论*/