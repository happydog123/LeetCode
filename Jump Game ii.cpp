#include<iostream>
#include<vector>
using namespace std;
/*class Solution {
public:
    int jump(int A[], int n) {
        vector<int> temp;
		for(int i=0;i<n;i++)
			temp.push_back(0);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<=i+A[i]&&j<n;j++){
				if(temp[j]==0){
					temp[j]=temp[i]+1;
				}
				else{
					int step=temp[i]+1;
					if(step<temp[j])
						temp[j]=step;
				}
			}
		}
		return temp[n-1];
    }
};*/
class Solution {
public:
    int jump(int A[], int n) {
        vector<int> temp;
		temp.push_back(0);
		int last_farest=A[0];
		int farest=A[0];
		int last_step=0;
		int step=0;
		for(int i=1;i<n;i++){
			if(i<=last_farest){
				int count=last_step<step?last_step:step;
				temp.push_back(count+1);
			}
			else
				temp.push_back(step+1);
			if(i+A[i]<n){
				if(i+A[i]>farest){
					last_farest=farest;
					last_step=step;
					farest=i+A[i];
					step=temp[i];
				}
				else if(i+A[i]>last_farest){
					last_farest=i+A[i];
					last_step=temp[i];
				}
			}
		}
		for(int i=0;i<n;i++)
			cout<<temp[i]<<" , ";
		cout<<endl;
		return temp[n-1];
    }
};
int main(){
	int A[100]={7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
	int n=15;
	Solution test;
	while(1){
		//cin>>n;
		//for(int i=0;i<n;i++)
			//cin>>A[i];
		cout<<test.jump(A,n)<<endl;
		while(1);
	}
}