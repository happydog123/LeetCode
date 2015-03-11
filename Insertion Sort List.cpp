#include<iostream>
using namespace std;
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
		if(head==NULL)
			return NULL;
        ListNode* result_list=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp1=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp2=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp3=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp4=(ListNode*)malloc(sizeof(ListNode));
		result_list=head;
		temp1=head->next;
		result_list->next=NULL;
		while(temp1){
			temp4=temp1;
			temp1=temp1->next;
			temp4->next=NULL;
			temp2=result_list;
			temp3=result_list;
			bool flag=false;
			int i=0;
			while(temp2){
				if(temp2->val>temp4->val){
					if(i==0){
						temp4->next=temp2;
						result_list=temp4;
						flag=true;
						break;
					}
					else{
						temp4->next=temp2;
						temp3->next=temp4;
						flag=true;
						break;
					}
				}
				temp3=temp2;
				temp2=temp2->next;
				i++;
			}
			if(!flag)
				temp3->next=temp4;
		}
		return result_list;
    }
};