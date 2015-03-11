#include<iostream>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL)
			return head;
		if(head->next==NULL)
			return head;
		ListNode *left=(ListNode*)malloc(sizeof(ListNode));
		ListNode *right=(ListNode*)malloc(sizeof(ListNode));
		ListNode *left_head=(ListNode*)malloc(sizeof(ListNode));
		ListNode *right_head=(ListNode*)malloc(sizeof(ListNode));
		ListNode *help=(ListNode*)malloc(sizeof(ListNode));
		help=head;
		left=NULL;
		right=NULL;
		left_head=NULL;
		right_head=NULL;
		while(help){
			if(help->val<x){
				if(left_head==NULL){
					left_head=help;
					left=help;
				}
				else{
					left->next=help;
					left=help;
				}
			}
			else{
				if(right_head==NULL){
					right_head=help;
					right=help;
				}
				else{
					right->next=help;
					right=help;
				}
			}
			help=help->next;
		}
		if(left!=NULL)
			left->next=NULL;
		if(right!=NULL)
			right->next=NULL;
		if(left!=NULL){
			left->next=right_head;
			return left_head;
		}
		else{
			return right_head;
		}
    }
};