// problem link --> https://leetcode.com/problems/max-points-on-a-line/submissions/

// my solution link --> https://leetcode.com/problems/max-points-on-a-line/discuss/3021052/C%2B%2B-oror-Short-and-Simple

class Solution {
public:
    double getSlope(vector<int>& a, vector<int>& b) {
        return (double)(a[0] - b[0])/(double)(a[1] - b[1]);
    }
    int func(vector<vector<int>>& points, int j, int n) {
        int res = 0;
        unordered_map<double, int> slopefreq;
        int hor_freq = 0, vir_freq = 0;
        for(int i=0;i<n;i++) {
            if(i == j) continue;
            if(points[i][0] == points[j][0]) hor_freq++;
            else if(points[i][1] == points[j][1]) vir_freq++;
            else {
                double d = getSlope(points[i], points[j]);
                slopefreq[d]++;
                res = max(res, slopefreq[d]);
            }
        }
        return max({res, vir_freq, hor_freq}) + 1;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        for(int i=0;i<n;i++) {
            res = max(res, func(points, i, n));
        }
        return res;
    }
};


// Alternative solution


typedef pair<int, int> cord;
typedef pair<double, double> dir;
class Solution {
public:
    map<cord, map<dir, vector<cord>>> adj;
    int res = 0, temp = 0;
    dir getDir(cord& c1, cord& c2) {
        double dist = getDist(c1, c2);
        return {(double)(c1.first - c2.first)/dist, (double)(c1.second - c2.second)/dist};
    }
    double getDist(cord& c1, cord& c2) {
        double val1 = c1.first - c2.first, val2 = c1.second - c2.second;
        return sqrt(val1*val1 + val2*val2);
    }
    void enqueue(cord& c1, cord& c2) {
        dir curr_dir = getDir(c2, c1);
        if(adj[c1][curr_dir].size()) {
            cord already = adj[c1][curr_dir][0];
            if(getDist(c1, already) > getDist(c1, c2)) 
                adj[c1][curr_dir][0] = c2;                 
        }
        else adj[c1][curr_dir].push_back(c2);
    }
    int dfs(cord& currnode, dir curr_dir) {
        if(!adj[currnode][curr_dir].size()) return 1;
        return 1 + dfs(adj[currnode][curr_dir][0], curr_dir);
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        for(int i=0;i<n;i++) {
            cord c1 = {points[i][0], points[i][1]};
            for(int j=0;j<i;j++) {
                cord c2 = {points[j][0], points[j][1]};
                enqueue(c1, c2);
                enqueue(c2, c1);
            }
        }
        for(vector<int>& point : points) {
            cord c1 = {point[0], point[1]};
            temp = 0;
            for(auto& p : adj[c1]) {
                res = max(res, dfs(c1, p.first));
            }
        }
        return (res)?res:1;
    }
};