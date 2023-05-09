// problem link --> https://leetcode.com/problems/spiral-matrix/

// my solution link --> https://leetcode.com/problems/spiral-matrix/discuss/3504145/C%2B%2B-oror-0ms-oror-Short-and-Simple

class Solution {
public:
    vector<int> res;
    void traverse(vector<vector<int>>& matrix, int si, int sj, int m1, int n1) {
        for(int j=sj;j<n1;j++) res.push_back(matrix[si][j]);
        for(int i=si+1;i<m1;i++) res.push_back(matrix[i][n1 - 1]);
        if(m1 - 1 - si) {
            for(int j=n1 - 2;j>= sj;j--) {
                res.push_back(matrix[m1 - 1][j]);
            }
        }
        if(n1 - 1 - sj) {
            for(int i=m1 - 2;i>si;i--) {
                res.push_back(matrix[i][sj]);
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<=min((m>>1) - !(m&1), (n>>1) - !(n&1));i++) {
            traverse(matrix, i, i, m - i, n - i);
        }
        return res;
    }
};