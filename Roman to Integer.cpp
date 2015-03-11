#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int result=0;
		int t1=0,t2=0;
		int i=0;
		while(i<s.length()){
			if(i>0){
				t2=toInt(s[i]);
				result=result+t2;
				if(t1<t2)
					result=result-2*t1;
				t1=t2;
			}
			else{
				t1=toInt(s[i]);
				result=result+t1;
			}
			i++;
			//cout<<"s[i-1] is "<<s[i-1]<<" t1 is "<<t1<<" t2 is "<<t2<<" result is "<<result<<endl;
		}
		return result;
    }

	int toInt(char c){
		switch(c){
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
		}
	}
};

int main(){
	string input;
	Solution test;
	while(1){
		cin>>input;
		cout<<test.romanToInt(input)<<endl;
	}
}