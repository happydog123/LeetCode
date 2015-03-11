#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL)
			return NULL;
		if(head->next==NULL){
			TreeNode *root=(TreeNode*)malloc(sizeof(TreeNode));
			root->val=head->val;
			root->left=NULL;
			root->right=NULL;
			return root;
		}
		if(head->next->next==NULL){
			TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
			root->val=head->val;
			root->left=NULL;
			root->right=NULL;
			TreeNode* right=(TreeNode*)malloc(sizeof(TreeNode));
			right->val=head->next->val;
			right->left=NULL;
			right->right=NULL;
			root->right=right;
			return root;
		}
		ListNode *nleft=(ListNode*)malloc(sizeof(ListNode));
		nleft=Getleft(head);
		ListNode *nmiddle=(ListNode*)malloc(sizeof(ListNode));
		nmiddle=nleft->next;
		ListNode *nright=(ListNode*)malloc(sizeof(ListNode));
		nright=nleft->next->next;
		nleft->next=NULL;
		TreeNode *tmiddle=(TreeNode*)malloc(sizeof(TreeNode));
		tmiddle->val=nmiddle->val;
		TreeNode *tleft=(TreeNode*)malloc(sizeof(TreeNode));
		TreeNode *tright=(TreeNode*)malloc(sizeof(TreeNode));
		tleft=sortedListToBST(head);
		tright=sortedListToBST(nright);
		tmiddle->left=tleft;
		tmiddle->right=tright;
		return tmiddle;
    }

	ListNode *Getleft(ListNode *head){
		ListNode *next=(ListNode*)malloc(sizeof(ListNode));
		ListNode *current=(ListNode*)malloc(sizeof(ListNode));
		ListNode *pre=(ListNode*)malloc(sizeof(ListNode));
		next=head;
		current=head;
		pre=head;
		while(next!=NULL){
			next=next->next;
			if(next==NULL)
				break;
			next=next->next;
			if(next==NULL)
				break;
			pre=head;
			head=head->next;
		}
		return pre;
	}
};