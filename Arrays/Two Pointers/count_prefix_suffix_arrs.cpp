/*
  problem link --> https://leetcode.com/problems/count-prefix-and-suffix-pairs-i
*/

class Solution {
  bool isPrefixAndSuffix(string a, string b) {
    int m = a.size(), n = b.size();
    if (m > n) return 0;
    for (int i = 0; i < m; i++) {
      if ((a[i] != b[i]) or (a[i] != b[n - m + i])) return 0;
    }
    return 1;
  }

 public:
  int countPrefixSuffixPairs(vector<string>& words) {
    int res = 0, n = words.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        res += isPrefixAndSuffix(words[i], words[j]);
      }
    }
    return res;
  }
};
