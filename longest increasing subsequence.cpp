#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lis(vector<int> v,int n){
	if(n==1)
		return 1;
	vector<int> t;
	for(int i=2;i<n;i++){
		if(v[i-1]<v[n-1])
			t.push_back(lis(v,i)+1);
		else
			t.push_back(lis(v,i));
	}
	t.push_back(1);
	return *max_element(t.begin(),t.end());
}

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
	vector<int> v;
	while(1){
		v=setdata();
		cout<<lis(v,v.size())<<endl;
	}
	return 0;
}

/*
other answer:
#include <iostream>
using namespace std;

int lis(int A[], int n){
    int *d = new int[n];
    int len = 1;
    for(int i=0; i<n; ++i){
        d[i] = 1;
        for(int j=0; j<i; ++j)
            if(A[j]<=A[i] && d[j]+1>d[i])
                d[i] = d[j] + 1;
        if(d[i]>len) len = d[i];
    }
    delete[] d;
    return len;
}
int main(){
    int A[] = {
        5, 3, 4, 8, 6, 7
    };
    cout<<lis(A, 6)<<endl;
    return 0;
}
*/
/*
关于此题的其他解法：http://www.felix021.com/blog/read.php?1587
或者排序+LCS*/