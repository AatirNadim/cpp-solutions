//Question link --> https://leetcode.com/problems/basic-calculator/
//My solution link --> https://leetcode.com/problems/basic-calculator/discuss/2833986/C%2B%2B-oror-95-faster-oror-O(n)-time-oror-O(n)-space


class Solution {
public:
    bool isNum(char c) {
        return c >= '0' and c <= '9';
    }
    int helper(string s) {
        vector<int> res; vector<bool> plus; 
        int curridx = 0; int n = s.size(), idx = 0;
        res.push_back(0); plus.push_back(1);
        while(idx < n) {
            if(s[idx] == '(') {
                res.push_back(0), plus.push_back(1);
                curridx++, idx++;
            }
            else if(s[idx] == ')') {
                int val = res.back(); res.pop_back(); curridx--; plus.pop_back();
                if(plus[curridx]) res[curridx] += val;
                else res[curridx] -= val;
                idx++;
            }
            else if(isNum(s[idx])) {
                int val = 0;
                while(idx < n and isNum(s[idx])) {
                    val = (val * 10) + (s[idx] - '0');
                    idx++;
                }
                if(plus[curridx]) res[curridx] += val;
                else res[curridx] -= val;
            }
            else if(s[idx] == '-') plus[curridx] = 0, idx++;
            else plus[curridx] = 1, idx++;
        }
        return res[curridx];
    }
    int calculate(string s) {
        string res = "";
        for(char c : s) {
            if(c - ' ') res.push_back(c);
        }
        return helper(res);
    }
};