#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
		vector<int>	number;
		vector<int> count;
		int i,j;
		int size=num.size();
		for(i=0;i<size;i++){
			bool flag=false;
			for(j=0;j<number.size();j++){
				if(number[j]==num[i]){
					count[j]++;
					flag=true;
					if(count[j]>(size/2))
						return number[j];
					break;
				}
			}
			if(flag==false){
				number.push_back(num[i]);
				count.push_back(1);
			}
		}
		return num[0];
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
	cout<<test.majorityElement(setdata())<<endl;
	while(1);
	return 0;
}
/*
¿¼ÂÇ¼«¶ËÊäÈë£º1
*/