#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
       if(n==1)
		   return A[0];
	   int max=A[0];
	   int tmax=max;
	   int min=A[0];
	   int tmin=min;
	   int temptmax=tmax;
	   int tempmax=max;
	   for(int i=1;i<n;i++){
		   temptmax=tmax;
		   tempmax=max;
		   if(tmax*A[i]>=A[i])
			   tmax=tmax*A[i];
		   else
			   tmax=A[i];
		   if(max<tmax)
			   max=tmax;

		   if(tmin*A[i]>=max){
			   max=tmin*A[i];
			   tmax=max;
		   }

		   if(tmin*A[i]>=A[i])
			   tmin=A[i];
		   else
			   tmin=tmin*A[i];
		   if(min>tmin)
			   min=tmin;
		   if(temptmax*A[i]<min){
			   min=temptmax*A[i];
			   tmin=min;
		   }
		   cout<<"max is "<<max<<" tmax is "<<tmax<<" min is "<<min<<" tmin is "<<tmin<<endl;
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
		cout<<test.maxProduct(input,n)<<endl;
	}
	return 0;
}