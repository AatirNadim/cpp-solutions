// problem link --> https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

// my solution link --> https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/discuss/3200179/C%2B%2B-oror-BFS-oror-Short-and-Simple

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        bool doit = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        while(q.size()) {
            queue<TreeNode*> newq;
            while(q.size()) {
                TreeNode* root = q.front(); q.pop();
                if(doit) {
                    root->val = temp.back(); temp.pop_back();
                }
                else if(root->left)
                    temp.push_back(root->left->val), temp.push_back(root->right->val);
                if(root->left) newq.push(root->left), newq.push(root->right);
            }
            doit = !doit;
            q = newq;
        }
        return root;
    }
};