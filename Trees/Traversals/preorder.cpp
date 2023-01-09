// problem link --> https://leetcode.com/problems/binary-tree-preorder-traversal/

// my solution links -->
    // recursive --> https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/3023064/  
    //               C%2B%2B-oror-0ms-oror-Recursive-oror-Easy

    // non-recursive --> https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/ 
    //                   3023110/C%2B%2B-oror-0ms-oror-Non-recursive-oror-Easy

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
    vector<int> res;
    void preorder(TreeNode* root) {
        if(!root) return;
        res.push_back(root->val);
        preorder(root->left), preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }
};