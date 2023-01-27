// problem link --> https://leetcode.com/problems/concatenated-words/

// my solution link --> https://leetcode.com/problems/concatenated-words/discuss/3105513/C%2B%2B-oror-Hash-oror-Short-and-Simple


class Solution {
public:
    bool func(unordered_map<string, bool>& mp, string& word) {
        int n = word.size();
        vector<bool> hash(n);
        for(int i=0;i<n-1;i++) {
            for(int j=1;j<=i;j++) {
                 hash[i] = hash[i] or (hash[j-1] and mp[word.substr(j, i - j + 1)]);
            }
            hash[i] = hash[i] or mp[word.substr(0, i + 1)];
        }
        for(int i=0;i<n-1;i++) {
            hash[n-1] = hash[n-1] or (hash[i] and mp[word.substr(i + 1)]);
        }
        return hash[n-1];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_map<string, bool> mp;
        for(string& word : words) mp[word] = 1;
        for(string& word : words) {
            if(func(mp, word)) res.push_back(word);
        }
        return res;
    }
};