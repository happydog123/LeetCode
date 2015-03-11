#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return build(inorder,postorder,0,inorder.size()-1);
    }
	TreeNode* build(vector<int> &inorder, vector<int> &postorder,int begin,int end){
		TreeNode *root=(TreeNode*)malloc(sizeof(TreeNode));
		if(postorder.size()==0)
			return NULL;
		root->val=postorder[postorder.size()-1];

		int t=root->val;
		std::vector<int>::iterator position=std::find(postorder.begin(),postorder.end(),t);
		bool isValid=(position!=postorder.end());
		if(isValid)
			postorder.erase(position);

		int i;
		for(i=begin;i<=end;i++){
			if(inorder[i]==t)
				break;
		}
		i++;;
		if(i>end)
			root->right=NULL;
		else{
			root->right=build(inorder,postorder,i,end);
		}
		i--;i--;
		if(i<begin)
			root->left=NULL;
		else{
			root->left=build(inorder,postorder,begin,i);
		}
		return root;
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

void printTree(TreeNode* root){
	if(root==NULL)
		return;
	printTree(root->left);
	cout<<root->val<<endl;
	printTree(root->right);
}

void printData(vector<int> &num){
	for(int i=0;i<num.size();i++)
		cout<<num[i]<<endl;
}

int main(){
	Solution test;
	while(1){
		vector<int> num1=setData();
		printData(num1);
		vector<int> num2=setData();
		printData(num2);
		cout<<"The tree is"<<endl;
		printTree(test.buildTree(num1,num2));
		//test.buildTree(num1,num2);
	}
	return 0;
}
/*
因为增加了vector造成了Memory limit问题，不如加一个数字表明是从哪里截取的*/