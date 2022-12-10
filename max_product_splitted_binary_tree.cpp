// problem link --> https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

// my solution link --> https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/discuss/2896853/C%2B%2B-oror-96-faster-oror-78-less-memory-oror-Intuitive-oror-Easy

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
#define ll long long int
#define val1 1000000007
class Solution {
public:
    ll res = 0;
    int dfs1(TreeNode* root) {
        if(!root) return 0;
        root->val += dfs1(root->left) + dfs1(root->right);
        return root->val;
    }
    void dfs2(TreeNode* root, ll sum_till_now) {
        if(!root or (!root->left and !root->right)) return;
        int a = 0, b = 0;
        if(root->left) {
            ll sum1 = sum_till_now + root->val - root->left->val;
            ll sum2 = root->left->val;
            res = max(res, sum1*sum2);
            dfs2(root->left, sum_till_now + root->val - root->left->val);
        }
        if(root->right) {
            ll sum1 = sum_till_now + root->val - root->right->val;
            ll sum2 = root->right->val;
            res = max(res, sum1*sum2);
            dfs2(root->right, sum_till_now + root->val - root->right->val);
        }
    }
    int maxProduct(TreeNode* root) {
        dfs1(root);
        dfs2(root, 0);
        return (int)(res%val1);
    }
};