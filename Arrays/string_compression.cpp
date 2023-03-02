// problem link --> https://leetcode.com/problems/string-compression/

// my solution link --> https://leetcode.com/problems/string-compression/discuss/3247067/C%2B%2B-oror-Short-and-Simple


class Solution {
public:
    int compress(vector<char>& chars) {
        int left= 0, n = chars.size(), right = 0;
        while(right < n) {
            int right1 = right;
            while(right1 < n and chars[right1] == chars[right]) right1++;
            chars[left++] = chars[right];
            if(right1 - right == 1) {right++; continue;}
            string val = to_string(right1 - right);
            
            for(char& c : val) chars[left++] = c;
            right = right1;
        }
        return left;
    }
};