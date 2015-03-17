#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> result;
		if(num.size()<4)
			return result;
		sort(num.begin(),num.end()); 
		for(int i=0;i<=num.size()-4;i++){
			if(num[i]+num[i+1]+num[i+2]+num[i+3]>target)
				break;
			if(num[i]+num[num.size()-3]+num[num.size()-2]+num[num.size()-1]<target)
				continue;
			if(i!=0&&num[i]==num[i-1])
				continue;

			for(int j=i+1;j<=num.size()-3;j++){
				if(num[i]+num[j]+num[j+1]+num[j+2]>target)
					break;
				if(num[i]+num[j]+num[num.size()-2]+num[num.size()-1]<target)
					continue;
				if(j!=i+1&&num[j]==num[j-1])
					continue;

				for(int k=j+1;k<=num.size()-2;k++){
					if(num[i]+num[j]+num[k]+num[k+1]>target)
						break;
					if(num[i]+num[j]+num[k]+num[num.size()-1]<target)
						continue;
					if(k!=j+1&&num[k]==num[k-1])
						continue;

					for(int m=k+1;m<=num.size()-1;m++){
						if(num[i]+num[j]+num[k]+num[m]>target)
							break;
						if(m!=k+1&&num[m]==num[m-1])
							continue;
						if(num[i]+num[j]+num[k]+num[m]==target){
							vector<int> temp;
							temp.push_back(num[i]);
							temp.push_back(num[j]);
							temp.push_back(num[k]);
							temp.push_back(num[m]);
							result.push_back(temp);
						}
					}
				}
			}
		}
		return result;
    }
};
/*
什么时候break，什么时候continue会用错*/