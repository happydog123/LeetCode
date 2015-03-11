#include<iostream>
using namespace std;
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int tlength=n;
		int i=0;
		while(i<tlength){
			if(A[i]!=elem)
				i++;
			else{
				int t=i+1;
				while(t<tlength){
					A[t-1]=A[t];
					t++;
				}
				tlength--;
			}
		}
		return tlength;
    }
};

void input(int A[],int n){
	for(int i=0;i<n;i++)
		cin>>A[i];
}

void print(int A[],int n){
	for(int i=0;i<n;i++)
		cout<<A[i]<<" , ";
	cout<<endl;
}

int main(){
	int inside[100];
	int n;
	int find;
	int result;
	Solution test;
	while(1){
		cin>>n;
		cin>>find;
		input(inside,n);
		result=test.removeElement(inside,n,find);
		print(inside,result);
	}
}