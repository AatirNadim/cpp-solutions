// problem link --> https://leetcode.com/problems/minimum-penalty-for-a-shop/

// my solution link --> https://leetcode.com/problems/minimum-penalty-for-a-shop/discuss/3976800/C%2B%2B-oror-Greedy-oror-Short-and-Simple

class Solution {
public:
    int bestClosingTime(string customers) {
        int yes = 0, no = 0, n = customers.size();
        for(char& c : customers) {
            if(c == 'Y') yes++;
        }
        int res= yes, idx = 1, res_idx = 0;
        while(idx <= n) {
            no += customers[idx - 1] == 'N';
            yes -= customers[idx - 1] == 'Y';
            if(res > yes + no) {
                res = yes + no;
                res_idx = idx;
            }
            idx++;
        }
        return res_idx;
    }
};