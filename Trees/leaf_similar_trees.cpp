
//problem link --> https://leetcode.com/problems/leaf-similar-trees/

// my solution link --> https://leetcode.com/problems/leaf-similar-trees/discuss/2891281/C%2B%2B-oror-Optimized-oror-Queue-oror-Easy
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
    queue<int> q; bool val = 1;
    void dfs(TreeNode* root) {
        if(!root) return;
        if(!root->left and !root->right) {
            q.push(root->val); return;   
        }
        dfs(root->left);
        dfs(root->right);
    }
    void dfs1(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) {
            if(!q.size() or q.front() - root->val) { val= 0; return;}
            q.pop();
        }
        dfs1(root->left);
        dfs1(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1) return !root2;
        dfs(root1);
        dfs1(root2);
        return val and !q.size();
    }
};