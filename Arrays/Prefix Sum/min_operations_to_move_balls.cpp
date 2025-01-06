/*
  problem link -->
  https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

  my solution link -->
  https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/solutions/6238992/c-on-time-o1-space-short-and-simple-by-u-cly6/

*/

class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();
    int rfreq = 0, rightval = 0;
    int lfreq = 0, leftval = 0;
    for (int i = 1; i < n; i++) {
      if (boxes[i] == '0') continue;
      rightval += i, rfreq++;
    }
    vector<int> res;
    res.push_back(rightval);
    for (int i = 1; i < n; i++) {
      lfreq += (boxes[i - 1] == '1');
      leftval += lfreq;
      rightval -= rfreq;
      rfreq -= (boxes[i] == '1');
      res.push_back(leftval + rightval);
    }
    return res;
  }
};