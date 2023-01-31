// problem link --> https://leetcode.com/problems/best-team-with-no-conflicts/

// my solution link --> https://leetcode.com/problems/best-team-with-no-conflicts/discuss/3123993/C%2B%2B-oror-DP-oror-Short-and-Simple

class Solution {
public:
    static bool compt(vector<int>& a, vector<int>& b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> hash;
        int n = scores.size(), res = 0;
        for(int i=0;i<n;i++) hash.push_back({scores[i], ages[i]});
        sort(hash.begin(), hash.end(), compt);
        vector<int> dp(n);
        for(int i=0;i<n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(hash[i][0] >= hash[j][0]) dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += hash[i][0];
            res = max(res, dp[i]);
        }
        return res;
    }
};