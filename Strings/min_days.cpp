// problem link --> https://practice.geeksforgeeks.org/problems/f4d22b1f9d62e8bee0ff84e9fa51dc66eb5005ec/1

class Solution {
  public:
    int getMinimumDays(int n, string s, vector<int> &p) {
        // code here
        vector<int> hash(n);
        int curr = 0, res = 0;
        for(int i=0;i<n-1;i++) {
            curr += (s[i] == s[i+1]);
        }
        for(int& i : p) {
            if(!curr) break;
            if(i) curr -= (s[i] == s[i-1]);
            if(i < n-1) curr -= (s[i] == s[i + 1]);
            s[i] = '?';
            res++;
        }
        return res;
        
    }
};