#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct ListNode {
	 int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		if(lists.size()==0)
			return NULL;
		ListNode* result_head=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp1=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp_max=(ListNode*)malloc(sizeof(ListNode));
		vector<ListNode*> temp_list;
		for(int i=0;i<lists.size();i++){
			ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
			temp=lists[i];
			temp_list.push_back(temp);
		}
		bool flag=true;
		int count=0;
		result_head=NULL;
		while(flag){
			temp_max=NULL;
			int con=0;
			for(int i=0;i<temp_list.size();i++){
				if(temp_list[i]!=NULL){
					if(temp_max==NULL){
						temp_max=temp_list[i];
						con=i;
					}
					else{
						if(temp_max->val<temp_list[i]->val){
							temp_max=temp_list[i];
							con=i;
						}
					}
				}
			}
			if(temp_max==NULL)
				flag=false;
			else{
				if(count==0){
					result_head=temp_max;
					temp1=temp_max;
					temp_list[con]=temp_list[con]->next;
					temp1->next==NULL;
				}
				else{
					temp1->next=temp_max;
					temp1=temp_max;
					temp_list[con]=temp_list[con]->next;
					temp1->next=NULL;
				}
				count++;
			}
		}
		return result_head;
    }
};