// problem link --> https://leetcode.com/problems/palindrome-partitioning/

// my solution link --> https://leetcode.com/problems/palindrome-partitioning/discuss/3084825/C%2B%2B-oror-DP-table-oror-Short-and-Easy


class Solution {
public:
    vector<vector<bool>> hash;
    vector<vector<string>> res;
    bool isPalin(int left, int right) {
        return hash[left][right];
    }
    void populate(string s, int n) {
        for(int i=n-1;i>=0;i--) {
            for(int j = i;j<n;j++) {
                if(j - i > 1) {
                    hash[i][j] = hash[i+1][j-1] and (s[i] == s[j]);
                }
                else hash[i][j] = (s[i] == s[j]);
            }
        }
    }
    void dfs(string s, int idx, int n, vector<string>& v_temp) {
        if(idx == n) {
            res.push_back(v_temp); return;
        }
        string temp = "";
        for(int i = idx;i<n;i++) {
            temp.push_back(s[i]);
            if(isPalin(idx, i)) {
                v_temp.push_back(temp);
                dfs(s, i + 1, n, v_temp);
                v_temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        hash = vector<vector<bool>>(n, vector<bool> (n));
        populate(s, n);
        string temp = "";
        vector<string> v_temp;
        for(int i=0;i<n;i++) {
            temp.push_back(s[i]);
            if(isPalin(0, i)) {
                v_temp.push_back(temp);
                dfs(s, i+1, n, v_temp);
                v_temp.pop_back();
            }
        }
        return res;
    }
};