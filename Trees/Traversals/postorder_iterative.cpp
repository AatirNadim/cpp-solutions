// problem link --> https://leetcode.com/problems/binary-tree-postorder-traversal/

// my solution link --> https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/3978085/C%2B%2B-oror-Iterative-oror-Stack

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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> st;
        vector<int> v;
        st.push(root);
        while(st.size()) {
            TreeNode* currnode = st.top(); st.pop(); 
            v.push_back(currnode->val);
            if(currnode->left) st.push(currnode->left);
            if(currnode->right) st.push(currnode->right);
        }
        return vector<int>(v.rbegin(), v.rend());
    }
};