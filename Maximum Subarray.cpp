#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
       if(n==1)
		   return A[0];
	   int max=A[0];
	   int tmax=max;
	   for(int i=1;i<n;i++){
		   if(tmax+A[i]>=A[i])
			   tmax=tmax+A[i];
		   else
			   tmax=A[i];
		   if(max<tmax)
			   max=tmax;
	   }
	   return max;
    }
};

int main(){
	int input[100];
	int n;
	Solution test;
	while(1){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>input[i];
		cout<<test.maxSubArray(input,n)<<endl;
	}
	return 0;
}