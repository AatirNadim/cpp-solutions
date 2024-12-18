/*
    problem link --> https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
*/

class Solution {
    
    bool presentInAll(vector<string>& arr, int idx, char c) {
        for(string s: arr) {
            if(!(s.size() > idx and s[idx] == c)) return 0;
        }
        return 1;
    }
    
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string res = "";
        int n = arr[0].size();
        for(int i=0;i<n;i++) {
            if(presentInAll(arr, i, arr[0][i])) res.push_back(arr[0][i]);
            else break;
        }
        return res;
    }
};