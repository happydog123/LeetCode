#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
		if(n==0)
			return "1";
        vector<int> sequence;
		for(int i=1;i<=n;i++)
			sequence.push_back(i);
		string result="";
		int devided=0;
		int devide=k;
		int count=0;
		int leave=0;
		int t=0;
		for(int i=n;i>=1;i--){
			devided=fac(i-1);
			count=devide/devided;
			leave=devide%devided;
			if(leave>0)
				count++;
			t=find(sequence,count);
			result=result+""+(char)(t+48);
			sequence=erase(sequence,t);
			if(leave!=0){
				devide=leave;
			}
			else{
				for(int j=sequence.size()-1;j>=0;j--){
					result=result+""+(char)(sequence[j]+48);
				}
				break;
			}
		}

		return result;
    }

	vector<int> erase(vector<int>input, int value){
		std::vector<int>::iterator position=std::find(input.begin(),input.end(),value);
		bool isValid=(position!=input.end());
		if(isValid)
			input.erase(position);
		return input;
	}

	int find(vector<int>input,int count){
		if(count>input.size()||count<1){
			if(!input.empty())
				return input[0];
			else
				return -1;
		}
		else{
			return input[count-1];
		}
	}

	int fac(int x){
		register int i,f=1;
		for(i=1;i<=x;i++)
			f*=i;
		return f;
	}
};

int main(){
	int n,k;
	string result;
	Solution test;
	while(1){
		cin>>n;
		cin>>k;
		cout<<test.getPermutation(n,k)<<endl;
	}
	return 0;
}