#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        vector<string> v;
		int len=strlen(s);
		int i=0;
		while(i<len){
			string t;
			bool flag=false;
			while(i<len&&s[i]==' ')
				i++;
			while(i<len&&s[i]!=' '){
				flag=true;
				t=t+s[i];
				i++;
			}
			if(flag)
				v.push_back(t);
			i++;
		}
		if(!v.empty()){
			string s=v[v.size()-1];
			return s.length();
		}
		else
			return 0;
    }
};

int main(){
	char *s=(char*)malloc(sizeof(char));
	s="Hello World  ";
	Solution test;
	cout<<test.lengthOfLastWord(s)<<endl;
	while(1);
}
/*
wrong case: "a  b   "*/