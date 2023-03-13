// problem link --> https://leetcode.com/problems/symmetric-tree/

// my solution link --> https://leetcode.com/problems/symmetric-tree/discuss/3290757/C%2B%2B-oror-DFS-oror-Short-and-Simple



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
    bool sym(TreeNode* a, TreeNode* b) {
        if(!a and !b) return 1;
        if(!a or !b) return 0;
        return a->val == b->val and sym(a->left, b->right) and sym(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return sym(root->left, root->right);
    }
};