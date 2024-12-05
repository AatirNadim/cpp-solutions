/*
    problem link --> https://www.geeksforgeeks.org/problems/construct-tree-1/1
*/

class Solution {
  public:
  unordered_map<int, int> mp;
  
    Node* func(vector<int>& inorder, vector<int>& preorder, int idx, int& n) {
        if(idx == n) return nullptr;
        Node* currnode = new Node(preorder[idx]);
        if(idx == n-1) return currnode;
        int idx1 = idx + 1;
        if(mp[preorder[idx + 1]] < mp[preorder[idx]]) {
            currnode->left = func(inorder, preorder, idx + 1, n);
            idx1++;
        }
        while(idx1 < n and mp[preorder[idx1]] < mp[preorder[idx]]) idx1++;
        currnode->right = func(inorder, preorder, idx1, n);
        return currnode;
    }
  
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // Code here
        int n = inorder.size();
        for(int i=0;i<n;i++) mp[inorder[i]] = i;
        int idx = 0;
        return func(inorder, preorder, idx, n);
    }
};