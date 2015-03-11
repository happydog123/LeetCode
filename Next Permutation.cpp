#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
		if(num.size()==2||num.size()==1)
			reverse(num.begin(),num.end());
		else{
			bool flag=helper(num,0,num.size()-1);
			if(!flag)
				reverse(num.begin(),num.end());
		}

    }
	bool helper(vector<int> &num,int begin, int end){
		if(end-begin==1){
			if(num[begin]<num[end]){
				int temp=num[begin];
				num[begin]=num[end];
				num[end]=temp;
				return true;
			}
			else
				return false;
		}
		bool flag=helper(num,begin+1,end);
		if(flag)
			return true;
		else{
			int temp;
			bool fl=false;
			for(int i=num.size()-1;i>=begin+1;i--){
				if(num[i]>num[begin]){
					temp=i;
					fl=true;
					break;
				}
			}
			if(fl){
				int k;
				//cout<<"now change "<<num[begin]<<" and "<<num[temp]<<endl;
				k=num[begin];
				num[begin]=num[temp];
				num[temp]=k;
				//cout<<"after change num[begin] "<<num[begin]<<" num[temp] "<<num[temp]<<endl;
				sort(num.begin()+begin+1,num.end());
				//cout<<num[0]<<num[1]<<num[2]<<endl;
				return true;
			}
			else{
				return false;
			}
		}

	}
};
vector<int> getInt(string buf){
	vector<int> num;
	int temp=0;
	char c;
	for(int i=0;i!=buf.size();i++){
		if(buf[i]!=','){
			c=buf.at(i);
			temp=temp*10+atoi(&c);
		}
		else{
			num.push_back(temp);
			temp=0;
		}
	}
	num.push_back(temp);
	return num;
}
vector<int> setdata(){
	string temp;
	cin>>temp;
	return getInt(temp);
}

int main(){
	Solution test;
	while(1){
		vector<int> input=setdata();
		test.nextPermutation(input);
		for(int i=0;i<input.size();i++)
			cout<<input[i]<<" , ";
		cout<<endl;
	}
}