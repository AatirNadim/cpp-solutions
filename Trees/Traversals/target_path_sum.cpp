/*
    problem link --> https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1
*/

class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        if(!root) return 0;
        if(!root->left and !root->right) return root->data == target;
        return hasPathSum(root->left, target - root->data) or 
            hasPathSum(root->right, target - root->data);
        
    }
};