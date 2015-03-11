#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        TreeNode *result=(TreeNode*)malloc(sizeof(TreeNode));
		result=helper(num,0,num.size()-1);
		return result;
    }

	TreeNode *helper(vector<int> &num, int begin, int end){
		if(begin<0||end>=num.size())
			return NULL;
		if(begin==end){
			TreeNode *result=(TreeNode*)malloc(sizeof(TreeNode));
			result->val=num[begin];
			result->left=NULL;
			result->right=NULL;
			return result;
		}
		if(end-begin==1){
			TreeNode *root=(TreeNode*)malloc(sizeof(TreeNode));
			root->val=num[begin];
			root->left=NULL;
			root->right=NULL;
			TreeNode *right=(TreeNode*)malloc(sizeof(TreeNode));
			right->val=num[end];
			right->left=NULL;
			right->right=NULL;
			root->right=right;
			return root;
		}
		int root_index=begin+(end-begin)/2;
		TreeNode *root=(TreeNode*)malloc(sizeof(TreeNode));
		root->val=num[root_index];
		root->left=helper(num,begin,root_index-1);
		root->right=helper(num,root_index+1,end);
		return root;
	}
};