// problem link --> https://leetcode.com/problems/minimum-falling-path-sum/

// my solution link --> https://leetcode.com/problems/minimum-falling-path-sum/discuss/2908522/C%2B%2B-oror-97-faster-oror-DP-oror-Easy


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), res;
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<n;j++) {
                int val = matrix[i+1][j];
                if(j> 0) val = min(val, matrix[i+1][j-1]);
                if(j < n-1) val = min(val, matrix[i+1][j+1]);
                matrix[i][j] += val;
            }
        }
        res = matrix[0][0];
        for(int i=1;i<n;i++) res = min(res, matrix[0][i]);
        return res;
    }
};