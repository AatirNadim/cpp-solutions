/*
  problem link --> https://leetcode.com/problems/shifting-letters-ii

  my solution link -->
  https://leetcode.com/problems/shifting-letters-ii/solutions/6233140/om-n-time-o1-space-0ms-by-user3405ye-9e5x/

*/


class Solution {
  void update(vector<int>& hash, int left, int right, int val) {
    hash[left] += val;
    if (right + 1 < hash.size()) hash[right + 1] -= val;
  }

 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.size();
    vector<int> hash(n);
    for (vector<int>& shift : shifts) {
      if (shift[2])
        update(hash, shift[0], shift[1], 1);
      else
        update(hash, shift[0], shift[1], -1);
    }
    for (int i = 1; i < n; i++) {
      hash[i] += hash[i - 1];
    }
    for (int i = 0; i < n; i++) {
      int val = s[i] - 'a';
      s[i] = (char)('a' + (val + hash[i] % 26 + 26) % 26);
    }
    return s;
  }
};
