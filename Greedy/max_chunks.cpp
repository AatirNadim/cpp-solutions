/*
    problem link --> https://leetcode.com/problems/max-chunks-to-make-sorted/

    my solution link --> https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/6165080/C%2B%2B-oror-0ms-oror-O(n)-time-oror-O(1)-space-oror-Simple-and-Efficient
*/


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int idx = 0, maxidx = -1;
        int n = arr.size(), res = 0;
        while(idx < n) {
            maxidx = max(maxidx, arr[idx]);
            if(maxidx == idx) {
                res++, maxidx = -1;
            }
            idx++;
        }
        return res;
    }
};