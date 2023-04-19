// problem link --> https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

// mny solution link --> https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/discuss/3433952/C%2B%2B-oror-DFS-oror-Short-and-Simple


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
typedef pair<int, int> pi;
class Solution {
public:
    int res = 0;
    pi dfs(TreeNode* root) {
        // if(!root->left and !root->right) return {0, 0};
        pi a = {-1, -1}, b = {-1, -1}, ans;
        if(root->left) a = dfs(root->left);
        if(root->right) b = dfs(root->right);
        ans = {a.second + 1, b.first + 1};
        res = max({res, ans.first, ans.second});
        return ans;
    }
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res;
    }
};