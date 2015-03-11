#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> left;
		vector<int> right;
		int result=0;
		for(int i=0;i<ratings.size();i++){
			if(i==0)
				left.push_back(1);
			else{
				if(ratings[i]>ratings[i-1])
					left.push_back(left[i-1]+1);
				else
					left.push_back(1);
			}
		}
		for(int i=ratings.size()-1;i>=0;i--){
			if(i==ratings.size()-1)
				right.push_back(1);
			else{
				if(ratings[i]>ratings[i+1])
					right.push_back(right[right.size()-1]+1);
				else
					right.push_back(1);
			}
		}
		reverse(right.begin(),right.end());
		for(int i=0;i<left.size();i++){
			if(left[i]>right[i])
				result=result+left[i];
			else
				result=result+right[i];
		}
		return result;
    }
};