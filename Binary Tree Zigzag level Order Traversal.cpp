#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL){}
	TreeNode(){}
};

class Tree{
private:
	TreeNode *root;
public:
	Tree(vector<int> &num){
		root=(TreeNode*)(malloc(sizeof(TreeNode)));
		root->val=num[0];
		root->left=NULL;
		root->right=NULL;
		static TreeNode t[100];
		for(int i=1;i<num.size();i++){
			t[i].left=NULL;
			t[i].right=NULL;
			t[i].val=num[i];
			TreeNode *temp=(TreeNode*)(malloc(sizeof(TreeNode)));
			TreeNode *temp1=(TreeNode*)(malloc(sizeof(TreeNode)));
			int position=1;//1 means left, 2 means right
			temp=root;
			temp1=root;
			while(temp!=NULL){
				if(num[i]<temp->val){
					temp1=temp;
					temp=temp->left;
					position=1;
				}
				else{
					temp1=temp;
					temp=temp->right;
					position=2;
				}
			}
			if(position==1)
				temp1->left=&t[i];
			else if(position==2)
				temp1->right=&t[i];
		}
	}
	TreeNode *getRoot(){
		return root;
	}
	void print(TreeNode *t){
		if(t!=NULL){
			print(t->left);
			cout<<t->val<<endl;
			print(t->right);
		}
	}
};

vector<int> getInt(string buf){
	vector<int> num;
	int temp=0;
	char c;
	for(int i=0;i!=buf.size();i++){
		if(buf[i]!=','){
			c=buf.at(i);
			temp=temp*10+atoi(&c);
		}
		else{
			num.push_back(temp);
			temp=0;}
		}
		num.push_back(temp);
		return num;
	}

vector<int> setData(){
	string temp;
	cin>>temp;
	return getInt(temp);
}

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode*> q;
		TreeNode* treePtr;
		vector<vector<int>> result1;
		vector<vector<int>> result;
		if(root!=NULL){
			q.push(root);
			while(!q.empty()){
				int t=q.size();
				vector<int> v;
				for(int i=0;i<t;i++){
					treePtr=q.front();
					v.push_back(treePtr->val);
					q.pop();
					if(treePtr->left!=NULL)
						q.push(treePtr->left);
					if(treePtr->right!=NULL)
						q.push(treePtr->right);
				}
				result1.push_back(v);
			}
		}
		for(int i=0;i<result1.size();i++){
			vector<int> temp;
			int j=result1[i].size();
			if(i%2==0){
				for(int k=0;k<j;k++)
					temp.push_back(result1[i][k]);
			}
			else{
				for(int k=j-1;k>=0;k--)
					temp.push_back(result1[i][k]);
			}
			result.push_back(temp);
		}
		return result;
    }
};

void printData(vector<int> &num){
	for(int i=0;i<num.size();i++)
		cout<<num[i]<<endl;
}

int main(){
	Solution test;
	while(1){
		vector<int> num=setData();
		Tree tree(num);
		//tree.print(tree.getRoot());
		vector<vector<int>> result;
		result=test.zigzagLevelOrder(tree.getRoot());
		for(int i=0;i<result.size();i++){
			for(int j=0;j<result[i].size();j++){
				cout<<result[i][j]<<",";
			}
			cout<<endl;
		}
	}
}