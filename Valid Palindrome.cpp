#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")
			return true;
		int i=0;
		int j=s.length()-1;
		char m,n;
		while(i<j){
			while(i<s.length()&&!isChar(s[i]))
				i++;
			while(j>=0&&!isChar(s[j]))
				j--;
			if(i<=j){
				if(toSmall(s[i])!=toSmall(s[j]))
					return false;
				else{
					i++;j--;
				}
			}
			else
				break;
		}
		return true;
    }

	char toSmall(char c){
		if(c>='A'&&c<='Z')
			return (char)((int)c+32);
		else
			return c;
	}

	bool isChar(char c){
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'))
			return true;
		else
			return false;
	}
};

int main(){
	string input="race a car";
	Solution test;
	if(test.isPalindrome(input))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	while(1);
}
/*
先把字符串化简导致Time Limit Exceed*/