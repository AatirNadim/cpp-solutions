// problem link --> https://leetcode.com/problems/delete-columns-to-make-sorted/

// my solution link --> https://leetcode.com/problems/delete-columns-to-make-sorted/discuss/2993975/C%2B%2B-oror-String-oror-Short-and-Simple

class Solution {
public:
    bool toDelete(vector<string>& strs, int idx, int m) {
        for(int i=0;i<m-1;i++) {
            if (strs[i][idx] > strs[i+1][idx]) {
                return 1;
            }
        }
        return 0;
    }
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size(), m = strs.size(), res = 0;
        for(int i=0;i<n;i++) {
            res += toDelete(strs, i, m);
        }
        return res;
    }
};