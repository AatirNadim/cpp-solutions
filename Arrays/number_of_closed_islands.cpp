// problem link --> https://leetcode.com/problems/number-of-closed-islands/

// my solution link --> https://leetcode.com/problems/number-of-closed-islands/discuss/3387730/C%2B%2B-oror-DFS-oror-Short-and-Simple

class Solution {
public:
    bool isValid = 1;
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if(i < 0 or i == m or  j < 0 or j == n or grid[i][j]) return;
        if(i == 0 or i == m-1 or j == 0 or j == n-1) isValid = 0;
        grid[i][j] = 1;
        dfs(grid, i+1, j, m, n);
        dfs(grid, i-1, j, m, n);
        dfs(grid, i, j+1, m, n);
        dfs(grid, i, j-1, m, n);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res= 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) continue;
                dfs(grid, i, j, m, n);
                res += isValid;
                isValid = 1;
            }
        }
        return res;
    }
};