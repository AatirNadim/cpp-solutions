// problem link --> https://leetcode.com/problems/add-binary/

// my solution link --> https://leetcode.com/problems/add-binary/discuss/3184320/C%2B%2B-oror-O(n)-time-oror-O(n)-space-oror-Short-and-Simple

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        if(n > m) swap(a, b), swap(m, n);
        reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
        string res = "";
        int idx = 0;
        bool carry = 0;
        for(;idx < n; idx++) {
            int val1 = a[idx] - '0', val2 = b[idx] - '0';
            int sum = val1 + val2 + carry;
            carry = (sum&2);
            sum = (sum&1);
            res.push_back((char)(sum + '0'));
        }
        while(idx < m) {
            int val1 = a[idx] - '0';
            int sum = val1 + carry;
            carry = sum&2;
            sum = sum&1;
            res.push_back((char)(sum + '0'));
            idx++;
        }
        if(carry) res.push_back((char)(carry + '0'));
        return string(res.rbegin(), res.rend());
    }
};