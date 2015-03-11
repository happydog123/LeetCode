#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

int main(){
	int m;
	Solution test;
	while(1){
		cin>>m;
		cout<<test.reverse(m)<<endl;
	}
}
/*
Òç³öÎÊÌâ*/