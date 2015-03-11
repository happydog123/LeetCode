#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<vector<int> > Sdata(int n){
		vector<vector<int> > num;
		for(int i=0;i<n;i++)
			num.push_back(setdata());
		return num;
	}
	vector<int> setdata(){
		string temp;
		cin>>temp;
		return getInt(temp);
	}
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
    int minimumTotal(vector<vector<int> > &triangle) {
		if(triangle.size()==1)
			return triangle[0][0];
        vector<vector<int> > temp;
		int min=triangle[0][0];
		for(int i=0;i<triangle.size();i++){
			int ntemp;
			vector<int> ttemp;
			for(int j=0;j<triangle[i].size();j++){
				if(j==0&&i==0)
					ntemp=triangle[i][j];
				else if(j==0&&i>0)
					ntemp=triangle[i][j]+temp[i-1][j];
				else if(j==triangle[i].size()-1)
					ntemp=triangle[i][j]+temp[i-1][j-1];
				else{
					int a=temp[i-1][j-1];
					int b=temp[i-1][j];
					if(a<b)
						ntemp=triangle[i][j]+a;
					else
						ntemp=triangle[i][j]+b;
				}
				ttemp.push_back(ntemp);
			}
			temp.push_back(ttemp);
			if(i==triangle.size()-1){
				min=temp[i][0];
				for(int k=1;k<temp[i].size();k++){
					if(temp[i][k]<min)
						min=temp[i][k];
				}
			}
		}
		return min;
    }
};
int main(){
	int n;
	Solution test;
	while(1){
		cin>>n;
		cout<<test.minimumTotal(test.Sdata(n))<<endl;
	}
	return 0;
}