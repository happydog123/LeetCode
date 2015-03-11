#include<iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result;
		result.push_back('1');
		vector<int> v;
		stringstream ss;
		int k;
		for(int i=2;i<=n;i++){
			vector<int>().swap(v);
			bool flag=true;//true表明是开始一个新的
			for(int j=0;j<result.size();j++){
				k=(int)result[j]-48;
				if(flag){
					v.push_back(1);
					v.push_back(k);
					flag=false;
				}
				else{
					if(result[j]==result[j-1]){
						int m=v[v.size()-2];
						v[v.size()-2]=m+1;
					}
					else{
						v.push_back(1);
						v.push_back(k);
					}
				}
			}
			result.clear();
			char c;
			for(int i=0;i<v.size();i++){
				ss.str("");
				ss<<v[i];
				result=result+ss.str();
			}
		}
		//cout<<result<<endl;
		return result;
    }
};

int main(){
	int n;
	Solution test;
	while(1){
		cin>>n;
		//test.countAndSay(n);
		cout<<test.countAndSay(n)<<endl;
	}
	return 0;
}