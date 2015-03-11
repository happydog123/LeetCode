#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string result="";
		string temp;
		stringstream ss;
		ss<<num;
		ss>>temp;
		int k=temp.length();
		int tk=pow(10*1.0,k-1);
		for(int i=0;i<temp.size();i++){
			result=result+toStr(((int)(temp[i])-48)*tk);
			//cout<<((int)(temp[i])-48)*tk<<endl;
			tk/=10;
			//cout<<result<<endl;
		}
		return result;
    }
	string toStr(int n){
		switch(n){
		case 1: return "I";
		case 2: return "II";
		case 3: return "III";
		case 4: return "IV";
		case 5: return "V";
		case 6: return "VI";
		case 7: return "VII";
		case 8: return "VIII";
		case 9: return "IX";
		case 10: return "X";
		case 20: return "XX";
		case 30: return "XXX";
		case 40: return "XL";
		case 50: return "L";
		case 60: return "LX";
		case 70: return "LXX";
		case 80: return "LXXX";
		case 90: return "XC";
		case 100: return "C";
		case 200: return "CC";
		case 300: return "CCC";
		case 400: return "CD";
		case 500: return "D";
		case 600: return "DC";
		case 700: return "DCC";
		case 800: return "DCCC";
		case 900: return "CM";
		case 1000: return "M";
		case 2000: return "MM";
		case 3000: return "MMM";
		default: return "";
		}
	}
};
int main(){
	int input;
	Solution test;
	while(1){
		cin>>input;
		cout<<test.intToRoman(input)<<endl;
	}
}