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
		ListNode* result_head=(ListNode*)malloc(sizeof(ListNode));
		result_head=NULL;
		temp1=head;
		temp2=head;
		int count=0;
		while(temp1){
			int k=temp1->val;
			bool flag=true;
			temp3=temp1;
			temp1=temp1->next;
			while(temp1&&temp1->val==k){
				flag=false;
				temp1=temp1->next;
			}
			if(flag){
				if(count==0){
					result_head=temp3;
					temp3->next=NULL;
					temp2=temp3;
				}
				else{
					temp2->next=temp3;
					temp2=temp3;
				}
				count++;
			}
			else{
				if(temp1==NULL)
					break;
			}
		}
		temp2->next=NULL;
		return result_head;
    }
};