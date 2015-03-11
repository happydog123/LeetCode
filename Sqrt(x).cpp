#include<iostream>
using namespace std;
class Solution {
public:
    int sqrt(int x) {
		if(x==0)
			return 0;
		long long low=0;
		long long high=x/2+1;
		while(low<=high){
			long long mid=low+(high-low)/2;
			long long max=mid*mid;
			if(max==x)
				return mid;
			else if(max>x)
				high=mid-1;
			else
				low=mid+1;
		}

		return high;
    }
};
int main(){
	int m;
	Solution test;
	while(1){
		cin>>m;
		cout<<test.sqrt(m)<<endl;
	}
}
/*
返回high可以解决不是平方数的问题
用long long解决大数问题*/