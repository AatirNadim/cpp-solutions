// problem link --> https://leetcode.com/problems/merge-strings-alternately/

// my solution link --> https://leetcode.com/problems/merge-strings-alternately/discuss/3429890/C%2B%2B-oror-Short-and-Simple


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size(), i = 0, j = 0;
        string res = "";
        while(i < m and j < n) {
            res.push_back(word1[i++]);
            res.push_back(word2[j++]);
        }
        while(i < m) res.push_back(word1[i++]);
        while(j < n) res.push_back(word2[j++]);
        return res;
    }
};