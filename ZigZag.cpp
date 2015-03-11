#include <iostream>
#include <vector>
#include <string>
using namespace std;
int turn;//1 means '+', -1 means '-'
int temp;

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

int zigzag(vector<int> v,int n){
	if(n==1){
		temp=v[0];
		return 1;
	}
	if(n==2){
		temp=v[1];
		if(v[1]>v[0])
			turn=1;
		else if(v[1]<v[0])
			turn=-1;
		else
			turn=0;
		return 2;
	}

	int k=zigzag(v,n-1);
	if(turn==1){
		if(v[n-1]>temp){
			temp=v[n-1];
			return k;
		}
		else if(v[n-1]<temp){
			temp=v[n-1];
			turn=-1;
			return k+1;
		}
		else{
			return k;
		}
	}
	else if(turn==-1){
		if(v[n-1]>temp){
			temp=v[n-1];
			turn=1;
			return k+1;
		}
		else if(v[n-1]<temp){
			temp=v[n-1];
			return k;
		}
		else{
			return k;
		}
	}
	else{
		if(v[n-1]>temp){
			temp=v[n-1];
			turn=1;
			return 2;
		}
		else if(v[n-1]<temp){
			temp=v[n-1];
			turn=-1;
			return 2;
		}	
		return 1;
	}
}

int main(){
	vector<int> v;
	while(1){
		v=setdata();
		turn=0;
		temp=v[0];
		cout<<zigzag(v,v.size())<<endl;
	}
	return 0;
}