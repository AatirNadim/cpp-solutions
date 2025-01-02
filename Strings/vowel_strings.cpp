/*
  problem link --> https://leetcode.com/problems/count-vowel-strings-in-ranges/
*/

class Solution {
  int find(vector<int>& arr, int left, int right) {
    if (left) return arr[right] - arr[left - 1];
    return arr[right];
  }

 public:
  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int n = words.size();
    vector<int> hash(n), res;
    unordered_map<char, bool> mp;
    mp['a'] = 1, mp['e'] = 1, mp['i'] = 1, mp['o'] = 1, mp['u'] = 1;
    for (int i = 0; i < n; i++) {
      if (i) hash[i] = hash[i - 1];
      if (mp[words[i][0]] && mp[words[i].back()]) hash[i]++;
      // cout<<hash[i]<<" ";
    }
    for (vector<int>& query : queries) {
      res.push_back(find(hash, query[0], query[1]));
    }
    return res;
  }
};