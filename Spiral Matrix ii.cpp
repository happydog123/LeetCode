#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> result;
		for(int i=0;i<n;i++){
			vector<int> temp;
			for(int j=0;j<n;j++)
				temp.push_back(0);
			result.push_back(temp);
		}
		int time=0;
		time=n/2;
		if(n%2!=0)
			time++;
		int add=1;
		for(int i=0;i<time;i++){
			int length=n-i*2;
			int height=length;
			int x=i;
			int y=i;
			int right;
			for(int j=0;j<length;j++){
				result[x][y]=add;
				//cout<<add<<endl;
				add++;
				right=y;
				y++;
			}
			y--;
			for(int j=1;j<height;j++){
				result[x+1][y]=add;
				//cout<<add<<endl;
				add++;
				x++;
			}
			if(x!=i){
				for(int j=1;j<length;j++){
					result[x][y-1]=add;
					//cout<<add<<endl;
					add++;
					y--;
				}
			}
			if(y!=right){
				for(int j=2;j<height;j++){
					result[x-1][y]=add;
					//cout<<add<<endl;
					add++;
					x--;
				}
			}
		}
		return result;
    }
};

int main(){
	int n;
	Solution test;
	while(1){
		cin>>n;
		vector<vector<int>> result;
		result=test.generateMatrix(n);
		for(int i=0;i<result.size();i++){
			for(int j=0;j<result[i].size();j++)
				cout<<result[i][j]<<" , ";
			cout<<endl;
		}
	}
	return 0;
}