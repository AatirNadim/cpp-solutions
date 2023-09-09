// problem link --> https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

// my solution link --> https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/4023669/C%2B%2B-oror-0ms-oror-Short-and-Simple

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 1, n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        while(idx < n) {
            TreeNode* node = new TreeNode(preorder[idx]), *temp = nullptr;
            while(st.size() and st.top()->val < node->val) {
                temp = st.top(); st.pop();
            }
            if(temp) {
                temp->right = node;
            }
            else st.top()->left = node;
            st.push(node); idx++;
        }
        return root;
    }
};