#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

struct ListNode {
	 int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(k==0)
			return head;
		if(head==NULL)
			return head;
		stack<ListNode*> s;
		ListNode* temp1=(ListNode*)malloc(sizeof(ListNode*));
		temp1=head;
		int num=0;
		while(temp1){
			s.push(temp1);
			temp1=temp1->next;
			num++;
		}
		k=k%num;
		if(k==0)
			return head;
		ListNode* temp2=(ListNode*)malloc(sizeof(ListNode*));
		for(int i=0;i<k;i++){
			ListNode* temp3=(ListNode*)malloc(sizeof(ListNode*));
			temp3=s.top();
			s.pop();
			if(i==0){
				temp3->next=NULL;
				temp2=temp3;
			}
			else{
				temp3->next=temp2;
				temp2=temp3;
			}
		}
		ListNode* result_head=(ListNode*)malloc(sizeof(ListNode*));
		result_head=temp2;
		while(temp2->next){
			temp2=temp2->next;
		}
		temp2->next=head;
		while(temp2->next!=result_head){
			temp2=temp2->next;
		}
		temp2->next=NULL;
		return result_head;
    }
};