// problem link --> https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// my solution link --> https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/discuss/3205929/C%2B%2B-oror-Stack-Approach-oror-Short-and-Simple

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*> st;
        st.push(root); bool temp = 0;
        vector<vector<int>> res;
        while(st.size()) {
            stack<TreeNode*> newt;
            vector<int> v;
            while(st.size()) {
                TreeNode* curr = st.top(); st.pop();
                v.push_back(curr->val);
                TreeNode* a = curr->left, *b = curr->right;
                if(temp) swap(a, b);
                if(a) newt.push(a);
                if(b) newt.push(b);
            }
            temp = !temp;
            st = newt;
            res.push_back(v);
        }
        return res;
    }
};