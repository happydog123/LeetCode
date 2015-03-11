#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
			return;
		TreeLinkNode* temp=(TreeLinkNode*)malloc(sizeof(TreeLinkNode));
		temp=root->next;
		while(temp!=NULL){
			if(temp->left!=NULL){
				temp=temp->left;
				break;
			}
			if(temp->right!=NULL){
				temp=temp->right;
				break;
			}
			temp=temp->next;
		}
		if(root->right!=NULL)
			root->right->next=temp;
		if(root->left!=NULL){
			root->left->next=root->right==NULL?temp:root->right;
		}
		connect(root->right);
		connect(root->left);
    }
};

/*
参考的别人的程序*/