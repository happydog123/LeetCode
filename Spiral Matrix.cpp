#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> result;
		int m=matrix.size();
		if(m==0)
			return result;
		int n=matrix[0].size();
		int time=0;
		if(m>=n){
			time=n/2;
			if(n%2!=0)
				time++;
		}
		else{
			time=m/2;
			if(m%2!=0)
				time++;
		}
		for(int i=0;i<time;i++){
			int length=n-i*2;
			int height=m-i*2;
			int x=i;
			int y=i;
			int right;
			//cout<<"length is "<<length<<" height is "<<height<<endl;
			for(int j=0;j<length;j++){
				result.push_back(matrix[x][y]);
				right=y;
				y++;
			}
			y--;
			for(int j=1;j<height;j++){
				result.push_back(matrix[x+1][y]);
				x++;
			}
			if(x!=i){
				for(int j=1;j<length;j++){
					result.push_back(matrix[x][y-1]);
					y--;
				}
			}
			if(y!=right){
				for(int j=2;j<height;j++){
					result.push_back(matrix[x-1][y]);
					x--;
				}
			}
		}
		return result;
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
	Solution test;
	while(1){
		cin>>m;
		vector<int> result;
		vector<vector<int>> input;
		for(int i=0;i<m;i++){
			vector<int> temp=setdata();
			input.push_back(temp);
		}
		result=test.spiralOrder(input);
		for(int i=0;i<result.size();i++)
			cout<<result[i]<<" , ";
		cout<<endl;
	}
}
/*
[1,2]情况
[]情况
[[7],[9],[6]]
[[7,9,6]]*/