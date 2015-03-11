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
private:
	vector<TreeNode*> vt;
public:
    void recoverTree(TreeNode *root) {
        helper(root);
		int m=0,n=0;
		int i=0;
		while(i<vt.size()){
			if(vt[i]->val>vt[i+1]->val){
				m=i;
				break;
			}
			i++;
		}
		i++;
		while(i<vt.size()){
			if(vt[i]->val>vt[m]->val){
				n=i-1;
				break;
			}
			i++;
		}
		if(i==vt.size())
			n=vt.size()-1;
		int temp=vt[m]->val;
		vt[m]->val=vt[n]->val;
		vt[n]->val=temp;
    }
	void helper(TreeNode* root){
		if(root!=NULL){
			helper(root->left);
			vt.push_back(root);
			helper(root->right);
		}
	}
};