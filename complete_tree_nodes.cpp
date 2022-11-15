// Question link --> https://leetcode.com/problems/count-complete-tree-nodes/description/
// Solution link --> https://leetcode.com/problems/count-complete-tree-nodes/solutions/2818367/c-short-and-simple/
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left = 0, right = 0;
        TreeNode* temp = root;
        while(temp) temp = temp->left, left++;
        temp = root;
        while(temp) temp = temp->right, right++;
        if(left - right) return 1 + countNodes(root->left) + countNodes(root->right);
        return (1<<left) - 1;
    }
};