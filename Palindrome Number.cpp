#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		if(x<0)
			return false;
        int n=num(x);
		if(n==1||n==0)
			return true;
		for(int i=1;i<=n/2;i++){
			int m=get(x,i);
			int p=get(x,n-i+1);
			//cout<<"m is "<<m<<" p is "<<p<<endl;
			if(m!=p)
				return false;
		}
		return true;
    }

	int num(int x){
		int n=1;
		int xk=x;
		while(xk!=0){
			xk=xk/10;
			if(xk!=0)
				n++;
		}
		return n;
	}

	int get(int x, int y){
		int k=0;
		int yk=x;
		for(int i=1;i<=y;i++){
			k=yk%10;
			yk=yk/10;
		}
		return k;
	}
};

int main(){
	int input;
	Solution test;
	while(1){
		cin>>input;
		if(test.isPalindrome(input))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}
/*
wrong case:-2147447412*/