#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n)
			return head;
		ListNode *help1=(ListNode*)malloc(sizeof(ListNode));
		ListNode* first=(ListNode*)malloc(sizeof(ListNode));
		help1=head;
		first=head;
		int k=1;
		while(help1){
			if(k==m)
				break;
			first=help1;
			help1=help1->next;
			k++;
		}
		ListNode *help2=(ListNode*)malloc(sizeof(ListNode));
		k++;
		while(k<=n){
			if(m!=1){
				help2=help1->next;
				if(help2==NULL)
					break;
				help1->next=help2->next;
				help2->next=first->next;
				first->next=help2;
			}
			else{
				help2=help1->next;
				if(help2==NULL)
					break;
				help1->next=help2->next;
				help2->next=first;
				first=help2;
			}
			k++;
		}
		if(m==1)
			return first;
		else
			return head;
    }
};
/*只写了一遍就AC的那种感觉就是：我真是个天才哈哈哈*/