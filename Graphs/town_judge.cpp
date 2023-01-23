// problem link --> https://leetcode.com/problems/find-the-town-judge/

// my solution link --> https://leetcode.com/problems/find-the-town-judge/discuss/3091817/C%2B%2B-oror-Easy-oror-Short-and-Simple-oror-HashTable

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> incoming(n), outgoing(n);
        for(vector<int>& edge : trust) {
            incoming[edge[1]-1]++;
            outgoing[edge[0]-1]++;
        }
        for(int i=0;i<n;i++) {
            if(incoming[i]== n-1 and !outgoing[i]) return i+1;
        }
        return -1;
    }
};