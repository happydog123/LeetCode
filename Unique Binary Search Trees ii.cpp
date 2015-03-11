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
    vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode *> result;
		if(n==0){
			result.push_back(NULL);
			return result;
		}
        vector<int> vt;
		for(int i=1;i<=n;i++)
			vt.push_back(i);
		result=helper(vt);
		return result;
    }
	vector<TreeNode *> helper(vector<int> vt){
		if(vt.size()==0){
			vector<TreeNode*> result;
			result.push_back(NULL);//好神奇，一开始没加这句话就是错的，加了就可以了哈哈哈
			return result;
		}
		if(vt.size()==1){
			TreeNode *temp=(TreeNode*)malloc(sizeof(TreeNode));
			temp->val=vt[0];
			temp->left=NULL;
			temp->right=NULL;
			vector<TreeNode*> result;
			result.push_back(temp);
			return result;
		}
		vector<int> left;
		vector<int> right;
		vector<TreeNode*> result;
		for(int i=1;i<vt.size();i++)
			right.push_back(vt[i]);
		for(int i=0;i<vt.size();i++){
			vector<TreeNode*> tleft=helper(left);
			vector<TreeNode*> tright=helper(right);
			for(int j=0;j<tleft.size();j++){
				for(int k=0;k<tright.size();k++){
					TreeNode *temp=(TreeNode*)malloc(sizeof(TreeNode));
					temp->val=vt[i];
					temp->left=tleft[j];
					temp->right=tright[k];
					result.push_back(temp);
				}
			}
			left.push_back(vt[i]);
			if(!right.empty())
				right.erase(right.begin());
		}
		return result;

	}
};