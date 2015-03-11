#include<iostream>
#include<vector>
using namespace std;
struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if(head==NULL)
			return NULL;
        RandomListNode* origin_head=(RandomListNode*)malloc(sizeof(RandomListNode));
		RandomListNode* origin_next=(RandomListNode*)malloc(sizeof(RandomListNode));
		RandomListNode* new_head=(RandomListNode*)malloc(sizeof(RandomListNode));
		RandomListNode* new_last=(RandomListNode*)malloc(sizeof(RandomListNode));
		if(head->next==NULL){
			new_head->label=head->label;
			new_head->next=head->next;
			new_head->random=head->random;
		}
		vector<RandomListNode*> v;
		origin_head=head;
		while(origin_head){
			if(origin_head==head){
				v.push_back(origin_head->next);
				new_head->label=origin_head->label;
				new_head->next=NULL;
				new_head->random=origin_head;
				new_last=new_head;
				origin_next=origin_head->next;
				origin_head->next=new_head;
				origin_head=origin_next;
			}
			else{
				v.push_back(origin_head->next);
				RandomListNode* temp=(RandomListNode*)malloc(sizeof(RandomListNode));
				temp->label=origin_head->label;
				temp->next=NULL;
				temp->random=origin_head;
				new_last->next=temp;
				new_last=temp;
				origin_next=origin_head->next;
				origin_head->next=temp;
				origin_head=origin_next;
			}
		}
		RandomListNode* new_temp=(RandomListNode*)malloc(sizeof(RandomListNode));
		new_temp=new_head;
		while(new_temp){
			if(new_temp->random->random!=NULL)
				new_temp->random=new_temp->random->random->next;
			else
				new_temp->random=NULL;
		}
		new_temp=head;
		int i=0;
		while(new_temp){
			new_temp->next=v[i];
			i++;
		}
		return new_head;
    }
};