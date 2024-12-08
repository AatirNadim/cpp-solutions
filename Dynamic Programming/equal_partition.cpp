/*
    problem link --> https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1
*/

class Solution {
    
    bool subsetSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<bool>> dp(2, vector<bool>(k + 1));
        for(int i = 0;i<2;i++) dp[i&1][0] = 1;
        
        for(int i=0;i<n;i++) {
            for(int j = 1;j<=k;j++) {
                if(!i) dp[0][j] = (arr[0] == j);
                else {
                    dp[i&1][j] = dp[(i - 1)&1][j] or 
                    (j >= arr[i] and dp[(i - 1)&1][j - arr[i]]);
                }
            }
        }
        return dp[(n - 1)&1][k];
    }
    
  public:
    // just check whether a subset is possible with the sum as half the total sum of the array

    bool equalPartition(vector<int>& arr) {
        // code here
        int val = accumulate(arr.begin(), arr.end(), 0);
        if(val&1) return 0;
        return subsetSum(arr, (val>>1));
    }
};