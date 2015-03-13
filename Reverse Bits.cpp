#include<iostream>
#include<stack>
using namespace std;
typedef unsigned int 
uint32_t;
class Solution {//把方向搞反了
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m=0;
        for(int i=0;i<32;i++){
            m<<=1;
            m = m|(n & 1);
            n>>=1;
        }
        return m;
    }
};