// problem link --> https://practice.geeksforgeeks.org/problems/b64485d3994958cca8748991bb58668204b3e4c0/1

class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edge)
  {
      int res = -1, maxval = -1;
      vector<int> hash(n);
      for(int i=0;i<n;i++) {
          if(edge[i] == -1) continue;
          hash[edge[i]] += i;
          if(hash[edge[i]] > maxval) {
              res = edge[i];
              maxval = hash[edge[i]];
          }
          else if(hash[edge[i]] == maxval) {
              res = max(res, edge[i]);
          }
      }
      if(res + 1) return res;
      return n-1;
  }
};