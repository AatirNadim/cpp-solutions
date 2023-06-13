// problem link --> https://leetcode.com/problems/equal-row-and-column-pairs/

// my solution link --> https://leetcode.com/problems/equal-row-and-column-pairs/discuss/3632928/C%2B%2B-oror-HashMap-oror-No-Trie-oror-Short-and-Simple

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i=0;i<m;i++) mp[grid[i]]++;
        for(int j=0;j<n;j++) {
            vector<int> temp;
            for(int i=0;i<m;i++) temp.push_back(grid[i][j]);
            res += mp[temp];
        }
        return res;
    }
};