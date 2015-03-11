#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
			return 1;
		if(n==2)
			return 2;
		int a=1,b=2;
		int sum;
		for(int i=3;i<=n;i++){
			sum=a+b;
			a=b;
			b=sum;
		}
		return sum;
    }
};

int main(){
	int n;
	Solution test;
	while(1){
		cin>>n;
		cout<<test.climbStairs(n)<<endl;
	}
	return 0;
}
/*
一开始用递归超时了*/