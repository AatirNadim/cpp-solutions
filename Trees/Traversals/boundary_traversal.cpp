/*
    problem link --> https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
*/


class Solution {
  public:
  
    vector<int> res;
    
    void leaves(Node* root) {
        if(!root) return;
        if(!root->left and !root->right) {
            res.push_back(root->data);
            return;
        }
        leaves(root->left);
        leaves(root->right);
    }
    
    void rightBoundary(Node* root) {
        if(!root) return;
        if(root->right) rightBoundary(root->right);
        else rightBoundary(root->left);
        if(root->left or root->right) res.push_back(root->data);
    }
    
    void leftBoundary(Node* root) {
        if(!root) return;
        if(root->left or root->right) res.push_back(root->data);
        if(root->left) leftBoundary(root->left);
        else leftBoundary(root->right);
    }
    
    void boundary(Node* root) {
        if(!root) return;
        res.push_back(root->data);
        leftBoundary(root->left);
        leaves(root->left);
        leaves(root->right);
        rightBoundary(root->right);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        boundary(root);
        return res;
    }
};