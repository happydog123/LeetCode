#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;
		int index=rowIndex+1;
		for(int i=1;i<=index;i++){
			vector<int> t;
			if(i!=1)
				t.push_back(1);
			for(int j=2;j<i;j++){
				t.push_back(result[i-2][j-2]+result[i-2][j-1]);
			}
			t.push_back(1);
			result.push_back(t);
		}
		return result[result.size()-1];
    }
};

int main(){
	int n;
	vector<int> result;
	Solution test;
	while(1){
		cin>>n;
		result=test.getRow(n);
		for(int i=0;i<result.size();i++){
			cout<<result[i]<<",";
		}
	}
	return 0;
}