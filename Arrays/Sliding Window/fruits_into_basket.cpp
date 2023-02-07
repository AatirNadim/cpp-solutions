// problem link --> https://leetcode.com/problems/fruit-into-baskets/

// my solution link --> https://leetcode.com/problems/fruit-into-baskets/discuss/3156821/C%2B%2B-oror-Short-and-Simple-oror-Easy-Understanding

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> hash(n);
        int temp = 0, left = 0, right = 0, res = 0;
        while(right < n) {
            temp += !hash[fruits[right]];
            hash[fruits[right]]++;
            while(left < right and temp > 2) {
                hash[fruits[left]]--;
                temp -= !(hash[fruits[left++]]);
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};