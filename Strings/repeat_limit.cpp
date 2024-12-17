/*
    problem link --> https://leetcode.com/problems/construct-string-with-repeat-limit/

    my solution link --> https://leetcode.com/problems/construct-string-with-repeat-limit/discuss/6155060/C%2B%2B-oror-Hashing-oror-Simple-Logic
*/

class Solution {
    
    char findNextGreater(vector<int>& hash, int idx) {
        for(int i = idx - 1;i>=0;i--) {
            if(hash[i]) {
                hash[i]--;
                return (char)(i + 'a');
            }
        }
        return '#';
    }
    
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> hash(26);
        for(char c: s) hash[c - 'a']++;
        string res = "";
        for(int i=25;i>=0;i--) {
            while(hash[i]) {
                int val = hash[i];
                for(int j = 0;j<min(repeatLimit, val); j++, hash[i]--) {
                    res.push_back((char)(i + 'a'));
                }
                if(hash[i]) {
                    char c = findNextGreater(hash, i);
                    if(c == '#') return res;
                    res.push_back(c);
                }
            }
        }
        return res;
    }
};