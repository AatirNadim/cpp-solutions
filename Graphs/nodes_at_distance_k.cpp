// problem link --> https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

// my solution link --> https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/2878186/C%2B%2B-oror-O(n)-time-oror-O(n)-space

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int, vector<int>> adj;
    vector<int> res;
    void dfs(TreeNode* root) {
        if(!root) return;
        if(root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if(root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
    void dfs(int curr, int k, int parent) {
        if(!k) {
            res.push_back(curr); return;
        }
        for(int child : adj[curr]) {
            if(child - parent) dfs(child, k-1, curr);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        unordered_map<int, bool> vis;
        vis[target->val] = 1;
        dfs(target->val, k, -1);
        return res;
    }
};