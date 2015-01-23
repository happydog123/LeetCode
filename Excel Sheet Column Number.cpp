#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Solution{
public:
	int titleToNumber(string s){
		int result=0;
		for(int i=0;i<s.length();i++){
			int base=int(s[i]-'A')+1;
			result=result*26+base;
		}
		return result;
	}
};

int main(){
	Solution test;
	string input;
	cin>>input;
	cout<<test.titleToNumber(input)<<endl;
	while(1);
	return 0;
}