#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		if(num.size()==1){
			vector<int> t;
			t.push_back(num[0]);
			vector<vector<int>> result;
			result.push_back(t);
			return result;
		}
		if(num.size()==2){
			vector<int> t;
			t.push_back(num[0]);
			t.push_back(num[1]);
			vector<vector<int>> result;
			result.push_back(t);
			t.clear();
			t.push_back(num[1]);
			t.push_back(num[0]);
			result.push_back(t);
			return result;
		}
		vector<vector<int>> result;
		for(int i=0;i<num.size();i++){
			int begin=num[i];
			vector<vector<int>> temp;
			vector<int> ttemp;
			for(int j=0;j<num.size();j++){
				if(i!=j)
					ttemp.push_back(num[j]);
			}
			temp=permute(ttemp);
			for(int j=0;j<temp.size();j++){
				temp[j].insert(temp[j].begin(),begin);
				result.push_back(temp[j]);
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
	vector<int> input;
	Solution test;
	vector<vector<int>> result;
	while(1){
		input=setdata();
		result=test.permute(input);
		for(int i=0;i<result.size();i++){
			for(int j=0;j<result[i].size();j++)
				cout<<result[i][j]<<",";
			cout<<endl;
		}
	}
	return 0;
}