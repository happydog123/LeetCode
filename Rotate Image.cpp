#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int n=matrix.size();
        for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				int p=matrix[i][j];
				int q=matrix[j][i];
				matrix[i][j]=q;
				matrix[j][i]=p;
			}
		}
		for(int i=0;i<n;i++)
			reverse(matrix[i].begin(),matrix[i].end());
    }
};

/*
因为思路很清晰，所以没有写测试用例*/