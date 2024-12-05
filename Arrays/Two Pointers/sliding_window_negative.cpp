/*
    problem link --> https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
*/


class Solution {
    void findNextNegative(vector<int>& arr, int& idx, int& n) {
        while(++idx < n and arr[idx] >= 0);
    }
    
    
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        vector<int> res;
        int curridx = 0, idx = -1, n = arr.size(), prev = -1;
        while(idx < n) {
            findNextNegative(arr, idx, n);
            int i = prev + 1;
            for(;i<=(idx - k);i++) res.push_back(0);
            if (idx < n) for(;i<=min(idx, n - k);i++) res.push_back(arr[idx]);
            prev = idx;
        }
        return res;
    }
};