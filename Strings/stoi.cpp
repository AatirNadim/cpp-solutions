// problem link --> https://leetcode.com/problems/string-to-integer-atoi/

// my solution link --> https://leetcode.com/problems/string-to-integer-atoi/discuss/3977218/C%2B%2B-oror-0ms-oror-String

class Solution {
public:
    typedef long long int ll;
    bool isNum(char c) {
        return c >= '0' and c <= '9';
    }
    int func(string& s, bool isNeg) {
        int idx = 0, n = s.size();
        while(idx < n and s[idx] == '0') idx++;
        if(n - idx > 10) return isNeg ? INT_MIN : INT_MAX;
        ll temp = 0;
        for(int i=idx;i<n;i++) {
            temp = (temp*10) + (s[i] - '0');
        }
        if(isNeg) temp *=-1;
        if(isNeg) temp = max(temp, (ll)INT_MIN);
        else temp = min(temp, (ll)INT_MAX);
        return (int)temp;
    }
    int myAtoi(string s) {
        int idx = 0, n = s.size(), res = 0; bool isNeg = 0;
        while(idx < n and s[idx] == ' ') idx++;
        if(idx == n) return res;
        if(s[idx] == '-' or s[idx] == '+') {
            isNeg = s[idx] == '-';
            idx++;
        }
        if(idx == n or !(isNum(s[idx]))) return res;
        string temp = "";
        while(idx < n and isNum(s[idx])) temp.push_back(s[idx++]);
        return func(temp, isNeg);
    }
};