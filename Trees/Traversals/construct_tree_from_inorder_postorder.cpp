// problem link --> https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// my solution link --> https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/3305349/C%2B%2B-oror-Logical-Analysis-oror-Short-and-Simple



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
    unordered_map<int, int> in_idx;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int in_l, int in_r, int post_l, int post_r) {
        if(in_l > in_r) return nullptr;
        TreeNode* root = new TreeNode(postorder[post_r]);
        
        int in_root_idx = in_idx[postorder[post_r]];
        int new_post_right = post_l + (in_root_idx - in_l);
        root->left = build(inorder, postorder, in_l, in_root_idx - 1, post_l, new_post_right - 1);
        root->right = build(inorder, postorder, in_root_idx + 1, in_r, new_post_right, post_r - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), root_val;
        for(int i=0;i<n;i++) in_idx[inorder[i]] = i;
        root_val = postorder[n-1];
        TreeNode* root = new TreeNode(root_val);
        root->left = build(inorder, postorder, 0, in_idx[root_val] - 1, 0, in_idx[root_val] - 1);
        root->right = build(inorder, postorder, in_idx[root_val] + 1, n-1, in_idx[root_val], n-2);
        return root;
        
    }
};