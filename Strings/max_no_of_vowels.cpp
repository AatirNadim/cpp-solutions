// problem link --> https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

// my solution link --> https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/discuss/3487957/C%2B%2B-oror-Sliding-Window-oror-HashTable-oror-Short-and-Simple

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,bool> mp;
        mp['a'] = 1,mp['e'] = 1, mp['o']= 1, mp['i']= 1,mp['u'] = 1;
        int idx = 0, n = s.size(), res = 0, curr_val = 0;
        while(idx < min(n, k)) {
            curr_val += mp[s[idx++]];
        }
        res = curr_val;
        while(idx < n) {
            curr_val += mp[s[idx]];
            curr_val -= mp[s[idx - k]];
            res =max(res,curr_val); idx++;
        }
        return res;
    }
};