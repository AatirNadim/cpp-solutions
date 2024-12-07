/*
    problem link --> https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
*/


class Solution {
    
    bool isCeleb(vector<vector<int>>& mat, int & n, int curr) {
        int res1 = 0, res2 = 0;
        for(int i=0;i<n;i++) {
            res1 += mat[i][curr];
            res2 += mat[curr][i];
        }
        return res1 == n - 1 and res2 == 0;
        
    }
    
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        for(int i = 0;i<n;i++) {
            if(isCeleb(mat, n, i)) return i;
        }
        return -1;
    }
};