#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<char> st;
		vector<string> result;
		result=helper(n,st);
		return result;
    }

	vector<string> helper(int n, stack<char> st){
		vector<string> result;
		if(n==0){
			if(st.empty()){
				return result;
			}
			else{
				string s="";
				while(!st.empty()){
					s=s+")";
					st.pop();
				}
				result.push_back(s);
				return result;
			}
		}
		else{
			if(st.empty()){
				st.push('(');
				vector<string> temp=helper(n-1,st);
				for(int i=0;i<temp.size();i++){
					string s="("+temp[i];
					result.push_back(s);
				}
				return result;
			}
			else{
				st.push('(');
				vector<string> temp=helper(n-1,st);
				for(int i=0;i<temp.size();i++){
					string s="("+temp[i];
					result.push_back(s);
				}

				st.pop();
				st.pop();
				temp=helper(n,st);
				for(int i=0;i<temp.size();i++){
					string s=")"+temp[i];
					result.push_back(s);
				}
				return result;
			}
		}

	}
};

int main(){
	int n;
	Solution test;
	vector<string> result;
	while(1){
		cin>>n;
		result=test.generateParenthesis(n);
		for(int i=0;i<result.size();i++)
			cout<<result[i]<<endl;
	}
	return 0;
}