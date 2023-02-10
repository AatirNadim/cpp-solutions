// problem link --> https://leetcode.com/problems/as-far-from-land-as-possible/

// my solution link --> https://leetcode.com/problems/as-far-from-land-as-possible/discuss/3168360/C%2B%2B-oror-BFS-oror-Short-and-Simple

typedef pair<int, int> pi;
class Solution {
public:
    bool isPossible(vector<vector<int>>& grid, int x, int y, int n, int val) {
        if(x < 0 or x == n or y < 0 or y == n or grid[x][y] <= val + 1) return 0;
        return 1;
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue<pi> q;
        int n = grid.size(), res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]) q.push({i, j});
                else grid[i][j] = INT_MAX;
            }
        }
        while(q.size()) {
                pi curr = q.front();q.pop();
                int x = curr.first, y =curr.second;
            
                if(isPossible(grid, x - 1, y, n, grid[x][y])) {
                    grid[x - 1][y] = grid[x][y] + 1;
                    res = max(res, grid[x - 1][y]);
                    q.push({x - 1, y});                            
                }
                if(isPossible(grid, x + 1, y, n, grid[x][y])) {
                   grid[x +1][y] = grid[x][y] + 1;
                    res = max(res, grid[x+1][y]);
                   q.push({x + 1, y});
                }
                if(isPossible(grid, x, y - 1, n, grid[x][y])) {
                    grid[x][y -1] = grid[x][y] + 1;
                    res = max(res, grid[x][y - 1]);
                    q.push({x, y - 1});                            
                }
                if(isPossible(grid, x, y + 1, n, grid[x][y])) {
                    grid[x][y + 1] = grid[x][y] + 1;    
                    res = max(res, grid[x][y + 1]);
                    q.push({x, y + 1});
            }
        }
        return res - 1;
    }
};