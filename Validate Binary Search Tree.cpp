#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(root==NULL)
			return true;
		return isLessValid(root->left,root->val)&&isGreaterValid(root->right,root->val)&&isValidBST(root->left)&&isValidBST(root->right);
    }

	bool isLessValid(TreeNode *root,int val){
		if(root==NULL)
			return true;
		return root->val<val&&isLessValid(root->left,val)&&isLessValid(root->right,val);
	}

	bool isGreaterValid(TreeNode *root,int val){
		if(root==NULL)
			return true;
		return root->val>val&&isGreaterValid(root->left,val)&&isGreaterValid(root->right,val);
	}
};