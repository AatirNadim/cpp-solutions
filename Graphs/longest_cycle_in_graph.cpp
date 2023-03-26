// problem link --> https://leetcode.com/problems/longest-cycle-in-a-graph/

// my solution link --> https://leetcode.com/problems/longest-cycle-in-a-graph/discuss/3343020/C%2B%2B-oror-97-faster-oror-85-less-memory-oror-DFS


class Solution {
public:
    vector<int> vis_count, iteration;
    int res = 0;
    void dfs(vector<int>& edges, int currnode, int count, int curr_itr) {
        vis_count[currnode] = count;
        iteration[currnode] = curr_itr;
        int child = edges[currnode];
        if(child == -1) return;
        if(iteration[child] + 1 and iteration[child] - curr_itr) return;
        if(vis_count[child] + 1) {
            res = max(res, count - vis_count[child] + 1);
            return;
        }
        dfs(edges, child, count + 1, curr_itr);
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), itr_val = 0;
        iteration = vector<int> (n, -1);
        vis_count = vector<int>(n, -1);
        for(int i=0;i<n;i++) {
            if(iteration[i] + 1) { continue;}
            dfs(edges, i, 0, itr_val++);
        }
        return res ? res : -1;
    }
};