#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct ListNode {
	 int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* input1=(ListNode*)malloc(sizeof(ListNode));
		ListNode* input2=(ListNode*)malloc(sizeof(ListNode));
		//input1=reverse(l1);
		//input2=reverse(l2);
		input1=l1;
		input2=l2;
		ListNode* result_reverse_head=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp1=(ListNode*)malloc(sizeof(ListNode));
		ListNode* temp2=(ListNode*)malloc(sizeof(ListNode));
		ListNode* last=(ListNode*)malloc(sizeof(ListNode));
		int jiewei=0;
		int result_temp=0;
		temp1=input1;
		temp2=input2;
		int i=0;
		while(temp1){
			ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
			result_temp+=temp1->val;
			temp1=temp1->next;
			if(temp2){
				result_temp+=temp2->val;
				temp2=temp2->next;
			}
			result_temp+=jiewei;
			temp->val=(result_temp%10);
			temp->next=NULL;
			if(i==0){
				result_reverse_head=temp;
				last=temp;
			}
			else{
				last->next=temp;
				last=temp;
			}
			jiewei=result_temp/10;
			result_temp=0;
			i++;
		}
		while(temp2){
			ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
			result_temp+=temp2->val;
			temp2=temp2->next;
			result_temp+=jiewei;
			temp->val=(result_temp%10);
			temp->next=NULL;
			last->next=temp;
			last=temp;
			jiewei=result_temp/10;
			result_temp=0;
		}
		if(jiewei!=0){
			ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
			temp->val=jiewei;
			temp->next=NULL;
			last->next=temp;
		}
		return result_reverse_head;
		//return reverse(result_reverse_head);
    }
	ListNode* reverse(ListNode* list){
		ListNode* before=(ListNode*)malloc(sizeof(ListNode));
		ListNode* now=(ListNode*)malloc(sizeof(ListNode));
		ListNode* next=(ListNode*)malloc(sizeof(ListNode));
		before=list;
		int i=0;
		if(before&&before->next){
			 now=before->next;
			 before->next=NULL;
			 while(now){
				 next=now->next;
				 now->next=before;
				 before=now;
				 now=next;
				 i++;
				 /*cout<<"before is "<<before->val<<endl;
				   if(now)
						cout<<"now is "<<now->val<<endl;*/
			 }
			 return before;
		}
		else
			 return before;
 }
};

 ListNode* construct(vector<int> input){
	 ListNode* head=(ListNode*)malloc(sizeof(ListNode));
	 ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
	 for(int i=0;i<input.size();i++){
		 if(i==0){
			 head->val=input[i];
			 head->next=NULL;
			 temp=head;
		 }
		 else{
			 ListNode* now=(ListNode*)malloc(sizeof(ListNode));
			 now->val=input[i];
			 now->next=NULL;
			 temp->next=now;
			 temp=now;
		 }
	 }
	 return head;
 }

 void print(ListNode* list){
	 ListNode* temp=(ListNode*)malloc(sizeof(ListNode));
	 temp=list;
	 while(temp!=NULL){
		 cout<<temp->val<<" , ";
		 temp=temp->next;
	 }
	 cout<<endl;
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
	ListNode* input1=(ListNode*)malloc(sizeof(ListNode));
	ListNode* input2=(ListNode*)malloc(sizeof(ListNode));
	input1=construct(setdata());
	input2=construct(setdata());
	Solution test;
	print(test.addTwoNumbers(input1,input2));
	while(1);
}