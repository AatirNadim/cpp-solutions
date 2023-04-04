// problem link --> https://leetcode.com/problems/optimal-partition-of-string/

// my solution link --> https://leetcode.com/problems/optimal-partition-of-string/discuss/3377863/C%2B%2B-oror-HashTable-oror-Short-and-Simple

class Solution {
public:
    int partitionString(string s) {
        vector<bool> hash(26);
        int res = 0;
        for(char& c:s) {
            if(hash[c - 'a']) {
                res++; hash = vector<bool> (26);
            }
            hash[c - 'a'] = 1;
        }
        return res + 1;
        
    }
};