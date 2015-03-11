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
    void reorderList(ListNode *head) {
		if(head==NULL||head->next==NULL)
			return;
		stack<ListNode*> v;
		ListNode* temp1=(ListNode*)malloc(sizeof(ListNode));
		temp1=head;
		ListNode* temp2=(ListNode*)malloc(sizeof(ListNode));
		temp2=head;
		while(temp2){
			v.push(temp2);
			temp2=temp2->next;
		}
		ListNode* temp4=(ListNode*)malloc(sizeof(ListNode));
		int count=0;
		while(!v.empty()){
			ListNode* temp3=(ListNode*)malloc(sizeof(ListNode));
			temp3=v.top();
			v.pop();
			if(temp1){
				if(count==0||temp4!=temp1){
					temp3->next=temp1->next;
					temp1->next=temp3;
					temp1=temp3->next;
				}
				else{
					temp1->next=NULL;
					break;
				}
			}
			else
				break;
			temp4=temp3;
			count++;
		}
    }
};