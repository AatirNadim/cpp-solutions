// problem link --> https://leetcode.com/problems/verifying-an-alien-dictionary/

// my solution link --> https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/3133490/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    bool wrong(string a, string b, vector<vector<int>>& hash) {
        int idx = 0, m = a.size(), n = b.size();
        while(idx < min(m, n) and a[idx] == b[idx]) idx++;
        if(idx == min(m, n)) return m > n;
        return (hash[a[idx] - 'a'][b[idx] - 'a'] - 1);
    }
    bool isAlienSorted(vector<string>& words, string order) {
        vector<vector<int>> hash(26, vector<int>(26));
        for(int i=0;i<26;i++) {
            for(int j=i+1;j<26;j++) {
                hash[order[i] - 'a'][order[j] - 'a'] = 1;
                hash[order[j] - 'a'][order[i] - 'a'] = -1;
            }
        }
        int n = words.size();
        for(int i=0;i<n-1;i++) {
            if(wrong(words[i], words[i+1], hash)) return 0;
        }
        return 1;
    }
};