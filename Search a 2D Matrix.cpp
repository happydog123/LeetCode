#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		for(int i=0;i<matrix.size();i++){
			if(target>=matrix[i][0]&&target<=matrix[i][matrix[i].size()-1])
				return BinarySearch(matrix[i],target);
		}
		return false;
    }

	bool BinarySearch(vector<int> v,int value){
		int len=v.size();
		if(len<=0)
			return false;
		int low=0;
		int high=len-1;
		while(low<=high){
			int mid=low+(high-low)/2;
			if(v[mid]==value)
				return true;
			else if(v[mid]>value)
				high=mid-1;
			else
				low=mid+1;
		}
		return false;
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
	int i;
	int n;
	while(1){
		cin>>i;
		cin>>n;
		vector<vector<int>> input;
		for(int i=0;i<n;i++){
			vector<int> input1;
			input1=setdata();
			input.push_back(input1);
		}
		if(test.searchMatrix(input,i))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}