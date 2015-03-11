#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n==1)
			return 1;
		if(n==2)
			return 2;
		int sum=0;
		for(int i=1;i<=n;i++){
			int t1=numTrees(i-1);
			int t2=numTrees(n-i);
			if(t1!=0&&t2!=0)
				sum=sum+t1*t2;
			else if(t1==0&&t2!=0)
				sum=sum+t2;
			else if(t1!=0&&t2==0)
				sum=sum+t1;
		}
		return sum;
    }
};

int main(){
	int input;
	Solution test;
	while(1){
		cin>>input;
		cout<<test.numTrees(input)<<endl;
	}
	return 0;
}