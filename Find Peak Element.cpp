#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
		for(int i=0;i<num.size();i++){
			if(i==0){
				if(num.size()==1)
					return i;
				else{
					if(num[i]>num[i+1])
						return i;
				}
			}
			else if(i==num.size()-1){
				if(num.size()==1)
					return i;
				else{
					if(num[i]>num[i-1])
						return i;
				}
			}
			else {
				if(num[i]>num[i-1]&&num[i]>num[i+1])
					return i;
			}
		}
        return 0;
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
	cout<<test.findPeakElement(setdata())<<endl;
	while(1);
	return 0;
}