#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
	map<TreeNode*,vector<int>> m;
	int result;
public:
    int maxPathSum(TreeNode *root) {
		if(root==NULL)
			return 0;
        helper_fill(root);
		result=root->val;
		map<TreeNode*,vector<int>>::iterator it=m.begin();
		helper_search(root);
		return result;
    }
	void helper_fill(TreeNode *root){
		if(root==NULL)
			return;
		if(root->left==NULL&&root->right==NULL){
			m[root].push_back(root->val);//left
			m[root].push_back(root->val);//right
			return;
		}
		if(root->left==NULL){
			m[root].push_back(root->val);
			helper_fill(root->right);
			if(m[root->right][0]>m[root->right][1]){
				if(m[root->right][0]+root->val>root->val)
					m[root].push_back(m[root->right][0]+root->val);
				else
					m[root].push_back(root->val);
			}
			else{
				if(m[root->right][1]+root->val>root->val)
					m[root].push_back(m[root->right][1]+root->val);
				else
					m[root].push_back(root->val);
			}
			return;
		}
		if(root->right==NULL){
			helper_fill(root->left);
			if(m[root->left][0]>m[root->left][1]){
				if(m[root->left][0]+root->val>root->val)
					m[root].push_back(m[root->left][0]+root->val);
				else
					m[root].push_back(root->val);
			}
			else{
				if(m[root->left][1]+root->val>root->val)
					m[root].push_back(m[root->left][1]+root->val);
				else
					m[root].push_back(root->val);
			}
			m[root].push_back(root->val);
			return;
		}
		helper_fill(root->left);
		helper_fill(root->right);
		if(m[root->right][0]>m[root->right][1]){
			if(m[root->right][0]+root->val>root->val)
				m[root].push_back(m[root->right][0]+root->val);
			else
				m[root].push_back(root->val);
		}
		else{
			if(m[root->right][1]+root->val>root->val)
				m[root].push_back(m[root->right][1]+root->val);
			else
				m[root].push_back(root->val);
		}
		if(m[root->left][0]>m[root->left][1]){
			if(m[root->left][0]+root->val>root->val)
				m[root].push_back(m[root->left][0]+root->val);
			else
				m[root].push_back(root->val);
		}
		else{
			if(m[root->left][1]+root->val>root->val)
				m[root].push_back(m[root->left][1]+root->val);
			else
				m[root].push_back(root->val);
		}
		return;
	}
	void helper_search(TreeNode *root){
		if(root==NULL)
			return;
		helper_search(root->left);
		helper_search(root->right);
		map<TreeNode*,vector<int>>::iterator it=m.find(root);
		if(it->second[0]>result)
			result=it->second[0];
		if(it->second[1]>result)
			result=it->second[1];
		if(it->second[0]+it->second[1]-it->first->val>result)
			result=it->second[0]+it->second[1]-it->first->val;
		if(it->first->val>result)
			result=it->first->val;
		return;
	}
};