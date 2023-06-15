// problem link --> https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

// my solution link --> https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/discuss/3640874/C%2B%2B-oror-BFS-oror-Level-Order


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
    int maxLevelSum(TreeNode* root) {
        int res = 0, maxsum = INT_MIN, level =0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            queue<TreeNode*> newq;
            int temp = 0; level++;
            while(q.size()) {
                TreeNode* currnode = q.front(); q.pop();
                temp += currnode->val;
                if(currnode->left) newq.push(currnode->left);
                if(currnode->right) newq.push(currnode->right);
            }
            if(temp > maxsum) {
                maxsum = temp, res = level;
            }
            q = newq;
        }
        return res;
    }
};