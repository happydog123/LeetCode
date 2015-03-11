#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*class Solution {
public:
    string longestPalindrome(string s) {
		vector<vector<int>> t;
		for(int i=0;i<s.length();i++){
			vector<int> q;
			for(int j=0;j<s.length();j++){
				q.push_back(0);
			}
			t.push_back(q);
		}
		for(int i=0;i<s.length();i++)
			t[i][i]=1;
		for(int i=1;i<s.length();i++)
			t[i][i-1]=1;
		for(int i=1;i<s.length();i++){
			for(int j=0;j<i-1;j++)
				t[i][j]=0;
		}
		if(s.length()!=0){
			int begin=0,end=0,length=1;
			bool flag=false;
			for(int k=1;k<s.length();k++){
				for(int m=0;m<s.length()-k;m++){
					int j=k+m;
					int i=m;
					if(s[i]==s[j]){
						if(t[i+1][j-1]==1){
							flag=true;
							if(abs(i-j)+1>length){
								length=abs(i-j)+1;
								begin=i;
								end=j;
							}
							t[i][j]=1;
						}
						else
							t[i][j]=0;
					}
					else
						t[i][j]=0;
				}
			}
			if(flag)
				return s.substr(begin,length);
			else{
				if(s.length()==1)
					return s;
				else
					return "";
			}
		}
		else
			return "";
    }
};*/
class Solution {
public:
    string longestPalindrome(string s) {
        
    }
};
int main(){
	Solution test;
	while(1){
		string input;
		cin>>input;
		cout<<test.longestPalindrome(input)<<endl;
	}
}
/*
动态规划也超出时间复杂度了
有疑问，同样用动态规划就不一样*/