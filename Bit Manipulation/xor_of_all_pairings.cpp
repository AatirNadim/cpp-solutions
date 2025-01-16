/*
  problem link --> https://leetcode.com/problems/bitwise-xor-of-all-pairings/
*/

class Solution {
 public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int res = 0, m = nums1.size(), n = nums2.size();
    if (m & 1) {
      for (int& i : nums2) res ^= i;
    }
    if (n & 1) {
      for (int& i : nums1) res ^= i;
    }
    return res;
  }
};