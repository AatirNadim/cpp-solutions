/*
    problem link --> https://www.geeksforgeeks.org/problems/height-of-spiral-tree/1
*/

int func(Node* root) {
    if(!root) return 0;
    // determine whether the current node is the leaf node
    bool a = root->left and root->left->right == root;
    bool b = root->right and root->right->left == root;
    if(a and b) return 1;
    return 1 + max(func(root->left), func(root->right));
}

// Return the height of the given special binary tree
int findTreeHeight(Node* root) {
    return func(root) - 1;
    
}