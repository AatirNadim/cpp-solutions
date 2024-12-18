/*
    problem link --> https://www.geeksforgeeks.org/problems/steps-by-knight5927/1
*/

class Solution 
{
    public:
    
    
    bool possibleUpdate(vector<vector<int>>& hash, int x, int y, int& N, int val) {
        if(x < 0 or x > N or y < 0 or y > N or hash[x][y] <= (val + 1)) return 0;
        hash[x][y] = val + 1;
        return 1;
    }
    
    typedef pair<int, int> pi;
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>> hash(N + 1, vector<int>(N + 1, INT_MAX));
	    queue<pi> q;
	    q.push({ KnightPos[0], KnightPos[1] });
	    hash[KnightPos[0]][KnightPos[1]] = 0;
	    vector<int> one = { 1, -1, 1, -1 };
	    vector<int> two = { 2, 2, -2, -2 };
	    while(q.size()) {
	        pi currnode = q.front(); q.pop();
	        int x = currnode.first, y = currnode.second;
	        if(x == TargetPos[0] and y == TargetPos[1]) return hash[x][y];
	        for(int i=0;i<4;i++) {
	            if(possibleUpdate(hash, x + one[i], y + two[i], N, hash[x][y])) {
	                q.push({ x + one[i], y + two[i] });
	            }
	            if(possibleUpdate(hash, x + two[i], y + one[i], N, hash[x][y])) {
	                q.push({ x + two[i], y + one[i] });
	            }
	        }
	    }
	    return INT_MAX;
	}
};