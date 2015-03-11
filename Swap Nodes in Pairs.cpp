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
    ListNode *swapPairs(ListNode *head) {
		if(head==NULL||head->next==NULL)
			return head;
		ListNode* before=(ListNode*)malloc(sizeof(ListNode));
		ListNode* after=(ListNode*)malloc(sizeof(ListNode));
		ListNode* next=(ListNode*)malloc(sizeof(ListNode));
		ListNode* result_head=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
		before=head;
		after=head->next;
		next=head->next->next;
		result_head=after;
		after->next=before;
		before->next=NULL;
		while(next){
			if(next->next==NULL){
				before->next=next;
				break;
			}
			else{
				temp=before;
				before=next;
				after=next->next;
				next=next->next->next;
				after->next=before;
				before->next=NULL;
				temp->next=after;
			}
		}
		return result_head;
    }
};