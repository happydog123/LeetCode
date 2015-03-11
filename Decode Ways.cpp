#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int a=0,b=0,c=0,d=0;
		if(s.length()==1)
			return isOneDigit(s);
		if(s.length()==2)
			return isTwoDigit(s);
		string tempa=s.substr(0,1),tempb=s.substr(0,2);
		string tempc,tempd;
		a=isOneDigit(tempa);
		b=isTwoDigit(tempb);
		int sum=0;
		for(int i=2;i<s.length();i++){
			tempc=s.substr(i,1);
			tempd=s.substr(i-1,2);
			c=isOneDigit(tempc);
			d=isTwoDigit(tempd);
			sum=a*d+b*c;
			std::stringstream ss;
			int temp;
			ss<<tempd;
			ss>>temp;
			if(((temp>=11&&temp<=19)||(temp>=21&&temp%10!=0))&&c!=0&&a!=0)
				sum=sum-a;
			a=b;
			b=sum;
		}
		return sum;
    }

	int isOneDigit(string s){
		if(s.length()==1){
			std::stringstream ss;
			int temp;
			ss<<s;
			ss>>temp;
			if(temp>=1&&temp<=9)
				return 1;
			else
				return 0;
		}
		return 0;
	}

	int isTwoDigit(string s){
		if(s.length()==2){
			std::stringstream ss;
			int temp;
			ss<<s;
			ss>>temp;
			if(temp<10)
				return 0;
			if(temp==10||temp==20)
				return 1;
			if(temp>=11&&temp<=26)
				return 2;
			if(temp%10==0)
				return 0;
			return 1;
		}
		return 0;
	}
};

int main(){
	string input;
	Solution test;
	while(1){
	cin>>input;
	cout<<test.numDecodings(input)<<endl;
	}
	return 0;
}