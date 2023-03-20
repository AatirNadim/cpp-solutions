// problem link --> https://leetcode.com/problems/can-place-flowers/

// my solution link --> https://leetcode.com/problems/can-place-flowers/discuss/3319572/C%2B%2B-oror-94-faster-oror-O(n)-solution-oror-Easy


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n = flowerbed.size(), idx = 0;
        while(idx < n and !flowerbed[idx]) idx++;
        if(idx == n) k -= max(0, ((idx + (idx&1))>>1));
        else k -= max(0, (idx>>1));
        while(idx < n and flowerbed[idx]) idx += 2;
        idx--;
        while(idx < n and k > 0) {
            int idx1 = idx, diff, val;
            while(idx1 < n and !flowerbed[idx1]) idx1++;
            diff = idx1 - idx;
            if(idx1 == n) val = max(0, (diff>>1));
            else val = max(0, ((diff - 1)>>1));
            k -= val;
            if(idx1 == n) break;
            idx = idx1;
            while(idx < n and flowerbed[idx]) idx += 2;
            idx--;
        }
        return k <= 0;
    }
};