// problem link --> https://leetcode.com/problems/spiral-matrix-ii/

// my solution link --> https://leetcode.com/problems/spiral-matrix-ii/discuss/3508160/C%2B%2B-oror-Matrix-oror-Traversal-oror-Short-and-Simple

class Solution {
public:
    int val = 1;
    void traverse(vector<vector<int>>& res, int si, int sj, int m1, int n1) {
        for(int j=sj;j<n1;j++)
            res[si][j] = val++;
        for(int i=si + 1;i<m1;i++)
            res[i][n1 - 1] = val++;
        if(m1 - 1 - si) {
            for(int j=n1 - 2;j>=sj;j--)
                res[m1 - 1][j] = val++;
        }
        if(n1 - 1 - sj) {
            for(int i=m1 - 2;i>si;i--)
                res[i][sj] = val++;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        for(int i=0;i<=((n>>1) - !(n&1)); i++) {
            traverse(res, i, i, n - i, n - i);
        }
        return res;
    }
};