/*
    problem link --> https://www.geeksforgeeks.org/problems/find-maximum-number2152/1
*/

class Solution {
  public:
    string findMax(string N) {
        // code here
        vector<int> hash(10);
        for(char c: N) {
            hash[c - '0']++;
        }
        string res = "";
        for(int i=9;i>=0;i--) {
            while(hash[i]--) res.push_back((char)(i + '0'));
        }
        return res;
    }
};