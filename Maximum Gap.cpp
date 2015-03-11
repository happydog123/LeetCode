#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int> &num) {
		if(num.size()<2)
			return 0;
		if(num.size()==2){
			sort(num.begin(),num.end());
			return num[1]-num[0];
		}
		int min=num[0];
		int max=num[0];
		for(int i=0;i<num.size();i++){
			if(min>num[i])
				min=num[i];
			if(max<num[i])
				max=num[i];
		}
		int len=(max-min)/(num.size()-1);
		if(((max-min)%(num.size()-1))>0)
			len++;
		int count=(max-min)/len+1;
		//cout<<"bucket count "<<count<<endl;
		vector<vector<int>> bucket;
		for(int i=0;i<count;i++){
			vector<int> temp;
			temp.push_back(-1);
			temp.push_back(-1);
			bucket.push_back(temp);
		}
		for(int i=0;i<num.size();i++){
			int loc=(num[i]-min)/len;
			//cout<<num[i]<<"  int location "<<loc<<endl;
			if(bucket[loc][0]==-1&&bucket[loc][1]==-1){
				bucket[loc][0]=num[i];
				bucket[loc][1]=num[i];
			}
			else{
				if(bucket[loc][0]>num[i])
					bucket[loc][0]=num[i];
				if(bucket[loc][1]<num[i])
					bucket[loc][1]=num[i];
			}
		}
		/*for(int i=0;i<bucket.size();i++){
			cout<<bucket[i][0]<<"  "<<bucket[i][1]<<endl;
		}*/
		int result=(max-min)/(num.size()-1);
		//cout<<"the begin result is "<<result<<endl;
		for(int i=0;i<bucket.size();i++){
			if(bucket[i][0]==-1&&bucket[i][1]==-1)
				;
			else{
				for(int j=i+1;j<bucket.size();j++){
					if(bucket[j][0]==-1&&bucket[j][1]==-1)
						;
					else{
						if(bucket[j][0]-bucket[i][1]>result){
							result=bucket[j][0]-bucket[i][1];
							//cout<<"result "<<result<<" beween bucket "<<i<<" and bucket "<<j<<endl;
							break;
						}
						else
							break;
					}
				}
			}
		}
		return result;

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
	int result;
	vector<int> input;
	Solution test;
	while(1){
		input=getInt("15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740");
		cout<<test.maximumGap(input)<<endl;
		while(1);
	}
	return 0;
}