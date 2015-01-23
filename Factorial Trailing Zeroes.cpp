#include <iostream>
using namespace std;

class Solution{
public:
	int trailingZeroes(int n){
		int temp=n;
		int result=0;
		while(temp!=0){
			result+=(temp/5);
			temp/=5;
		}
		return result;
	}
};

int main(){
	Solution test;
	int n;
	cin>>n;
	cout<<test.trailingZeroes(n)<<endl;
	while(1);
	return 0;
}
/*
this is a math problem
http://en.wikipedia.org/wiki/Trailing_zero
*/