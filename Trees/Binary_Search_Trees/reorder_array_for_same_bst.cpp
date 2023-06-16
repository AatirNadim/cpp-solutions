// problem link --> https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/

// my solution link --> https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/discuss/3644801/C%2B%2B-oror-Recursive-oror-BST-oror-Intuitive


struct Node {
    Node* left, *right;
    int val;
    Node() {
        left = nullptr, right = nullptr, val = 0;
    }
    Node(int val1) {
        left = nullptr, right = nullptr, val = val1;
    }
};
class Solution {
public:
    typedef long long int ll;
    typedef pair<ll, ll> pi;
    int mod = 1e9 + 7;
    vector<vector<int>> dp;
    Node* root;
    
    void add(Node* root, int val) {
        if(val > root->val) {
            if(root->right) add(root->right, val);
            else {
                Node* curr = new Node(val);
                root->right = curr;
            }
        }  
        else {
            if(root->left) add(root->left, val);
            else {
                Node* curr = new Node(val);
                root->left = curr;
            }
        }
    }
    
    void ncr(int n, int r) {
        dp[0][0] = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<=i;j++) {
                if(i and j) {
                    dp[i][j] = (dp[i-1][j-1]%mod + dp[i-1][j]%mod)%mod;
                }
                else if(!i or !j) dp[i][j] = 1;
            }
        }
    }
    
    void construct(vector<int>& nums) {
        root = new Node(nums[0]);
        int n = nums.size();
        for(int i=1;i<n;i++) {
            add(root, nums[i]);
        }
    }
    
    pi no_ways(Node* root) {
        if(!root->left and !root->right) return {1,1};
        pi a, b, res; ll arrange = 0;
        a = {1, 0}; b = {1,0};
        if(root->left) a = no_ways(root->left);
        if(root->right) b = no_ways(root->right);
        if(a.second) arrange = dp[a.second + b.second - 1][a.second - 1];
        if(b.second) arrange = (arrange%mod + dp[a.second + b.second - 1][b.second - 1]%mod)%mod;
        res.first = (a.first%mod * b.first%mod)%mod;
        res.first = (res.first%mod * arrange%mod)%mod;
        res.second = a.second + b.second + 1;
        return res;
    }
    
    int numOfWays(vector<int>& nums) {
        construct(nums);
        int n = nums.size();
        dp = vector<vector<int>>(2*n, vector<int>(2*n));
        ncr(2*n, 2*n);
        pi res = no_ways(root);
        return res.first - 1;
    }
};