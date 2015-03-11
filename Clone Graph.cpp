#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
	map<int,UndirectedGraphNode*> m;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL)
			return NULL;
		if(m.find(node->label)!=m.end())
			return m[node->label];
		UndirectedGraphNode *now=new UndirectedGraphNode(node->label);
		/*UndirectedGraphNode *now=(UndirectedGraphNode *)malloc(sizeof(UndirectedGraphNode));
		now->label=node->label;*///为什么改成这种写法就不行
		m[now->label]=now;
		for(int i=0;i<node->neighbors.size();i++){
			now->neighbors.push_back(cloneGraph(node->neighbors[i]));
		}
		return now;
    }
};
/*
需要map去重*/