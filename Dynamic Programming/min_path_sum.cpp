// problem link --> https://leetcode.com/problems/minimum-path-sum/

// my solution link --> https://leetcode.com/problems/minimum-path-sum/discuss/3347022/C%2B%2B-oror-DP-oror-O(n2)-time-oror-O(1)-space

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i and j) 
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                else if(i) grid[i][j] += grid[i-1][j];
                else if(j) grid[i][j] += grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};