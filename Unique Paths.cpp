#include <iostream>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int t[100][100];
		if(m==1||n==1)
			return 1;
		for(int i=0;i<m;i++)
			t[i][0]=1;
		for(int j=0;j<n;j++)
			t[0][j]=1;
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				t[i][j]=t[i][j-1]+t[i-1][j];
			}
		}
		return t[m-1][n-1];
    }
};
int main(){
	int m,n;
	while(1){
		cin>>m>>n;
		Solution test;
		cout<<test.uniquePaths(m,n)<<endl;
	}
	return 0;
}