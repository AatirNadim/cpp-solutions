/*
  problem link --> https://leetcode.com/problems/number-of-ways-to-split-array/

*/

class Solution {
 public:
  typedef long long int ll;
  int waysToSplitArray(vector<int>& nums) {
    int res = 0, n = nums.size();
    ll total = 0, curr = 0;
    for (int& i : nums) total += (ll)i;
    for (int i = 0; i < n - 1; i++) {
      curr += (ll)nums[i];
      if (curr >= total - curr) res++;
    }
    return res;
  }
};