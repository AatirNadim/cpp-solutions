// problem link --> https://leetcode.com/problems/truncate-sentence/

// my solution link --> https://leetcode.com/problems/truncate-sentence/discuss/3012413/C%2B%2B-oror-0ms-oror-String-Pointer-oror-Short-and-Simple

class Solution {
public:
    string truncateSentence(string s, int k) {
        s.push_back(' ');
        auto itr = s.begin();
        while(itr != s.end()) {
            k -= (*itr == ' ');
            if(!k) break;
            itr++;
        }
        return string(s.begin(), itr);
    }
};