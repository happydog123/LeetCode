#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

struct ListNode {
	 int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		if(head==NULL)
			return NULL;
		map<ListNode*,int> m;
		ListNode* temp1=(ListNode*)malloc(sizeof(ListNode));
		temp1=head;
		int count=0;
		while(temp1){
			if(m.find(temp1)!=m.end())
				return temp1;
			m[temp1]=count;
			temp1=temp1->next;
			count++;
		}
		return NULL;
    }
};
/*
����������������������*/