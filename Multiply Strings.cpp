#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		if(num1=="0"||num2=="0")
			return "0";
		string result;
		result+='0';
		for(int i=num2.size()-1;i>=0;i--){
			string t=multi(num1,num2[i]);
			for(int k=0;k<num2.size()-1-i;k++)
				t+='0';
			result=add(result,t);
		}
		return result;
    }
	string add(string num1,string num2){
		int len1=num1.length();
		int len2=num2.length();
		int e=abs(len1-len2);
		string s;
		for(int i=0;i<e;i++)
			s+='0';
		if(len1>len2)
			num2=s+num2;
		else if(len1<len2)
			num1=s+num1;
		string result;
		int lk=0;
		int k;
		int m;
		int n;
		int t;
		for(int i=num1.length()-1;i>=0;i--){
			m=(int)num1[i]-48;
			n=(int)num2[i]-48;
			t=m+n+lk;
			k=t/10;
			t=t%10;
			result=result+(char)(t+48);
			lk=k;
		}
		if(lk>0)
			result=result+(char)(lk+48);
		reverse(result.begin(),result.end());
		return result;
	}

	string multi(string num, char c){
		string result;
		int m;
		int n;
		int t;
		int k;
		int lk=0;
		n=(int)c-48;
		for(int i=num.length()-1;i>=0;i--){
			m=(int)num[i]-48;
			t=m*n;
			t=t+lk;
			k=t/10;
			t=t%10;
			result=result+(char)(t+48);
			lk=k;
		}
		if(lk>0)
			result=result+(char)(lk+48);
		reverse(result.begin(),result.end());
		return result;
	}
};

int main(){
	while(1){
		char c;
		string input1;
		string input2;
		Solution test;
		cin>>input1;
		cin>>input2;
		//cout<<test.multi(input1,c)<<endl;
		//cout<<test.add(input1,input2)<<endl;
		cout<<test.multiply(input1,input2)<<endl;
	}
}