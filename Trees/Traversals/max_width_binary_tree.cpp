// problem link --> https://leetcode.com/problems/maximum-width-of-binary-tree/

// my solution link --> https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/3983653/C%2B%2B-oror-0ms-oror-Short-and-Simple

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
    typedef long long int ll;
    typedef pair<TreeNode*, ll> pi;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        ll res = 0;
        queue<pi> q;
        q.push({root, 1});
        while(q.size()) {
            int n = q.size(); ll diff = -101;
            ll left = -101, right = -101;
            while(n--) {
                pi currnode = q.front(); q.pop();
                if(currnode.first->left and diff == -101)
                    diff = (currnode.second<<1);
                if(currnode.first->right and diff == -101)
                    diff = (currnode.second<<1) + 1;
                if(left == -101) left = currnode.second;
                right = currnode.second;
                if(currnode.first->left) {
                    q.push({currnode.first->left, (currnode.second<<1) - diff + 1});
                }
                if(currnode.first->right) {
                    q.push({currnode.first->right, (currnode.second<<1) - diff + 2});
                }
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};