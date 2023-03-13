// Question link --> https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        auto itr = s.begin();
        while(itr != s.end()) {
            if(res.size() and res.back() == *itr) res.pop_back();
            else res.push_back(*itr);
            itr++;
        }
        return res;
    }
};