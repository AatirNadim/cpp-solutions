// problem link --> https://practice.geeksforgeeks.org/problems/90a81c305b1fe939b9230a67824749ceaa493eab/1

#define ll long long int

class Solution{
  public:
  vector<ll> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      vector<ll> res;
      ll count = n*n;
      unordered_map<int, bool> rows, cols;
      for(vector<int>& v : arr) {
          if(!rows[v[0]]) {
              rows[v[0]] = 1;
              count -= (n - cols.size());
          }
          if(!cols[v[1]]) {
              cols[v[1]] = 1;
              count -= (n - rows.size());
          }
          res.push_back(count);
      }
      return res;
      
  }
};