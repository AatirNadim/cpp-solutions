// problem link --> https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1

class Solution{
public:
    int inSequence(int A, int B, int C){
        int dist = B - A;
        if(!dist) return 1;
        if(!C) return 0;
        return dist%C == 0 and dist/C> 0;
    }
};