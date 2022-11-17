//Question link --> https://leetcode.com/problems/rectangle-area/description/

//my solution link --> https://leetcode.com/problems/rectangle-area/solutions/2825054/c-clever-question/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int lenx = 0, leny = 0;
        if(bx1 < ax1) lenx = max(ax2, bx2) - bx1;
        else lenx = max(ax2, bx2) - ax1;
        if(by1 < ay1) leny = max(ay2, by2) - by1;
        else leny = max(ay2, by2) - ay1;
        int res = (ax2 - ax1)*(ay2 - ay1) + (bx2 - bx1)*(by2 - by1);
        int totalx = (ax2 - ax1) + (bx2 - bx1);
        int totaly = (ay2 - ay1) + (by2 - by1);
        if(lenx > totalx or leny > totaly) return res;
        return res - (totalx - lenx)*(totaly - leny);
    }
};