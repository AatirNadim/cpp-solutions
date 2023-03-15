// problem link --> https://leetcode.com/problems/check-completeness-of-a-binary-tree/

// my solution link --> https://leetcode.com/problems/check-completeness-of-a-binary-tree/discuss/3299853/C%2B%2B-oror-BFS-oror-Short-and-Simple

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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool done = 0;
        while(q.size()) {
            TreeNode* root = q.front(); q.pop();
            if(done and root->left) return 0;
            if(root->left) q.push(root->left);
            else done = 1;
            if(done and root->right) return 0;
            if(root->right) q.push(root->right);
            else done = 1;
        }
        return 1;
        
    }
};