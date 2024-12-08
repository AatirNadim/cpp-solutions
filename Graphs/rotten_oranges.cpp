/*
    problem link --> https://www.geeksforgeeks.org/problems/rotten-oranges2536/1
*/

class Solution {
    
    bool isPossible(vector<vector<int>>& mat, int i, int j, int& m, int& n) {
        return i > -1 and i < m and j > -1 and j < n and mat[i][j] == 1;
    }
    
  public:
    // Function to find minimum time required to rot all oranges.
    typedef pair<int, int> pi;
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<pi> q;
        int m = mat.size(), n = mat[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 2) q.push({ i, j });
            }
        }
        int res = -1;
        vector<int> hor = {1, -1. 0, 0};
        vector<int> ver = {0, 0, 1, -1};
        while(q.size()) {
            res++;
            int n = q.size();
            while(n--) {
                pi currnode = q.front(); q.pop();
                for(int i=0;i<4;i++) {
                    int x = currnode.first + hor[i], y = currnode.second + ver[i]);
                    if(!isPossible(mat, x, y, m, n) continue;
                    mat[x][y] = 2;
                    q.push({ x, y });
                }
            }
        }
        return res;
    }
};