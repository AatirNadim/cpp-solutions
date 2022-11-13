// Question link --> https://leetcode.com/problems/reverse-words-in-a-string/description/
//My solution link --> https://leetcode.com/problems/reverse-words-in-a-string/solutions/2810917/c-intuitive-short-and-simple/

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        auto right = s.begin(), left = right;
        while(right != s.end() and *right == ' ') right++;
        while(right != s.end()) {
            left = right;
            while(right != s.end() and *right - ' ') right++;
            auto itr = right; itr--;
            while(itr != left) res.push_back(*itr), itr--;
            res.push_back(*left); res.push_back(' ');
            while(right != s.end() and *right == ' ') right++;
        }
        res.pop_back();
        return string(res.rbegin(), res.rend());
    }
};