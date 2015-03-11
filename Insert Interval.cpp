#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result;
		intervals.push_back(newInterval);
		sort(intervals.begin(),intervals.end(),comp);
		for(int i=0;i<intervals.size();i++){
			if(result.empty())
				result.push_back(intervals[i]);
			else{
				Interval temp=result[result.size()-1];
				if(intervals[i].start>temp.end)
					result.push_back(intervals[i]);
				else if(intervals[i].end>temp.end){
					Interval k(temp.start,intervals[i].end);
					result.pop_back();
					result.push_back(k);
				}
			}
		}
		return result;

    }
	static bool comp(Interval a, Interval b){
		return a.start<b.start;
	}
};

  vector<Interval> input(){
	 int count;
	 cin>>count;
	 int low=0,high=0;
	 vector<Interval> result;
	 for(int i=0;i<count;i++){
		 cin>>low>>high;
		 Interval temp(low,high);
		 result.push_back(temp);
	 }
	 return result;
 }

 void print(vector<Interval> input){
	 for(int i=0;i<input.size();i++){
		 cout<<"{ ";
		 cout<<input[i].start<<" , "<<input[i].end<<" }, ";
	 }
	 cout<<endl;
 }

 static bool comp(Interval a, Interval b){
	 return a.start<b.start;
 }

 vector<Interval> sorti(vector<Interval> input){
	 sort(input.begin(),input.end(),comp);
	 return input;
 }

  int main(){
	 vector<Interval> inputt;
	 inputt=input();
	 int insert_begin;
	 int insert_end;
	 cin>>insert_begin;
	 cin>>insert_end;
	 Interval temp(insert_begin,insert_end);
	 Solution test;
	 inputt=test.insert(inputt,temp);
	 print(inputt);
	 while(1);
 }