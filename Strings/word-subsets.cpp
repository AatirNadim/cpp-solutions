/*
  problem link --> https://leetcode.com/problems/word-subsets/
*/

class Solution {
 public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<int> hash1(26);
    for (string s : words2) {
      vector<int> temp(26);
      for (char c : s) temp[c - 'a']++;
      for (int i = 0; i < 26; i++) hash1[i] = max(hash1[i], temp[i]);
    }
    vector<string> res;
    for (string s : words1) {
      vector<int> temp(26);
      for (char c : s) temp[c - 'a']++;
      bool fl = 1;
      for (int i = 0; i < 26; i++) {
        if (hash1[i] > temp[i]) {
          fl = 0;
          break;
        }
      }
      if (fl) res.push_back(s);
    }
    return res;
  }
};