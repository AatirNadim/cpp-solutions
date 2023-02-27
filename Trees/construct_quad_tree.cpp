// problem link --> https://leetcode.com/problems/construct-quad-tree/

// my solution link --> https://leetcode.com/problems/construct-quad-tree/discuss/3236354/C%2B%2B-oror-Recursion-oror-Optimized


/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

typedef pair<int, int> cord;
typedef pair<cord, int> dat;
class Solution {
public:
    map<dat, int> mp;
    void populate(vector<vector<int>>& grid, int n, cord start) {
        if(n == 1) {
            mp[{start, 1}] = grid[start.first][start.second];
            return;
        }
        cord tl, tr, bl, br;
        tl = start, tr = {start.first, start.second + (n>>1)};
        bl = {start.first + (n>>1), start.second};
        br = {start.first + (n>>1), start.second + (n>>1)};
        populate(grid, (n>>1), tl);
        populate(grid, (n>>1), tr);
        populate(grid, (n>>1), bl);
        populate(grid, (n>>1), br);
        int val1 = mp[{tl, (n>>1)}], val2 = mp[{tr, (n>>1)}], val3 = mp[{bl, (n>>1)}], val4 = mp[{br, (n>>1)}];
        if(val1 + 1 and val2 + 1 and val3 + 1 and val4 + 1 and val1 == val2 and val1 == val3 and val1 == val4) {
            mp[{start, n}] = val1;
        }
        else mp[{start, n}] = -1;
    }
    
    Node* makeTree( cord start, int n ) {
        if(mp[{start, n}] + 1) return new Node(mp[{start, n}], 1);
        Node* curr = new Node(1, 0);
        
        cord tl, tr, bl, br;
        tl = start, tr = {start.first, start.second + (n>>1)};
        bl = {start.first + (n>>1), start.second};
        br = {start.first + (n>>1), start.second + (n>>1)};
        curr->topLeft = makeTree(tl, (n>>1));
        curr->topRight = makeTree(tr, (n>>1));
        curr->bottomLeft = makeTree(bl, (n>>1));
        curr->bottomRight = makeTree(br, (n>>1));
        return curr;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        populate(grid, grid.size(), {0, 0});
        Node* root = makeTree( {0, 0} , grid.size());
        return root;
    }
};