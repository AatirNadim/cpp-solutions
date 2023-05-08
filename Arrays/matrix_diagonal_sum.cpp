// problem link --> https://leetcode.com/problems/matrix-diagonal-sum/

// my solution link --> https://leetcode.com/problems/matrix-diagonal-sum/discuss/3500967/C%2B%2B-oror-Short-and-Simple-oror-O(n)-time-oror-O(1)-space

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), res = 0;
        for(int i=0;i<n;i++) {
            res += mat[i][i] + mat[i][n-i-1];
        }
        return res - mat[n>>1][n>>1]*(n&1);
    }
};