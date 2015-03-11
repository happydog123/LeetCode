#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        string result="";
		if(nRows==1)
			return s;
		for(int i=0;i<nRows;i++){
			string t="";
			int down=2*(nRows-i-1);
			int up=2*i;
			if(i<s.length()){
				int k=i;
				bool flag=true;//true为向下，false为向上
				while(k<s.length()){
					//cout<<s[k]<<endl;
					t=t+s[k];
					if(up==0||down==0){
						if(up==0&&down!=0)
							k=k+down;
						else if(down==0&&up!=0)
							k=k+up;
						else
							break;
					}
					else
					{
						if(flag){
							k=k+down;
							flag=false;
						}
						else{
							k=k+up;
							flag=true;
						}
					}
				}
				//cout<<t<<endl;
				result+=t;
			}
			else
				break;
		}
		return result;
    }
};

int main(){
	Solution test;
	string input;
	int row;
	while(1){
		cin>>input;
		cin>>row;
		cout<<test.convert(input,row)<<endl;
	}
}
/*
wrong case: {ab,1}*/