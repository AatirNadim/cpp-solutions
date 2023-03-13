// problem link --> https://leetcode.com/problems/keys-and-rooms/

// my solution link --> https://leetcode.com/problems/keys-and-rooms/discuss/2874199/C%2B%2B-oror-Short-and-Simple-oror-Dfs-%2B-Hashmap

class Solution {
public:
    unordered_map<int, bool> vis; int res;
    void dfs(vector<vector<int>>& rooms, int currnode, int n) {
        if(res == n) return;
        for(int child : rooms[currnode]) {
            if(vis[child]) continue;
            vis[child] = 1; res++;
            dfs(rooms, child, n);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vis[0] = 1; res = 1;
        dfs(rooms, 0, n);
        return res == n;
    }
};