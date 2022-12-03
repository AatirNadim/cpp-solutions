// problem link --> https://leetcode.com/problems/palindrome-partitioning/

// my solution link --> https://leetcode.com/problems/palindrome-partitioning/discuss/2874164/C%2B%2B-oror-Short-and-Simple-oror-Backtracking

class Solution {
public:
    vector<vector<string>> res;
    bool isPalin(string s, int left, int right) {
        while(left < right) {
            if (s[left] - s[right]) return 0;
            left++, right--;
        }
        return 1;
    }
    void func(string s, vector<string>& temp, int start, int n) {
        if(start >= n) {
            res.push_back(temp);
            return;
        }
        string curr = "";
        for(int i=start;i<n;i++) {
            curr.push_back(s[i]);
            if (isPalin(s, start, i)) {
                temp.push_back(curr);
                func(s, temp, i + 1, n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string> temp;
        string curr = "";
        for(int i=0;i<n;i++) {
            curr.push_back(s[i]);
            if(isPalin(s, 0, i)) {
                temp.push_back(curr);
                func(s, temp, i+1, n);
                temp.pop_back();
            }
        }
        return res;
    }
};