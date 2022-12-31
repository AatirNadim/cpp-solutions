// problem link --> https://leetcode.com/problems/unique-paths-iii/


// my solution link --> https://leetcode.com/problems/unique-paths-iii/discuss/2974613/C%2B%2B-oror-DFS-oror-Short-and-Simple


typedef pair<int, int> pi;
class Solution {
public:
    pi start;
    int m, n, total_empty, res;
    void dfs(vector<vector<int>>& grid, int i, int j, int total_filled) {
        if(i < 0 or i== m or j < 0 or j == n or grid[i][j] == 3 or grid[i][j] == -1) return;
        total_filled++;
        if(grid[i][j] == 2) {
            res += (total_filled == total_empty);
            return;
        }
        int val = grid[i][j]; grid[i][j] = 3;
        dfs(grid, i, j+1, total_filled);
        dfs(grid, i+1, j, total_filled);
        dfs(grid, i, j-1, total_filled);
        dfs(grid, i-1, j, total_filled);
        grid[i][j] = val;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), res = 0, total_empty = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] + 1) total_empty++;
                if(grid[i][j] == 1) start = {i, j};
            }
        }
        dfs(grid, start.first, start.second, 0);
        return res;
    }
};