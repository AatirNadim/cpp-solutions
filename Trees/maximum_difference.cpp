//problem link --> https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

// my solution link --> https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/discuss/2894317/C%2B%2B-oror-Short-and-Simple-oror-DFS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int maxyet, int minyet) {
        if(!root) return;
        res = max({res, abs(maxyet - root->val), abs(minyet - root->val)});
        dfs(root->left, max(maxyet, root->val), min(minyet, root->val));
        dfs(root->right, max(maxyet, root->val),min(minyet, root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val,root->val);
        return res;
    }
};