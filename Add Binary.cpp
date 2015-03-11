#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string t="0";
		string result;
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int lena=a.length();
		int lenb=b.length();
		if(lena>lenb){
			for(int i=0;i<(lena-lenb);i++)
				b=b+"0";
		}
		else if(lena<lenb){
			for(int i=0;i<(lenb-lena);i++)
				a=a+"0";
		}
		//cout<<"a is "<<a<<" b is "<<b<<endl;
		for(int i=0;i<a.length();i++){
			if(a[i]=='1'&&b[i]=='1'){
				if(t=="0"){
					result=result+"0";
					t="1";
				}
				else{
					result=result+"1";
				}
			}
			else if((a[i]=='1'&&b[i]=='0')||(a[i]=='0'&&b[i]=='1')){
				if(t=="1"){
					result=result+"0";
				}
				else{
					result=result+"1";
				}
			}
			else{
				if(t=="1"){
					result=result+"1";
					t="0";
				}
				else{
					result=result+"0";
				}
			}
			//cout<<result<<endl;
		}
		if(t=="1")
			result=result+"1";
		reverse(result.begin(),result.end());
		return result;
    }
};

int main(){
	string input1,input2;
	Solution test;
	while(1){
		cin>>input1;
		cin>>input2;
		cout<<test.addBinary(input1,input2)<<endl;
	}
}