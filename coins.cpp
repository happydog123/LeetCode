#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int min(int i){
	if(i==0)
		return 0;
	vector<int> v;
	if(i-1>=0)
		v.push_back(min(i-1)+1);
	if(i-3>=0)
		v.push_back(min(i-3)+1);
	if(i-5>=0)
		v.push_back(min(i-5)+1);
	return *min_element(v.begin(),v.end());
}
int main(){
	int input;
	while(1){
		cin>>input;
		cout<<min(input)<<endl;
	}
	return 0;
}