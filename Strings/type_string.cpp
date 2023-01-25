// problem link --> https://practice.geeksforgeeks.org/problems/95080eb9efbf7cc5cb4851ddf8d7946e3f212a49/1

class Solution {
  public:
  bool isDup(string s, int idx, int n) {
    if((idx+1)&1) return 0;
    int left = 0, right = ((idx + 1)>>1);
    while(right <= idx and s[left] == s[right]) left++, right++;
    return right > idx;
  }
    int minOperation(string s) {
        // code here
        int n = s.size(), idx = n-1;
        while(idx >= 0) {
            if(isDup(s, idx, n)) {
                return ((idx + 1)>>1) + (n - idx);
            }
            idx--;
        }
        return n;
    }
};