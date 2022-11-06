// Leetcode Daily:
// Find longest palindrome, created with two letter words, from the words vector provided.

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        unordered_map<string, bool> vis;
        for(string s : words) mp[s]++, vis[s] = 1;
        bool odd_done = 0; int res = 0;
        for(auto &p : mp) {
            string s(p.first.rbegin(), p.first.rend());
            if(!vis[s] or !p.second) continue;
            if(s == p.first) {
                res += p.second*2;
                if(p.second&1) res -= odd_done*2;
                odd_done = odd_done or (p.second&1);
                p.second = 0;
            }
            else {
                res += min(mp[s], p.second)*4;
                mp[s] = 0, p.second = 0;
            }   
        }
        return res;
    }
};