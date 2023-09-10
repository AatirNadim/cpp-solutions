// problem link --> https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

// my solution link --> https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/discuss/4026937/C%2B%2B-oror-DFS-oror-Short-and-Simple

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
    int res = 0;
    bool validLeft(vector<int>& temp, int val) {
        if(!temp.size()) return 1;
        if(temp[0] == INT_MIN) return 0;
        return temp[1] < val;
    }
    bool validRight(vector<int>& temp, int val) {
        if(!temp.size()) return 1;
        if(temp[0] == INT_MIN) return 0;
        return temp[0] > val;
    }
    vector<int> dfs(TreeNode* root) {
        if(!root) return {};
        vector<int> a = dfs(root->left), b = dfs(root->right);
        if(validLeft(a, root->val) and validRight(b, root->val)) {
            int minval = a.size() ? a[0] : root->val;
            int maxval = b.size() ? b[1] : root->val;
            int sum = root->val + (a.size() ? a[2] : 0) + (b.size() ? b[2] : 0);
            res = max(res, sum);
            return { minval, maxval, sum };
        }
        return { INT_MIN, INT_MIN, -1 };
        
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};