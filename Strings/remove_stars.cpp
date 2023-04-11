// problem link --> https://leetcode.com/problems/removing-stars-from-a-string/

// my solution link --> https://leetcode.com/problems/removing-stars-from-a-string/discuss/3403321/C%2B%2B-oror-95-faster-oror-6-lines-oror-Short-and-SImple

class Solution {
public:
    string removeStars(string s) {
        string res = "";
        for(char& c : s) {
            if(c - '*') res.push_back(c);
            else res.pop_back();
        }
        return res;
    }
};