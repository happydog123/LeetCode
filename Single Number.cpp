#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int singleNumber(int A[], int n) {
        map<int,int> help;
		for(int i=0;i<n;i++){
			if(help.find(A[i])!=help.end()){
				help.erase(A[i]);
			}
			else{
				help[A[i]]=i;
			}
		}
		int result;
		map<int,int>::iterator it=help.begin();
		result=it->first;
		return result;
    }
};
int main(){
	int n;
	int A[100];
	Solution test;
	while(1){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>A[i];
		cout<<test.singleNumber(A,n)<<endl;
	}
}