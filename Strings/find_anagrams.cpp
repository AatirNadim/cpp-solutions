// problem link --> https://leetcode.com/problems/find-all-anagrams-in-a-string/

// my solution link --> https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/3145369/C%2B%2B-oror-Sliding-Window-oror-97-faster

class Solution {
public:
    bool same(vector<int>& a, vector<int>& b) {
        for(int i=0;i<26;i++) {
            if(a[i] - b[i]) return 0;
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash1(26), hash2(26), res;
        for(char c : p) hash2[c - 'a']++;
        int m = p.size(), n = s.size(), idx = 0;
        while(idx < min(m, n)) {
            hash1[s[idx++] - 'a']++;
        } 
        if(same(hash1, hash2)) res.push_back(0);
        while(idx < n) {
            hash1[s[idx - m] - 'a']--;
            hash1[s[idx] -'a']++;
            if(same(hash1, hash2)) res.push_back(idx - m + 1);
            idx++;
        }
        return res;
    }
};