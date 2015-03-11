#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result;
		stack<string> s;
		if(path[0]=='/'){
			int i=1;
			while(i<path.length()){
				string t;
				while(i<path.length()&&path[i]!='/'){
					t=t+path[i];
					i++;
				}
				i++;
				if(t.size()!=0){
					if(t!=".."){
						if(t!="."){
							s.push(t);
						}
					}
					else{
						if(!s.empty())
							s.pop();
					}
				}
			}
		}
		if(s.size()==0)
			result+="/";
		stack<string> ss;
		while(!s.empty()){
			ss.push(s.top());
			s.pop();
		}
		while(!ss.empty()){
			string t;
			t=ss.top();
			result+="/";
			result+=t;
			ss.pop();
		}
		return result;
    }
};

int main(){
	string input;
	Solution test;
	while(1){
		cin>>input;
		cout<<test.simplifyPath(input)<<endl;
	}
	return 1;
}
/*
wrong case: /.
/..
/
///
*/