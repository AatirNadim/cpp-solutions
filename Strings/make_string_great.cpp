// Question link --> https://leetcode.com/problems/make-the-string-great/description/
//my solution link --> https://leetcode.com/problems/make-the-string-great/solutions/2793142/c-short-and-simple/

class Solution {
public:
    bool func(char a, char b) {
        return ((a - 97) == (b - 65)) or ((a - 65) == (b - 97));
    }
    string makeGood(string s) {
        string res = "";
        auto itr= s.begin();
        while(itr != s.end()) {
            if(res.size() and func(res.back(), *itr)) res.pop_back();
            else res.push_back(*itr);
            itr++;
        }
        return res;
    }
};