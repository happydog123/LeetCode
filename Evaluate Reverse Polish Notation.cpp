#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include <sstream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int result=0;
		stack<int> s;
		stringstream ss;
		for(int i=0;i<tokens.size();i++){
			if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
				int a=s.top();
				s.pop();
				int b=s.top();
				s.pop();
				if(tokens[i]=="+")
					s.push(a+b);
				else if(tokens[i]=="-")
					s.push(b-a);
				else if(tokens[i]=="*")
					s.push(a*b);
				else if(tokens[i]=="/")
					s.push(b/a);
			}
			else{
				int val=0;
				ss.clear();
				ss<<tokens[i];
				ss>>val;
				//cout<<"val is "<<val<<endl;
				s.push(val);
			}
		}
		if(!s.empty())
			result=s.top();
		return result;
    }
};

int main(){
	Solution test;
	while(1){
		vector<string> input;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			input.push_back(s);
		}
		cout<<test.evalRPN(input)<<endl;
	}
}