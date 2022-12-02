//problem link --> https://leetcode.com/problems/determine-if-two-strings-are-close/

// my solution link --> https://leetcode.com/problems/determine-if-two-strings-are-close/discuss/2870815/C%2B%2B-oror-Short-and-Simple


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> hash1(26), hash2(26);
        for(char c : word1) hash1[c - 'a']++;
        for(char c : word2) {
            if(!hash1[c - 'a']) return 0;
            hash2[c - 'a']++;
        }
        multiset<int> m1, m2;
        for(int i : hash1) {
            if(i) m1.insert(i);
        }
        for(int i : hash2) {
            if(i) m2.insert(i);
        }
        return m1 == m2;
    }
};