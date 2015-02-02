#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
		if(num.size()!=0){
			int min=num[0];
			for(int i=1;i<num.size();i++){
				if(num[i]<min){
					return num[i];
				}
			}
			return min;
		}
		return -1;
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
	cout<<test.findMin(setdata())<<endl;
	while(1);
	return -1;
}