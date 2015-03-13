#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL)
			return head;
		if(n==0)
			return head;
		stack<ListNode*> origin;
		ListNode* head1=(ListNode*)malloc(sizeof(ListNode));
		head1=head;
		while(head1){
			origin.push(head1);
			head1=head1->next;
		}
		stack<ListNode*> help;
		for(int i=0;i<n;i++){
			head1=origin.top();
			help.push(head1);
			origin.pop();
		}
		help.pop();
		if(origin.empty()){
			if(help.empty())
				return NULL;
			else
				return help.top();
		}
		else{
			head1=origin.top();
			head1->next=NULL;
			while(!help.empty()){
				head1=origin.top();
				head1->next=help.top();
				origin.push(help.top());
				help.pop();
			}
			return head;
		}
    }
};
/*
Wrong case: {1},1*/