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
    ListNode *deleteDuplicates(ListNode *head) {
		if(head==NULL||head->next==NULL)
			return head;
		ListNode* temp1=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp2=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp3=(ListNode*)malloc(sizeof(ListNode));
		temp1=head;
		temp2=head; 
		temp3=head;
		temp1=temp1->next;
		while(temp1){
			if(temp1->val!=temp3->val){
				temp2->next=temp1;
				temp2=temp2->next;
				temp3=temp1;
			}
			temp1=temp1->next;
		}
		temp2->next=NULL;
		return head;
    }
};