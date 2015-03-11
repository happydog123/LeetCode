#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
	vector<vector<string>> result;
public:
    vector<vector<string> > solveNQueens(int n) {
		vector<int> help;
		helper(n,0,help);
        return result;
    }
	void helper(int n,int index,vector<int> help){
		int i=0;
		while(i<n){
			if(correct(help,i)){
				help.push_back(i);
				if(help.size()==n){
					vector<string> temp;
					for(int i=0;i<n;i++){
						string s;
						for(int j=0;j<n;j++)
							s=s+".";
						s[help[i]]='Q';
						temp.push_back(s);
					}
					result.push_back(temp);
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