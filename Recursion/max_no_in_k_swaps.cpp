/*
    problem link --> https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1
*/

class Solution {
    
    // Function to find the largest number after k swaps.
    
    /*
        1. the number at the current idx is the greatest possible from the remaining
        2. swaps are exhausted
        2. the max number in the segment is present at various positions, try for every
        instance, reducing the possible swaps by 1
    */
    
    void update(string curr) {
        if(res.compare(curr) < 0) res = curr;
    }
    
    void func(string& curr, int idx, int k, int& n) {
        if (!k or idx == n) {
            update(curr);
            return;
        }
        char maxval = curr[idx];
        for(int i = idx + 1; i< curr.size();i++) maxval = max(maxval, curr[i]);
        for(int i = idx + 1; i< curr.size() and curr[idx] - maxval; i++) {
            if(curr[i] - maxval) continue;
            swap(curr[idx], curr[i]);
            func(curr, idx + 1, k - 1, n);
            swap(curr[idx], curr[i]);
        }
        func(curr, idx + 1, k, n);
    }
    
  public:
    
    string res = "";
    
    string findMaximumNum(string& s, int k) {
        // code here.
        string curr = s; res = s;
        int n = s.size();
        func(curr, 0, k, n);
        return res;
    }
    
};