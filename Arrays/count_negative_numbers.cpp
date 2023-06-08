// problem link --> https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

// my solution link --> https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/3614744/C%2B%2B-oror-O(m%2Bn)-time-oror-Short-and-Simple


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x = m-1, y = 0, res = 0;
        while(x > -1 and y < n) {
            if(grid[x][y] < 0) {
                res += (n - y);
                x--;
            }
            else y++;
        }
        return res;
    }
};