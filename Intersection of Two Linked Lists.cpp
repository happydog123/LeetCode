#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lengthA=getListLength(headA);
		int lengthB=getListLength(headB);
		if(lengthA==0||lengthB==0)
			return NULL;
		int length=abs(lengthA-lengthB);
		ListNode* tempA=(ListNode*)malloc(sizeof(ListNode));
		ListNode* tempB=(ListNode*)malloc(sizeof(ListNode));
		if(lengthA>=lengthB){
			tempA=headB;
			tempB=headA;
		}
		else{
			tempA=headA;//the shorter one be tempA
			tempB=headB;
		}
		for(int i=0;i<length;i++){
				if(tempB!=NULL)
					tempB=tempB->next;
				else
					return NULL;
			}
		while(tempA!=NULL&&tempB!=NULL){
			if(tempA->val==tempB->val)
				return tempA;
			if(tempB!=NULL)
				tempB=tempB->next;
			else
				return NULL;
			if(tempA!=NULL){
				tempA=tempA->next;
			}
			else
				return NULL;
		}
		return NULL;
    }

	int getListLength(ListNode *head){
		int length=0;
		while(head!=NULL){
			length++;
			head=head->next;
		}
		return length;
	}
};

ListNode* constructList(vector<int> &num){
	if(num.size()!=0){
		ListNode* head=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
		head->val=num[0];
		head->next=NULL;
		temp=head;
		for(int i=1;i<num.size();i++){
			ListNode *node=(ListNode*)malloc(sizeof(ListNode));
			node->val=num[i];
			node->next=NULL;
			temp->next=node;
			temp=temp->next;
		}
		return head;
	}
	else
		return NULL;
}

void printList(ListNode* head){
	ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
	temp=head;
	while(temp!=NULL){
		cout<<temp->val<<endl;
		temp=temp->next;
	}
}

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
			temp=0;
		}
	}
	num.push_back(temp);
	return num;
}

vector<int> setdata(){
	string temp;
	cin>>temp;
	return getInt(temp);
}

int main(){
	Solution test;
	//printList(constructList(setdata()));
	printList(test.getIntersectionNode(constructList(setdata()),constructList(setdata())));
	while(1);
	return 0;
}
/*
一开始忽略了不能改变链表结构，所以采用逆序。
实际上计算一下两个链表节点数相差多少，然后让长的那个先走那么多节点就可以了。
*/