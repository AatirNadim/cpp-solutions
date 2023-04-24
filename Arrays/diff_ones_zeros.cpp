// problem link --> https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

// my solution link --> https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/discuss/3449223/C%2B%2B-oror-Matrix-oror-Simulation


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rows(m), cols(n);
        vector<vector<int>> res(m, vector<int>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                rows[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                res[i][j] += (2*rows[i] - n) + (2*cols[j] - m);
            }
        }
        return res;
    }
};