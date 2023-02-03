// problem link --> https://leetcode.com/problems/zigzag-conversion/

// my solution link --> https://leetcode.com/problems/zigzag-conversion/discuss/3137971/C%2B%2B-oror-93-faster-oror-Single-Traversal

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1) return s;
        int k = numRows + numRows - 2, num_blocks;
        num_blocks = n/k + (n%k != 0);
        string res = "";
        for(int i=0, idx = 0;i<num_blocks;i++, idx += k) {
            res.push_back(s[idx]);
        }
        for(int idx = 1; idx <= (k>>1); idx++) {
            for(int j=0;j < num_blocks;j++) {
                int left = j*k + idx, right = (j + 1)*k - idx;
                if(left < n) 
                    res.push_back(s[left]);
                if(right < n and right - left) 
                    res.push_back(s[right]);
            }
        }
        return res;   
    }
};