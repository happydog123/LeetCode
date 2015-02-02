#include <iostream>
#include <deque>
#include <string>
using namespace std;

class MinStack {
	deque<int> num;
	deque<int> order;
public:
    void push(int x) {
		num.push_back(x);
		if(order.size()==0)
			order.push_back(x);
		else{
			int temp=order[order.size()-1];
			if(x<=temp)//should not be x<temp, because the minest may show twice times
				order.push_back(x);
		}
    }

    void pop() {
		if(num.size()!=0&&order.size()!=0){
			int temp1=num[num.size()-1];
			int temp2=order[order.size()-1];
			if(temp1==temp2)
				order.pop_back();
			num.pop_back();
		}
	}

    int top() {
		if(num.size()!=0)
			return num[num.size()-1];
		else
			return -1;
    }

    int getMin() {
		if(order.size()!=0)
			return order[order.size()-1];
    }

	void printStack(){
		for(int i=0;i<num.size();i++){
			cout<<num[i]<<' ';
		}
		cout<<endl;
	}
};

int main(){
	MinStack test;
	string command;
	int num;
	while(1){
		cin>>command;
		if(command=="pu"){
			cin>>num;
			test.push(num);
			test.printStack();
		}
		if(command=="po"){
			test.pop();
			test.printStack();
		}
		if(command=="to"){
			cout<<test.top()<<endl;
		}
		if(command=="min"){
			cout<<test.getMin()<<endl;
		}
	}
}
/*
首先解决Memory Limit Exceed, 将vector改为deque
其次使用两个栈，才能使getMin的复杂度为O(1)*/