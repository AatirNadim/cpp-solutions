// question link --> https://leetcode.com/problems/text-justification/

// my solution link --> https://leetcode.com/problems/text-justification/discuss/3954754/C%2B%2B-oror-Short-and-Simple-oror-Simulation


class Solution {
public:
    
    string get_str(vector<string>& temp, int& currlen, int maxWidth, bool left_just) {
        int n = temp.size(), spaces = n - 1;
        int to_add = 0, from_left = 0;
        if(spaces > 0) {
            to_add = (maxWidth - currlen)/spaces, from_left = (maxWidth - currlen)%spaces;
        }
        string res = "";
        res += temp[0];
        if(left_just) {
            for(int i=1;i<n;i++) {
                res += " " + temp[i]; 
            }
        }
        else {
            for(int i=1;i<n;i++) {
                int tempval = to_add + (from_left > 0);
                from_left = max(from_left - 1, 0);
                while(tempval--) res.push_back(' ');
                res += " " + temp[i];
            }
        }
        to_add = maxWidth - res.size();
        while(to_add--) res.push_back(' ');
        return res;
        
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(), idx = 0;
        vector<string> res;
        while(idx < n) {
            vector<string> temp; int currlen = 0;
            temp.push_back(words[idx]); currlen = words[idx].size();
            idx++;
            while(idx < n and currlen + words[idx].size() + 1 <= maxWidth) {
                temp.push_back(words[idx]); currlen += words[idx].size() + 1;
                idx++;
            } 
            if(idx == n) {
                res.push_back(get_str(temp, currlen, maxWidth, 1));
            }
            else {
                res.push_back(get_str(temp, currlen, maxWidth, 0));       
            }
        }
        return res;
    }
};