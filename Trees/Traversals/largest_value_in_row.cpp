/*
    problem link --> https://leetcode.com/problems/find-largest-value-in-each-tree-row/
*/

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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(q.size()) {
            int n = q.size(), maxval = INT_MIN;
            while(n--) {
                TreeNode* currnode = q.front(); q.pop();
                maxval = max(maxval, currnode->val);
                if(currnode->left) q.push(currnode->left);
                if(currnode->right) q.push(currnode->right);
            }
            res.push_back(maxval);
        }
        return res;
    }
};