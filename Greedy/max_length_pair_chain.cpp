// problem link --> https://leetcode.com/problems/maximum-length-of-pair-chain/

// my solution link --> https://leetcode.com/problems/maximum-length-of-pair-chain/discuss/3963538/C%2B%2B-oror-Sort-%2B-Greedy-oror-Short-and-Simple

class Solution {
public:
    static bool compt(vector<int>& a, vector<int>& b) {
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compt);
        int res = 1, left = pairs[0][0], right = pairs[0][1];
        int n = pairs.size();
        for(int i=1;i<n;i++) {
            if(pairs[i][0] > right) right = pairs[i][1], res++;
        }
        return res;
    }
};