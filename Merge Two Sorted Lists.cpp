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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;
		ListNode* result_head=(ListNode*)malloc(sizeof(ListNode));
		int count=0;
		ListNode* temp1=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp2=(ListNode*)malloc(sizeof(ListNode));
		ListNode* result_temp=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
		temp1=l1;
		temp2=l2;
		while(l1&&l2){
			if(l1->val<l2->val){
				temp=l1;
				l1=l1->next;
				temp->next=NULL;
			}
			else{
				temp=l2;
				l2=l2->next;
				temp->next=NULL;
			}
			if(count==0){
				result_head=temp;
				result_temp=temp;
			}
			else{
				result_temp->next=temp;
				result_temp=temp;
			}
			count++;
		}
		if(l1!=NULL)
			result_temp->next=l1;
		else if(l2!=NULL)
			result_temp->next=l2;
		return result_head;
    }
};