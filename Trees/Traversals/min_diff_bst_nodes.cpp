// problem link --> https://leetcode.com/problems/minimum-distance-between-bst-nodes/

// my solution link --> https://leetcode.com/problems/minimum-distance-between-bst-nodes/discuss/3197117/C%2B%2B-oror-0ms-oror-Inorder-Traversal-oror-Short-and-Simple

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
    int prev = -1, res = INT_MAX;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        if(prev + 1) res = min(res, root->val - prev);
        prev = root->val;
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return res;
        
    }
};