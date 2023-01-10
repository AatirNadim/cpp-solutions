// problem link --> https://leetcode.com/problems/same-tree/

// my solution link --> https://leetcode.com/problems/same-tree/discuss/3029729/C%2B%2B-oror-0ms-oror-2-lines-oror-Recursion

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return 1;
        return p and q and (p->val == q->val) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};