//problem link --> https://leetcode.com/problems/sort-characters-by-frequency/

// my solution link --> https://leetcode.com/problems/sort-characters-by-frequency/discuss/2872136/C%2B%2B-oror-Map-oror-Short-and-Simple


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hash;
        for(char c : s) hash[c]++;
        map<int, string> mp; string res = "";
        for(auto &p : hash) {
            for(int i=0;i<p.second;i++) {
                mp[p.second].push_back(p.first);
            }
        }
        for(auto &p : mp) res = p.second + res;
        return res;
    }
};