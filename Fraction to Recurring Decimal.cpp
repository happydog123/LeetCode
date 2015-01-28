#include <iostream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
		string result;
		stringstream ss;
		long long int mod;
		long long n=numerator;
		long long d=denominator;
		n=abs(n);
		d=abs(d);


		if((numerator<0&&denominator>0)||(numerator>0&&denominator<0))
				result+='-';
		ss<<n/d;
		result+=(ss.str());
		mod=abs(n%d);

		if(mod!=0){
			result+='.'; 
			vector<int> consult;
			vector<int> remainder;
			int num=0;

			mod*=10;
			unordered_map<int,int> map;
			while(1){
				unordered_map<int,int>:: iterator it=map.find(mod);
				while(it!=map.end()){
					for(unordered_map<int,int>::iterator iter=map.begin();iter!=it;iter++){
						ss.str("");
						ss<<iter->second;
						result+=(ss.str());
					}
					result+='(';
					for(unordered_map<int,int>::iterator iter=it;iter!=map.end();iter++){
						ss.str("");
						ss<<iter->second;
						result+=(ss.str());
					}
					result+=')';
					return result;
				}
				if(mod==0){
					for(unordered_map<int,int>::iterator iter=map.begin();iter!=map.end();iter++){
						ss.str("");
						ss<<iter->second;
						result+=(ss.str());
					}
					return result;
				}
				map.insert(make_pair(mod,mod/d));
				mod=(mod%d)*10;
			}
		}
        return result;       
    }
};
int main(){
	Solution test;
	int numerator=1,denominator=1;
	cin>>numerator>>denominator;
	cout<<test.fractionToDecimal(numerator,denominator)<<endl;
	while(1);
	return -1;
}
/*
wrong case: [1,8] Runtime Error
wrong case: [1,99] Runtime Error
wrong case: [-2147483648,-1] Runtime Error
wrong case: [1,333] output: 0.(0) Expected: 0.(003)
wrong case: [1,214748364] Runtime Error
wrong case: [1,6] output: 0.(1) Expected: 0.1(6)
wrong case: [-50,8] output:-6.-2-5 Expected: -6.25
int -2147483648 ~ +2147483647
wrong case: [-2147483648,-1999] Time Limit Exceeded

wrong case that I can't understand: [1,6] Ouput: 0.(61)  Expected: 0.1(6)
*/