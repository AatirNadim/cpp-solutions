// problem link --> https://leetcode.com/problems/maximum-width-of-binary-tree/

// my solution link --> https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/3437661/C%2B%2B-oror-BFS-oror-Intuitive-Approach



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
typedef long long int ll;
typedef pair<TreeNode*, ll> pi;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll res = 0;
        queue<pi> q;
        q.push({root, 1});
        while(q.size()) {
            int n = q.size();
            ll itr = 1, left = -101, right;
            ll diff = -101;
            while(n--) {
                pi currnode = q.front(); q.pop();
                if(left == -101) left = currnode.second;
                right = currnode.second;
                if(diff == -101 and currnode.first->left)
                    diff = (currnode.second<<1) - 1;
                if(diff == -101 and currnode.first->right)
                    diff = (currnode.second<<1) + 1 - 1;
                if(currnode.first->left)
                    q.push({currnode.first->left, (currnode.second<<1) - diff});
                if(currnode.first->right) 
                    q.push({currnode.first->right, (currnode.second<<1) - diff + 1});
            }
            // cout<<left<<" "<<right<<"\n";
            res = max(res, right - left + 1);
        }
        return (int)res;
    }
};