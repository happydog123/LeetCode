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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
		result=helper(root,sum);
		return result;
    }
	vector<vector<int>> helper(TreeNode *root,int sum){
		vector<vector<int>> result;
		if(root==NULL)
			return result;
		if(root->left==NULL&&root->right==NULL){
			if(root->val==sum){
				vector<int> temp;
				temp.push_back(root->val);
				result.push_back(temp);
			}
			return result;
		}
		vector<vector<int>> temp1=helper(root->left,sum-root->val);
		vector<vector<int>> temp2=helper(root->right,sum-root->val);
		for(int i=0;i<temp1.size();i++){
			temp1[i].insert(temp1[i].begin(),root->val);
			result.push_back(temp1[i]);
		}
		for(int i=0;i<temp2.size();i++){
			temp2[i].insert(temp2[i].begin(),root->val);
			result.push_back(temp2[i]);
		}
		return result;
	}
};