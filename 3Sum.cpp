#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(),num.end());
        vector<vector<int>> result;
		int i=0;
		int lt;
		while(!num.empty()){
			int t=num[num.size()-1];
			vector<vector<int>> temp;
			num.pop_back();
			if(i==0||t!=lt){
				temp=twoSum(num,0-t);
				for(int i=0;i<temp.size();i++){
					temp[i].push_back(t);
					sort(temp[i].begin(),temp[i].end());
					result.push_back(temp[i]);
				}
			}
			i++;
			lt=t;
		}
		/*for(int i=0;i<result.size();i++)
			sort(result[i].begin(),result[i].end());*/
		/*sort(result.begin(),result.end());
		result.erase(unique(result.begin(),result.end()),result.end());*/
		return result;
    }

	vector<vector<int>> twoSum(vector<int> &numbers, int target) {
        vector<vector<int>> result;
		map<int,int> m;
		map<vector<int>,int> mi;
		for(int i=0;i<numbers.size();i++){
			if(m.find(target-numbers[i])!=m.end()){
				vector<int> temp;
				if(numbers[i]<target-numbers[i]){
					temp.push_back(numbers[i]);
					temp.push_back(target-numbers[i]);
				}
				else{
					temp.push_back(target-numbers[i]);
					temp.push_back(numbers[i]);
				}
				if(mi.find(temp)==mi.end()){
					result.push_back(temp);
					mi[temp]=i;
				}
			}
			else{
				m[numbers[i]]=i;
			}
		}
		return result;
    }
};

int main(){
	int n;
	Solution test;
	while(1){
		cin>>n;
		vector<int> input;
		vector<vector<int>> result;
		int t;
		for(int i=0;i<n;i++){
			cin>>t;
			input.push_back(t);
		}
		result=test.threeSum(input);
		for(int i=0;i<result.size();i++){
			for(int j=0;j<result[i].size();j++)
				cout<<result[i][j]<<" , ";
			cout<<endl;
		}
	}
}