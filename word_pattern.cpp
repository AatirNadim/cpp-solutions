// problem link --> https://leetcode.com/problems/word-pattern/

// my solution link --> https://leetcode.com/problems/word-pattern/discuss/2978786/C%2B%2B-oror-0ms-oror-HashMap-oror-Vector-oror-Short-and-Simple

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> hash(26, "");
        unordered_map<string, string> mp; 
        string curr = "";
        s.push_back(' '); 
        auto pat_itr = pattern.begin(), itr = s.begin();
        while(itr != s.end() and pat_itr != pattern.end()) {
            if(*itr == ' ') {
                string temp = hash[*pat_itr - 'a'];
                if(temp.size() and temp != curr) return 0;
                if(mp[curr].size() and mp[curr][0] - *pat_itr) return 0;
                hash[*pat_itr - 'a'] = curr;
                mp[curr].push_back(*pat_itr);
                curr.clear(); pat_itr++;
            }
            else curr.push_back(*itr);
            itr++;
        }
        return itr == s.end() and pat_itr == pattern.end();
    }
};