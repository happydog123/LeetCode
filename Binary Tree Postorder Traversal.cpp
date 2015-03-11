#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		stack<TreeNode*> s;
		TreeNode* cur;
		TreeNode* pre=NULL;
		if(root!=NULL){
			s.push(root);
			while(!s.empty()){
				cur=s.top();
				if((cur->left==NULL&&cur->right==NULL)||(pre!=NULL&&(pre==cur->left||pre==cur->right))){
					result.push_back(cur->val);
					s.pop();
					pre=cur;
				}
				else{
					if(cur->right!=NULL)
						s.push(cur->right);
					if(cur->left!=NULL)
						s.push(cur->left);
				}
			}
			return result;
		}
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
		tree.print(tree.getRoot());
		printData(test.postorderTraversal(tree.getRoot()));
	}
}