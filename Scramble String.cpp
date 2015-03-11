#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)
			return true;
		if(s1.length()!=s2.length())
			return false;
		if(s1.length()==1){
			if(s1[0]==s2[0])
				return true;
			else
				return false;
		}
		if(s1[0]==s2[0]){
			return isScramble(s1.substr(1,s1.length()-1),s2.substr(1,s2.length()-1));
		}
		else if(s1[0]==s2[s2.length()-1]){
			return isScramble(s1.substr(1,s2.length()-1),s2.substr(0,s2.length()-1));
		}
		else{

		}
    }
};