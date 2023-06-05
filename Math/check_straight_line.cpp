// problem link --> https://leetcode.com/problems/check-if-it-is-a-straight-line/

// my solution link --> https://leetcode.com/problems/check-if-it-is-a-straight-line/discuss/3599865/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    typedef pair<char, double> pi;
    pi getSlope(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0]) return {'v', 0};
        if(a[1] == b[1]) return {'h', 0};
        double x = a[0] - b[0], y = a[1] - b[1];
        return {'#', y/x};
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        pi prev = getSlope(coordinates[0], coordinates[1]);
        int n = coordinates.size();
        for(int i=1;i<n-1;i++) {
            if(prev != getSlope(coordinates[i], coordinates[i+1])) return 0;
        }
        return 1;
    }
};