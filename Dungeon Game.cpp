#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        vector<vector<int>> temp;
		for(int i=0;i<dungeon.size();i++){
			vector<int> ve;
			for(int j=0;j<dungeon[0].size();j++)
				ve.push_back(1);
			temp.push_back(ve);
		}
		for(int i=dungeon.size()-1;i>=0;i--){
			for(int j=dungeon[0].size()-1;j>=0;j--){
				int t,tright,tdown;
				if(i+1==dungeon.size()&&j+1==dungeon[0].size()){
					if(dungeon[i][j]<=0)
						temp[i][j]=abs(dungeon[i][j])+1;
					else
						temp[i][j]=1;
				}
				else if(i+1==dungeon.size()){
					tright=temp[i][j+1]-dungeon[i][j];
					if(tright<=0)
						temp[i][j]=1;
					else
						temp[i][j]=tright;
				}
				else if(j+1==dungeon[0].size()){
					tdown=temp[i+1][j]-dungeon[i][j];
					if(tdown<=0)
						temp[i][j]=1;
					else
						temp[i][j]=tdown;
				}
				else{
					tright=temp[i][j+1]-dungeon[i][j];
					if(tright<=0)
						tright=1;
					tdown=temp[i+1][j]-dungeon[i][j];
					if(tdown<=0)
						tdown=1;
					temp[i][j]=tright<tdown?tright:tdown;
				}
			}
		}
		return temp[0][0];
    }
};