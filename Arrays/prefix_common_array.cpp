/*
  problem link -->
  https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/solutions

  my solution link -->
  https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/solutions/6280959/0ms-on-space-on-time-by-user3405ye-h264/
*/

class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size(), count = 0;
    vector<int> vis(n + 1), res;
    for (int i = 0; i < n; i++) {
      vis[A[i]]++;
      vis[B[i]]++;
      if (vis[A[i]] == 2) count++;
      if (vis[B[i]] == 2 and A[i] - B[i]) count++;
      res.push_back(count);
    }
    return res;
  }
};