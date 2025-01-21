/*
  problem link --> https://leetcode.com/problems/grid-game/
*/

class Solution {
 public:
  typedef long long int ll;
  long long gridGame(vector<vector<int>>& grid) {
    int n = grid[0].size();
    ll val1 = 0, val2 = 0;
    ll res = INT_MAX;
    for (int i = n - 1; i > 0; i--) val1 += (ll)grid[0][i];
    res = val1;
    for (int i = 1; i < n; i++) {
      val2 += (ll)grid[1][i - 1];
      val1 -= (ll)grid[0][i];
      res = min(res, max(val1, val2));
    }
    return res;
  }
};