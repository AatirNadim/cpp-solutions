/**
// problem link --> https://leetcode.com/problems/minimum-absolute-difference-in-bst/

// my solution link --> https://leetcode.com/problems/minimum-absolute-difference-in-bst/discuss/3185537/C%2B%2B-oror-O(1)-space-oror-O(n)-time-oror-Short-Solution


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
    int res = INT_MAX;
    void dfs(TreeNode* root, int l, int r) {
        if(!root) return;
        if(l + 1) res = min(res, root->val - l);
        if(r + 1) res = min(res, r - root->val);
        int rlimit = (r + 1) ? min(r, root->val) : root->val;
        int llimit = (l + 1) ? max(l, root->val) : root->val;
        dfs(root->left, l, rlimit);
        dfs(root->right, llimit, r);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root, -1, -1);
        return res;
    }
};