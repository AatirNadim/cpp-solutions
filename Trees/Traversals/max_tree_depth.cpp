// problem link --> https://leetcode.com/problems/maximum-depth-of-binary-tree/

// my solution link --> https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/3193559/C%2B%2B-oror-DFS-oror-Short-and-Simple

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int val1 = 0, val2 = 0;
        if(root->left) val1 = maxDepth(root->left);
        if(root->right) val2 = maxDepth(root->right);
        return 1 + max(val1, val2);
        
    }
};