// problem link --> https://practice.geeksforgeeks.org/problems/13eb74f1c80bc67d526a69b8276f6cad1b8c3401/1

class Solution {
  public:
    bool isNum(char c) {
        return  c>= '0' and c <= '9';
    }
    int checkCompressed(string s, string t) {
        int n = s.size(), m = t.size(), idx = 0, idx1 = 0;
        while(idx < n and idx1 < m) {
            if(isNum(t[idx1])) {
                int temp = 0;
                while(isNum(t[idx1])) {
                    temp = (temp*10) + (t[idx1++] - '0');
                }
                idx += temp;
            }
            else if(t[idx1] - s[idx]) return 0;
            else idx++, idx1++;
        }
        while(idx1 < m and t[idx1] == '0') idx1++;
        return idx1 == m and idx == n;
    }
};