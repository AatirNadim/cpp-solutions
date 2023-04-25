// problem link --> https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

// my solution link --> https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/discuss/3452996/C%2B%2B-oror-Hash-Table-oror-Short-and-Simple


class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> hash(26);
        int n = words.size();
        for(string& word: words) {
            for(char& c : word) {
                hash[c - 'a']++;
            }
        }
        for(int i=0;i<26;i++) {
            if(hash[i] and hash[i]%n) return 0;
        }
        return 1;
    }
};