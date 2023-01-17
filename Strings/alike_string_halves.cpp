// problem link --> https://leetcode.com/problems/determine-if-string-halves-are-alike/

// my solution link --> https://leetcode.com/problems/determine-if-string-halves-are-alike/discuss/2866526/C%2B%2B-oror-Short-and-Simple-oror-O(n)-time-oror-O(1)-space

class Solution {
public:
    char getVal(char c) {
        if (c >= 'A' and c<= 'Z') return c - 'A';
        return c - 'a';
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        unordered_map<char, bool> mp;
        int res1 = 0, res2= 0;
        mp[0] = 1, mp['e' - 'a'] = 1, mp['i' - 'a'] = 1, mp['o' - 'a'] = 1;
        mp['u' - 'a'] = 1;
        for(int i=0;i<(n>>1);i++) {
            res1 += mp[getVal(s[i])];
        }
        for(int i=(n>>1);i<n;i++) {
            res1 -= mp[getVal(s[i])];
        }
        return !res1;
    }
};