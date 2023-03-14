// problem link --> https://leetcode.com/problems/sum-root-to-leaf-numbers/

// my solution link --> https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/3294559/C%2B%2B-oror-100-faster-oror-Short-and-Simple

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
    void dfs(TreeNode* root, int val) {
        if(!root->left and !root->right) {
            res += (val*10 + root->val); 
            return;
        }
        if(root->left) dfs(root->left, val*10 + root->val);
        if(root->right) dfs(root->right, val*10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};