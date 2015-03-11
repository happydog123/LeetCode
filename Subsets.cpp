#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
class Solution {
public:
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
		if(num1>num2)
			return 1;
		if(num1<num2)
			return -1;
		return 0;
	}
	void printvector(vector<int> &S){
		for(int i=0;i<S.size();i++){
			cout<<S[i]<<",";
		}
		cout<<endl;
	}
    vector<vector<int> > subsets(vector<int> &S) {
		int len=S.size();
		sort(S,0,S.size()-1);
		vector<vector<int>> result(1);
		for(int i=0;i<len;i++){
			int resSize=result.size();
			for(int j=0;j<resSize;j++){
				result.push_back(result[j]);
				result.back().push_back(S[i]);
			}
		}
		return result;
    }
	void print(vector<vector<int>> input){
		for(int i=0;i<input.size();i++){
			for(int j=0;j<input[i].size();j++){
				cout<<input[i][j]<<",";
			}
			cout<<endl;
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
		//test.subsets(input);
		test.print(test.subsets(input));
	}
	return 0;
}
/*
不要自己再去写quicksort了
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int len = S.size();
        //第一层先加入一个空集合
        vector<vector<int>> res(1);
        sort(S.begin(), S.end());
        
        for(int i = 0; i < len; i++)
        {
            int resSize = res.size();
            for(int j = 0; j < resSize; j++)
            {
                //复制一遍当前集合，并在其后添加元素S[i]
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        
        return res;
    }
};*/