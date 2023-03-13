// problem link --> https://leetcode.com/problems/largest-submatrix-with-rearrangements/


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        for(int j=0;j<n;j++) {
            for(int i=1;i<m;i++) {
                if(matrix[i][j]) matrix[i][j] += matrix[i-1][j];
            }
        }
        for(auto& r : matrix) {
            sort(r.begin(), r.end());
            for(int j=0;j<n;j++) {
                res = max(res, r[j]*(n - j));
            }
        }
        return res;
    }
};