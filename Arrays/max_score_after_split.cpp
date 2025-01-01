/*
  problem link -->
  https://leetcode.com/problems/maximum-score-after-splitting-a-string/

  my solution link -->
  https://leetcode.com/problems/maximum-score-after-splitting-a-string/solutions/6212146/c-short-and-simple-traversal-by-user3405-r3jp/
*/

class Solution {
 public:
  int maxScore(string s) {
    int n = s.size(), zeros = 0, res = 0;
    for (char c : s) {
      if (c - '0')
        ;
      else
        zeros++;
    }
    int leftzeros = 0;
    for (int i = 0; i < n - 1; i++) {
      leftzeros += (s[i] == '0');
      zeros -= (s[i] == '0');
      res = max(res, leftzeros + (n - i - 1) - zeros);
    }
    return res;
  }
};