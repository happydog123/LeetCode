#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
	int total;
public:
    int totalNQueens(int n) {
		vector<int> help;
		total=0;
		helper(n,0,help);
        return total;
    }
	void helper(int n,int index,vector<int> help){
		int i=0;
		while(i<n){
			if(correct(help,i)){
				help.push_back(i);
				if(help.size()==n){
					total++;
				}
				helper(n,index+1,help);
				help.pop_back();//这是进行了回退的地方
			}
			i++;
		}
	}
	bool correct(vector<int> help,int place){
		int row=help.size();
		for(int i=0;i<row;i++){
			if(help[i]==place)
				return false;
			if(abs(i-row)==abs(help[i]-place))
				return false;
		}
		return true;
	}
};