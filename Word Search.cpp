#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		vector<vector<int>> temp;
		for(int i=0;i<board.size();i++){
			vector<int> t;
			for(int j=0;j<board[i].size();j++)
				t.push_back(0);
			temp.push_back(t);
		}
		int mi=0,mj=0,begin=0;
        return helper(board,temp,mi,mj,word,begin);
    }
	bool helper(vector<vector<char>>&board, vector<vector<int>> help, int mi,int mj,string word,int begin){
		if(begin>=word.size()||begin<0)
			return false;
		cout<<"in seeking "<<word[begin]<<endl;
		if(mi<0||mi>=board.size())
			return false;
		if(mj<0||mj>=board[0].size())
			return false;
		if(help[mi][mj]==0){
			if(board[mi][mj]==word[begin]){
				help[mi][mj]=1;
				begin++;
				if(begin>=word.size())
					return true;
				//up
				cout<<"try turn up"<<endl;
				if(mi-1>=0&&mi-1<board.size()){
					if(helper(board,help,mi-1,mj,word,begin)){
						cout<<"turn up is true"<<endl;
						return true;
					}
				}
				//down
				cout<<"try turn down"<<endl;
				if(mi+1>=0&&mi+1<board.size()){
					if(helper(board,help,mi+1,mj,word,begin)){
						cout<<"turn down is true"<<endl;
						return true;
					}
				}
				//left
				cout<<"try turn left"<<endl;
				if(mj-1>=0&&mj-1<board[0].size()){
					if(helper(board,help,mi,mj-1,word,begin)){
						cout<<"turn left is true"<<endl;
						return true;
					}
				}
				//right
				cout<<"try turn right"<<endl;
				if(mj+1>=0&&mj+1<board[0].size()){
					if(helper(board,help,mi,mj+1,word,begin)){
						cout<<"turn right is true"<<endl;
						return true;
					}
				}
				help[mi][mj]=0;
				begin--;
				return false;
			}
			else{
				//up
				if(mi-1>=0&&mi-1<board.size()){
					cout<<"let try turn up"<<endl;
					if(helper(board,help,mi-1,mj,word,begin)){
						cout<<"let turn up is true"<<endl;
						return true;
					}
					help[mi-1][mj]=0;
				}
				//down
				if(mi+1>=0&&mi+1<board.size()){
					cout<<"let try turn down"<<endl;
					if(helper(board,help,mi+1,mj,word,begin)){
						cout<<"let turn down is true"<<endl;
						return true;
					}
					help[mi+1][mj]=0;
				}
				//left
				if(mj-1>=0&&mj-1<board[0].size()){
					cout<<"let try turn left"<<endl;
					if(helper(board,help,mi,mj-1,word,begin)){
						cout<<"let turn left is true"<<endl;
						return true;
					}
					help[mi][mj-1]=0;
				}
				//right
				if(mj+1>=0&&mj+1<board[0].size()){
					cout<<"let try turn right"<<endl;
					if(helper(board,help,mi,mj+1,word,begin)){
						cout<<"let turn right is true"<<endl;
						return true;
					}
					help[mi][mj+1]=0;
				}
				return false;
			}
		}
		else
			return false;
	}
};

int main(){
	Solution test;
	while(1){
		vector<vector<char>> input;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			vector<char> iinput;
			for(int j=0;j<s.size();j++)
				iinput.push_back(s[j]);
			input.push_back(iinput);
		}
		string output;
		cin>>output;
		if(test.exist(input,output))
			cout<<"true"<<endl;
		else
			cout<<"false"<<endl;
	}
}