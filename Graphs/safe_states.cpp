/*
  problem link --> https://leetcode.com/problems/find-eventual-safe-states/
*/

class Solution {
 public:
  int dfs(vector<vector<int>>& graph, int idx, vector<int>& isSafe) {
    if (isSafe[idx] + 1) return isSafe[idx];
    if (!graph[idx].size()) {
      isSafe[idx] = 1;
      return 1;
    }
    isSafe[idx] = 0;
    for (auto& itr : graph[idx]) {
      if (!dfs(graph, itr, isSafe)) {
        isSafe[idx] = 0;
        return 0;
      }
    }
    isSafe[idx] = 1;
    return 1;
  }
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> isSafe(graph.size(), -1);
    vector<int> res;
    for (int i = 0; i < graph.size(); i++) {
      if (dfs(graph, i, isSafe) == 1) res.push_back(i);
    }
    return res;
  }
};