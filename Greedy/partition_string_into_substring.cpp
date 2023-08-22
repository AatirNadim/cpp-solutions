// problem link --> https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/

// my solution link --> https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/discuss/3944594/C%2B%2B-oror-Greedy-oror-Short-and-Simple

class Solution {
public:
    typedef long long int ll;
    int minimumPartition(string s, int k) {
        int res = 0, n = s.size();
        ll curr_val = 0; int idx = 0;
        while(idx < n) {
            curr_val = s[idx] - '0'; int idx1 = idx;
            while(idx1 < n-1 and curr_val*10 + s[idx1 + 1] - '0' <= (ll)k) {
                curr_val = (curr_val)*10 + s[idx1 + 1] - '0';
                idx1++;
            }
            if(curr_val > k) return -1;
            res++; idx = idx1 + 1;
        }
        return res;
    }
};