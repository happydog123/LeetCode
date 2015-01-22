#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
/*class Solution {//练习版
private:
	vector<int> input;
	string output;
public:
	void setdata(){
		string temp;
		cin>>temp;
		getInt(temp);
	}
	int largerNumber(int num1,int num2){
		int length1=itos(num1).length();
		int length2=itos(num2).length();
		string snum1=itos(num1);
		string snum2=itos(num2);
		bool flag=true;
		while(flag){
			for(int i=0;i<length1&&i<length2;i++){
				if(snum1[i]>snum2[i])
					return 1;   //num1>num2
				else if(snum1[i]<snum2[i])
					return -1;   //num1<num2
			}
			if(length1==length2)
				return 0;//num1==num2
			else{
				string ssnum1,ssnum2;
				ssnum1+=snum1;
				ssnum1+=snum2;
				ssnum2+=snum2;
				ssnum2+=snum1;
				int slength=ssnum1.length();
				for(int i=0;i<slength;i++){
					if(ssnum1[i]>ssnum2[i])
						return 1;
					else if(ssnum1[i]<ssnum2[i])
						return -1;
				}
				return 0;
			}			
		}
		return 0;
	}
	void largest(){
		sort(0,input.size()-1);
	}
	void sort(int lo,int hi){
		if(hi<=lo)
			return;
		int j=partition(lo,hi);
		sort(lo,j-1);
		sort(j+1,hi);
	}
	int partition(int lo,int hi){
		int i=lo,j=hi+1;
		int v=input[lo];
		while(true){
			while(largerNumber(input[++i],v)==-1)
				if(i==hi)
					break;
			while(largerNumber(v,input[--j])==-1)
				if(j==lo)
					break;
			if(i>=j)
				break;
			int temp=input[i];
			input[i]=input[j];
			input[j]=temp;
		}
		int temp=input[lo];
		input[lo]=input[j];
		input[j]=temp;
		return j;
	}
	void display(){
		for(int i=input.size()-1;i>=0;i--){
			string temp=itos(input[i]);
			output+=temp;
		}
		cout<<output<<endl;
	}
	int getInt(string buf){
		int temp=0;
		char c;
		for(int i=0;i!=buf.size();i++){
			if(buf[i]!=','){
				c=buf.at(i);
				temp=temp*10+atoi(&c);
			}
			else{
				input.push_back(temp);
				temp=0;
			}
		}
		input.push_back(temp);
		return 0;
	}
	string itos(int i){
		stringstream s;
		s<<i;
		return s.str();
	}
};  

int main(){
	Solution test;
	test.setdata();
	test.largest();
	test.display();
	while(1);
	return 0;
}*/
//LeetCode
class Solution {
public:
	vector<int> setdata(){
		string temp;
		cin>>temp;
		return getInt(temp);
	}
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
    string largestNumber(vector<int> &num) {
        sort(num,0,num.size()-1);
        string output;
		bool iszero=true;
        for(int i=num.size()-1;i>=0;i--){
			if(num[i]!=0)
				iszero=false;
			string temp=itos(num[i]);
			output+=temp;
		}
		if(iszero)
			output='0';
		cout<<output<<endl;
		return output;
    }
    void sort(vector<int> &num,int lo,int hi){
		if(hi<=lo)
			return;
		int j=partition(num,lo,hi);
		sort(num,lo,j-1);
		sort(num,j+1,hi);
    }
    int partition(vector<int> &num,int lo,int hi){
		int i=lo,j=hi+1;
		int v=num[lo];
		while(true){
			while(largerNumber(num[++i],v)==-1)
				if(i==hi)
					break;
			while(largerNumber(v,num[--j])==-1)
				if(j==lo)
					break;
			if(i>=j)
				break;
			int temp=num[i];
			num[i]=num[j];
			num[j]=temp;
		}
		int temp=num[lo];
		num[lo]=num[j];
		num[j]=temp;
		return j;
	}
    int largerNumber(int num1,int num2){
		int length1=itos(num1).length();
		int length2=itos(num2).length();
		string snum1=itos(num1);
		string snum2=itos(num2);
		bool flag=true;
		while(flag){
			for(int i=0;i<length1&&i<length2;i++){
				if(snum1[i]>snum2[i])
					return 1;   //num1>num2
				else if(snum1[i]<snum2[i])
					return -1;   //num1<num2
			}
			if(length1==length2)
				return 0;//num1==num2
			else{
				string ssnum1,ssnum2;
				ssnum1+=snum1;
				ssnum1+=snum2;
				ssnum2+=snum2;
				ssnum2+=snum1;
				int slength=ssnum1.length();
				for(int i=0;i<slength;i++){
					if(ssnum1[i]>ssnum2[i])
						return 1;
					else if(ssnum1[i]<ssnum2[i])
						return -1;
				}
				return 0;
			}			
		}
		return 0;
	}
	string itos(int i){
		stringstream s;
		s<<i;
		return s.str();
	}
};
int main(){
	Solution test;
	test.largestNumber(test.setdata());
	while(1);
	return 0;
}
/*
出现错误的地方：输入为0,0时
这里面使用了一个快速排序算法
*/