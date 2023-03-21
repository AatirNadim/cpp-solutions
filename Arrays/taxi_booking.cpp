// problem link --> https://practice.geeksforgeeks.org/problems/7995e41d167d81f14f1d4194b29ef839f52d18ba/1

class Solution{
public:
    int minimumTime(int n,int cur,vector<int> &pos,vector<int> &time){
        int res = INT_MAX;
        for(int i=0;i<n;i++) {
            res = min(res, abs(cur - pos[i])*time[i]);
        }
        return res;
    }
};