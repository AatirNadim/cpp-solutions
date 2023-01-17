// problem link --> https://leetcode.com/problems/flip-string-to-monotone-increasing/

// my solution link --> https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/3063762/C%2B%2B-oror-O(n)-time-oror-O(n)-space-oror-Prefix-Sum

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> hash(n);
        hash[0] = s[0] - '0';
        for(int i=1;i<n;i++) hash[i] = hash[i-1] + s[i] - '0';
        int res = n - hash[n-1];
        for(int i=0;i<n;i++) {
            int ones_right = 0, zeros_right = 0;
            ones_right = hash[n-1] - hash[i];
            zeros_right  = n - i - 1 - ones_right;
            res = min(res, hash[i] + zeros_right);
        }
        return res;
    }
};