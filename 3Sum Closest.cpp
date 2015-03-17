#include<iostream>
#include<vector>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		if(num.size()==3)
			return num[0]+num[1]+num[2];
		sort(num.begin(),num.end());
		int result=num[0]+num[1]+num[2];
		int targetr=abs(num[0]+num[1]+num[2]-target);

		for(int i=0;i<=num.size()-3;i++){
			if(i!=0&&num[i]==num[i-1])
				continue;
			//在这里进行了裁剪
			if((num[i]+num[num.size()-2]+num[num.size()-1]-target<0)||(num[i]+num[i+1]+num[i+2]-target>0)){
				if(abs(num[i]+num[i+1]+num[i+2]-target)<targetr){
					targetr=abs(num[i]+num[i+1]+num[i+2]-target);
					result=num[i]+num[i+1]+num[i+2];
				}
				if(abs(num[i]+num[num.size()-2]+num[num.size()-1]-target)<targetr){
					targetr=abs(num[i]+num[num.size()-2]+num[num.size()-1]-target);
					result=num[i]+num[num.size()-2]+num[num.size()-1];
				}
				continue;
			}

			for(int j=i+1;j<=num.size()-2;j++){
				if(j!=i+1&&num[j]==num[j-1])
					continue;
				//在这里进行了裁剪
				if((num[i]+num[j]+num[num.size()-1]-target<0)||(num[i]+num[j]+num[j+1]-target>0)){
					if(abs(num[i]+num[j]+num[j+1]-target)<targetr){
						targetr=abs(num[i]+num[j]+num[j+1]-target);
						result=num[i]+num[j]+num[j+1];
					}
					if(abs(num[i]+num[j]+num[num.size()-1]-target)<targetr){
						targetr=abs(num[i]+num[j]+num[num.size()-1]-target);
						result=num[i]+num[j]+num[num.size()-1];
					}
					continue;
				}

				int tempk;
				for(int k=j+1;k<num.size();k++){
					if(k!=j+1&&num[k]==num[k-1])
						continue;
					tempk=num[i]+num[j]+num[k]-target;
					if(tempk==0)
						return num[i]+num[j]+num[k];
					else{
						if(abs(tempk)<targetr){
							result=num[i]+num[j]+num[k];
							targetr=abs(tempk);
						}
					}
				}
			}
		}
		return result;
    }
};

/*
又是一道做了三遍终于做出来的题，噢耶*/