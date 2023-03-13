// problem link --> https://leetcode.com/problems/odd-string-difference/

// my solution link --> https://leetcode.com/problems/odd-string-difference/discuss/2996206/C%2B%2B-oror-String-%2B-HashMap-oror-Easy-oror-Short-and-Simple

class Solution {
public:
    string oddString(vector<string>& words) {
        unordered_map<string, vector<string>> mp;
        int n = words[0].size();
        for(string& word : words) {
            string temp = "";
            for(int i=0;i<n-1;i++) {
                temp += to_string(word[i+1] - word[i]);
                temp.push_back(' ');
            }
            if(mp[temp].size() < 2) mp[temp].push_back(word);
        }
        for(auto &p : mp) {
            if(p.second.size() == 1) return p.second[0];
        }
        return "";
    }
};