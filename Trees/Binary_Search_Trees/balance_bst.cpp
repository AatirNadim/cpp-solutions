/*
    problem link --> https://www.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1
*/

class Solution{
    
    void inorder(Node* root, vector<int>& hash) {
        if(!root) return;
        inorder(root->left, hash);
        hash.push_back(root->data);
        inorder(root->right, hash);
    }
    
    Node* buildBST(vector<int>& hash, int left, int right) {
        if(left > right) return nullptr;
        int mid = left + (right - left)/2;
        Node* curr = new Node(hash[mid]);
        curr->left = buildBST(hash, left, mid - 1);
        curr->right = buildBST(hash, mid + 1, right);
        return curr;
    }
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
    	// Code here
    	vector<int> hash;
    	inorder(root, hash);
    	int n = hash.size();
    	return buildBST(hash, 0, n - 1);
    }
};
