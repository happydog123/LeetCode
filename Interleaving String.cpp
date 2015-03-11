#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
private:
	map<int,map<int,map<int,int>>> record;
public:
    bool isInterleave(string s1, string s2, string s3) {
        return helper(s1,s2,s3);
    }

	bool helper(string s1,string s2,string s3){
		if(s3.length()!=s1.length()+s2.length()){
			if(s1.length()!=0&&s2.length()!=0&&s3.length()!=0)
				record[s1.length()-1][s2.length()-1][s3.length()-1]=0;
			return false;
		}
		if(s3.length()==0)
			return true;
		if(s1.length()==0){
			if(s2==s3)
				return true;
			else
				return false;
		}
		if(s2.length()==0){
			if(s1==s3)
				return true;
			else
				return false;
		}
		map<int,map<int,map<int,int>>>::iterator it1;
		it1=record.find(s1.length()-1);
		if(it1!=record.end()){
			map<int,map<int,int>>::iterator it2;
			it2=it1->second.find(s2.length()-1);
			if(it2!=it1->second.end()){
				map<int,int>::iterator it3;
				it3=it2->second.find(s3.length()-1);
				if(it3!=it2->second.end()&&it3->second==0);
					return false;
				}
		}
		int ls1=s1.length();
		int ls2=s2.length();
		int ls3=s3.length();
		string ts1="";
		if(ls1>1)
			ts1=s1.substr(1,ls1-1);
		string ts2="";
		if(ls2>1)
			ts2=s2.substr(1,ls2-1);
		string ts3="";
		if(ls3>1)
			ts3=s3.substr(1,ls3-1);
		if(s3[0]==s1[0]){
			if(helper(ts1,s2,ts3))
				return true;
			else{
				if(s3[0]==s2[0]){
					if(helper(s1,ts2,ts3))
						return true;
					else{
						record[s1.length()-1][s2.length()-1][s3.length()-1]=0;
						if(ts2.length()!=0&&ts3.length()!=0)
							record[s1.length()-1][ts2.length()-1][ts3.length()-1]=0;
						return false;
					}
				}
				else{
					record[s1.length()-1][s2.length()-1][s3.length()-1]=0;
					return false;
				}
			}
		}
		else if(s3[0]==s2[0]){
			if(helper(s1,ts2,ts3))
				return true;
			else{
				record[s1.length()-1][s2.length()-1][s3.length()-1]=0;
				if(ts2.length()!=0&&ts3.length()!=0)
					record[s1.length()-1][ts2.length()-1][ts3.length()-1]=0;
				return false;
			}
		}
		else{
			record[s1.length()-1][s2.length()-1][s3.length()-1]=0;
			return false;
		}
	}
};
int main(){
	string s1,s2,s3;
	Solution test;
	while(1){
		cin>>s1;
		cin>>s2;
		cin>>s3;
		if(test.isInterleave(s1,s2,s3))
			cout<<"true";
		else
			cout<<"false";
	}
	return 0;
}
/*
一开始只是用回溯递归，大数据集不通过，后来用vector进行记忆，Memory Limit超过了，最后把vector
换成了map通过了哈哈哈*/