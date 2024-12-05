/*
problem link --> https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

my soln link --> https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/discuss/6116893/C%2B%2B-oror-Single-DFS

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
    typedef pair<bool, bool> pb;
    pair<string, pb> func(TreeNode* root, int startValue, int destValue, bool leftChild) {
        if(!root) return {"", {0, 0}};
        auto a = func(root->left, startValue, destValue, 1);
        auto b = func(root->right, startValue, destValue, 0);
        if(a.second.first and a.second.second) return a;
        if(b.second.first and b.second.second) return b;
        if(a.second.second or b.second.first) swap(a, b);
        bool startPresent = a.second.first or root->val == startValue;
        bool endPresent = b.second.second or root->val == destValue;
        if(startPresent and endPresent) {
            for(int i = b.first.size() - 1; i >= 0;i--) {
                a.first.push_back(b.first[i]);
            }
            a.second.first = 1, a.second.second = 1;
            return a;
        }
        else if(startPresent) {    
            a.first.push_back('U');
            a.second.first = 1;
            return a;
        }
        else if(endPresent) {
            if(leftChild) b.first.push_back('L');
            else b.first.push_back('R');
            b.second.second = 1;
            return b;
        }
        return {"", {0, 0}};
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto res = func(root, startValue, destValue, 0);
        return res.first;
    }
};