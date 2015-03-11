#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(haystack==NULL||needle==NULL)
			return 0;
		int n=strlen(haystack);
		int m=strlen(needle);
		int position=-1;
		for(int i=0;i<=(n-m);i++){
			bool flag=true;
			for(int j=0;j<m;j++){
				if(haystack[i+j]!=needle[j]){
					flag=false;
					break;
				}
			}
			if(flag)
				return i;
		}
		return position;
    }
};

int main(){
	char* m=(char*)malloc(sizeof(char));
	char* n=(char*)malloc(sizeof(char));;
	Solution test;
	while(1){
		cin>>m;
		cin>>n;
		cout<<test.strStr(m,n)<<endl;
	}
}