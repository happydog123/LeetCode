#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
		string result;
		unsigned int numpow=1;
		unsigned int ttemp=n;
		if(n<=26){
			result+=('A'+n-1);
			return result;
		}
		while(!(n<=max(numpow)&&n>=min(numpow))){
			numpow++;
		}
		int temp=n;
		int t;
		int q;
		for(int i=numpow;i>=1;i--){
			t=temp/pow((double)26,i-1);
			q=temp%(int)pow((double)26,i-1);
			if(q==0&&i!=1)
				t--;
			result+=('A'+t-1);
			temp=temp-t*pow((double)26,i-1);
		};
		return result;
    }

	unsigned int max(int n){
		unsigned int pwd=0;
		unsigned int maxnum=0;
		for(int i=0;i<n;i++){
			pwd=26*pow((double)26,i);
			maxnum=maxnum+pwd;
		}
		return maxnum;
	}

	unsigned int min(int n){
		unsigned int pwd=0;
		unsigned int minnum=0;
		for(int i=0;i<n;i++){
			pwd=pow((double)26,i);
			minnum=minnum+pwd;
		}
		return minnum;
	}
};

int main(){
	Solution test;
	int input;
	cin>>input;
	cout<<test.convertToTitle(input)<<endl;
	while(1);
	return 0;
}
/*
1.�Ϸ���û�п���AZ�������
2.��һ���Ǽ�λʱ������һ�ָ���Ȼ���뷨
3.unsigned int��λ�����󣬲��õĻ�������1000000001ʱ��������
*/