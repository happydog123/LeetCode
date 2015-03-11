#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
		for(int i=1;i<=numRows;i++){
			vector<int> t;
			if(i!=1)
				t.push_back(1);
			for(int j=2;j<i;j++){
				t.push_back(result[i-2][j-2]+result[i-2][j-1]);
			}
			t.push_back(1);
			result.push_back(t);
		}
		return result;
    }
};

int main(){
	int n;
	vector<vector<int>> result;
	Solution test;
	while(1){
		cin>>n;
		result=test.generate(n);
		for(int i=0;i<result.size();i++){
			for(int j=0;j<result[i].size();j++)
				cout<<result[i][j]<<",";
			cout<<endl;
		}
	}
	return 0;
}