// problem link --> https://leetcode.com/problems/permutation-in-string/

// my solution link --> https://leetcode.com/problems/permutation-in-string/discuss/3141158/C%2B%2B-oror-Sliding-Window-oror-HashTable

class Solution {
public:
    bool same(vector<int>& hash1, vector<int>& hash2) {
        for(int i=0;i<26;i++) {
            if(hash1[i] - hash2[i]) return 0;
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> hash1(26), hash2(26);
        for(char c: s1) hash1[c - 'a']++;
        int idx = 0;
        while(idx < min(m, n)) {
            hash2[s2[idx++] - 'a']++;
        }
        if(same(hash1, hash2)) return 1;
        while(idx < n) {
            hash2[s2[idx - m] - 'a']--;
            hash2[s2[idx] - 'a']++;
            if(same(hash1, hash2)) return 1;
            idx++;
        }
        return 0;
    }
};