// problem link --> https://practice.geeksforgeeks.org/problems/5a7e1a52f1b7796238f9efea4c6fda389f26c327/1

class Solution {
  public:
    int solve(int a, int b) {
        // code here
        bool b1 = 0, b2 = 0;
        int val = 32;
        while(val--) {
            if(a&1 and !(b&1)) b1 = 1;
            if(b&1 and !(a&1)) b2 = 1;
            a>>=1, b>>=1;
        }
        return b1 + b2;
    }
};