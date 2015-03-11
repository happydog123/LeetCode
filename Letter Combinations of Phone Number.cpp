#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
		if(digits.size()==0)
			return result;
		int begin=0;
		result=helper(digits,begin);
    }
	vector<string> helper(string digits, int begin){
		if(begin==digits.size()-1){
			return tohelp(digits[begin]);
		}
		vector<string> temp1=tohelp(digits[begin]);
		begin++;
		vector<string> temp2=helper(digits,begin);
		vector<string> result;
		for(int i=0;i<temp1.size();i++){
			for(int j=0;j<temp2.size();j++){
				string temp=temp1[i]+temp2[j];
				result.push_back(temp);
			}
		}
		return result;

	}
	vector<string> tohelp(char c){
		vector<string> result;
		if(c=='1')
			return result;
		if(c=='2'){
			result.push_back("a");
			result.push_back("b");
			result.push_back("c");
			return result;
		}
		if(c=='3'){
			result.push_back("d");
			result.push_back("e");
			result.push_back("f");
			return result;
		}
		if(c=='4'){
			result.push_back("g");
			result.push_back("h");
			result.push_back("i");
			return result;
		}
		if(c=='5'){
			result.push_back("j");
			result.push_back("k");
			result.push_back("l");
			return result;
		}
		if(c=='6'){
			result.push_back("m");
			result.push_back("n");
			result.push_back("o");
			return result;
		}
		if(c=='7'){
			result.push_back("p");
			result.push_back("q");
			result.push_back("r");
			result.push_back("s");
			return result;
		}
		if(c=='8'){
			result.push_back("t");
			result.push_back("u");
			result.push_back("v");
			return result;
		}
		if(c=='9'){
			result.push_back("w");
			result.push_back("x");
			result.push_back("y");
			result.push_back("z");
			return result;
		}
		return result;
	}
};