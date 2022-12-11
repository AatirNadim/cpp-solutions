// problem link --> https://leetcode.com/problems/binary-tree-maximum-path-sum/

// my solution link --> https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/2901881/C%2B%2B-oror-DFS-oror-Recursion

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
    int res = -1001;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root->left), right = dfs(root->right),val = root->val;
        val = max(val,val + left); val = max(val, val + right);
        res = max(res, val);
        return max({left, right, 0}) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};