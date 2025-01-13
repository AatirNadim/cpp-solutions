/*
  problem link -->
  https://leetcode.com/problems/minimum-length-of-string-after-operations/
*/

class Solution {
 public:
  int minimumLength(string s) {
    vector<int> hash(26);
    for (char c : s) hash[c - 'a']++;
    int res = 0;
    for (int i = 0; i < 26; i++) {
      if (!hash[i]) continue;
      if (hash[i] & 1)
        res++;
      else
        res += 2;
    }
    return res;
  }
};