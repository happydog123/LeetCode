#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
		int tmax=0;
		int max=0;
		for(int i=0;i<n;i++){
			if(A[i]!=0){
				tmax=A[i]+i;
				if(tmax>max)
					max=tmax;
			}
			else{
				if(i==0&&n==1)
					return true;
				if(max<=i&&i!=n-1)
					return false;
			}
		}
		return true;
    }
};

int main(){
	Solution test;
	int n;
	int A[100];
	while(1){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>A[i];
		if(test.canJump(A,n))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
/*动态规划
注意特殊情况
{0}
{2,0,0}*/