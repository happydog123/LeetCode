#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
		if(height.size()==1)
			return 0;
		if(height.size()==2)
			return height[0]<height[1]?height[0]:height[1];
		int area=0;
		int begin=0;
		int end=height.size()-1;
		while(begin<end){
			if(end-begin==1){
				int temp=(end-begin)*(height[begin]<height[end]?height[begin]:height[end]);
				if(temp>area)
					area=temp;
				break;
			}
			else{
				int temp1=(end-begin-1)*(height[begin+1]<height[end]?height[begin+1]:height[end]);
				int temp2=(end-1-begin)*(height[begin]<height[end-1]?height[begin]:height[end-1]);
				int temp3=(end-begin)*(height[begin]<height[end]?height[begin]:height[end]);
				if(temp1>area&&temp1>temp2&&temp1>temp3){
					begin++;
					area=temp1;
				}
				else if(temp2>area&&temp2>temp1&&temp2>temp3){
					end--;
					area=temp2;
				}
				else{
					if(temp3>area&&temp3>temp1&&temp3>temp2)
						area=temp3;
					if(height[begin]<height[end])//要将少的那个往前走，不可能去走高度大的那一方
						begin++;
					else
						end--;
				}
			}
		}
		return area;
    }
};