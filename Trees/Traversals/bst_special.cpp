// problem link --> https://practice.geeksforgeeks.org/problems/c85e3a573a7de6dfd18398def16d05387852b319/1


class Solution{
public:

    ll res = 0;
    int x = -1, y = -1;
    Node* temp = nullptr;
    void getNode(Node* root, int target, int currx, int curry) {
        if(!root or temp) return;
        if(root->data == target) {
            temp = root; 
            x = currx, y = curry;
            return;
        }
        getNode(root->left, target, currx - 1, curry + 1);
        getNode(root->right, target, currx + 1, curry + 1);
    }
    void dfs(Node* root, int currx, int curry) {
        if(!root) return;
        if(curry > y and currx == x) res += root->data;
        dfs(root->left, currx - 1, curry + 1);
        dfs(root->right, currx + 1, curry + 1);
    }
    
    ll verticallyDownBST(Node *root,int target){
        // Code here
        getNode(root, target, 0, 0);
        if(temp){
            dfs(temp, x, y);
            return res;
        } 
        return -1;
    }
};

