// problem link --> https://leetcode.com/problems/restore-ip-addresses/

// my solution link --> https://leetcode.com/problems/restore-ip-addresses/discuss/3080108/C%2B%2B-oror-Recursion-oror-Short-and-Simple

class Solution {
public:
    vector<string> res; 
    void func(string s, string& temp, int i, int n, int times) {
        if(i == n) {
            temp.pop_back();
            if(times == 4) res.push_back(temp); 
            return;
        }
        string curr = temp;
        int num = 0, idx = i;
        while(idx < n) {
            num = (num*10) + s[idx] - '0';
            if(num > 255) break;
            if(idx - i and num < 10) break;
            temp.push_back(s[idx]);
            temp.push_back('.');
            func(s, temp, idx + 1, n, times + 1);
            temp.pop_back(); idx++;
        }
        temp = curr;
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size(), idx = 0;
        if(n > 12) return {};
        string temp = ""; int num = 0;
        while(idx < n) {
            num = (num*10) + s[idx] - '0';
            if(num > 255) break;
            if(idx and num < 10) break;
            temp.push_back(s[idx]);
            temp.push_back('.');
            func(s, temp, idx + 1, n, 1); idx++;
            temp.pop_back();
        }
        return res;
    }
};