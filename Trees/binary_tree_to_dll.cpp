/*
    problem link --> https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1
*/

class Solution {
  public:
    // for every function call, we need the first and the last node of the dll produced so far

  pair<Node*, Node*> func(Node* root) {
      if(!root) return { root, root };
      auto leftSeg = func(root->left);
      
      if(leftSeg.second) {
          leftSeg.second->right = root;
      }
      root->left = leftSeg.second;
      auto rightSeg = func(root->right);
      root->right = rightSeg.first;
      if(rightSeg.first) {
          rightSeg.first->left = root;
      }
      return { leftSeg.first ? leftSeg.first : root, 
      rightSeg.second ? rightSeg.second : root };
  }
    Node* bToDLL(Node* root) {
        // code here
        if(!root) return root;
        auto res = func(root);
        return res.first;
    }
};