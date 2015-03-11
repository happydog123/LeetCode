#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if(obstacleGrid.size()==0)
			return 0;
		int t[100][100];
		int m=obstacleGrid.size();
		int n=obstacleGrid[0].size();
		bool flag=true;
		for(int i=0;i<m;i++){
			if(obstacleGrid[i][0]==1)
				flag=false;
			if(flag)
				t[i][0]=1;
			else
				t[i][0]=0;
		}
		flag=true;
		for(int j=0;j<n;j++){
			if(obstacleGrid[0][j]==1)
				flag=false;
			if(flag)
				t[0][j]=1;
			else
				t[0][j]=0;
		}
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				if(obstacleGrid[i][j]==1)
					t[i][j]=0;
				else
					t[i][j]=t[i][j-1]+t[i-1][j];
			}
		}
		return t[m-1][n-1];
    }
};
vector<int> getInt(string buf){
	vector<int> num;
	int temp=0;
	char c;
	for(int i=0;i!=buf.size();i++){
		if(buf[i]!=','){
			c=buf.at(i);
			temp=temp*10+atoi(&c);
		}
		else{
			num.push_back(temp);
			temp=0;
		}
	}
	num.push_back(temp);
	return num;
}
vector<int> setdata(){
	string temp;
	cin>>temp;
	return getInt(temp);
}
int main(){
	int m;
	vector<vector<int>> input;
	Solution test;
	while(1){
		cin>>m;
		for(int i=0;i<m;i++){
			input.push_back(setdata());
		}
		cout<<test.uniquePathsWithObstacles(input)<<endl;
	}
	return 1;
}