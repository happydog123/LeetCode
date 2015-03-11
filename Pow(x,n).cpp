#include<iostream>
using namespace std;
class Solution {
public:
    double pow(double x, int n) {
        if(n==0)return 1;
        if(n==1)return x;
        double temp=pow(x,abs(n/2));
        if(n>0)
        {
            if(n&1)return temp*temp*x;
            else return temp*temp;
        }
        else 
        {
            if(n&1)return 1.0/(temp*temp*x);
            else return 1.0/(temp*temp);
        }
    }
};
// blog.csdn.net/havenoidea

int main(){
	double m;
	int n;
	Solution test;
	while(1){
		cin>>m;
		cin>>n;
		cout<<test.pow(m,n)<<endl;
	}
}
/*
不能一个一个乘，会有Time Limit Exceed
没考虑到n是正数还是负数*/