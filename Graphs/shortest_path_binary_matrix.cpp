// problem link --> https://leetcode.com/problems/shortest-path-in-binary-matrix/

// my solution link --> https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/3587300/C%2B%2B-oror-BFS-oror-In-place-oror-Short-and-Simple

class Solution {
public:
    typedef pair<int,int> pi;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] or grid[n-1][n-1]) return -1;
        queue<pi> q;
        q.push({0,0});
        grid[0][0] = 1;
        while(q.size()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(x == n-1 and y == n-1) return grid[x][y];
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++) {
                    if(x+i < 0 or x+i == n or y+j < 0 or y+j == n) continue;
                    if(!i and !j) continue;
                    if(!grid[x+i][y+j]) {
                        grid[x+i][y+j] = grid[x][y] + 1;
                        q.push({x+i, y+j});  
                    }
                }
            }
                
        }
        return -1;
    }
};