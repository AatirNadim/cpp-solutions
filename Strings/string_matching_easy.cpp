// problem link --> https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// my solution link --> https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/discuss/3251259/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for(int i=0;i<=m-n;i++) {
            if(haystack.substr(i, n) == needle) return i;
        }
        return -1;
    }
};