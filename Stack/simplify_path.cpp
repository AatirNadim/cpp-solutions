// problem link --> https://leetcode.com/problems/simplify-path/

// my solution link --> https://leetcode.com/problems/simplify-path/discuss/3408530/C%2B%2B-oror-String(Stack)-oror-90-less-memory-oror-Short-and-Simple

class Solution {
public:
    string simplifyPath(string path) {
        string res = "/";
        int idx = 0, n = path.size();
        while(idx < n and path[idx] == '/') idx++;
        while(idx < n) {
            string s = "";
            while(idx < n and path[idx] - '/') s.push_back(path[idx++]);
            while(idx < n and path[idx] == '/') idx++;
            if(s.size() == 1 and s[0] == '.') {
                continue;
            }   
            else if(s.size() == 2 and s[0] == '.' and s[1] == '.') {
                if(res.size() == 1) continue;
                res.pop_back();
                while(res.back() - '/') res.pop_back();
            }
            else {
                res += s + "/";
            }
            
        }
        if(res.size() > 1) res.pop_back();
        return res;
    }
};