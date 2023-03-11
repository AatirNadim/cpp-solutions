// problem link --> https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

// my solution link --> https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/discuss/3285238/C%2B%2B-oror-100-less-memory-oror-85-faster-oror-Short-and-Simple





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    int len = 0;
    ListNode* itr;
    void create(TreeNode* root, int left, int right) {
        if(left >= right) return;
        int mid = left + ((right - left)>>1);
        if(mid > left) {
            TreeNode* l = new TreeNode();
            root->left = l;
            create(l, left, mid - 1);
        }
        if(mid < right) {
            TreeNode* r = new TreeNode();
            root->right = r;
            create(r, mid + 1, right);
        }
    }
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        root->val = itr->val;
        itr = itr->next;
        inorder(root->right);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        itr = head;
        while(temp) {
            temp = temp->next; len++;
        }
        if(!len) return nullptr;
        TreeNode* root = new TreeNode();
        create(root, 0, len-1);
        inorder(root);
        return root;
    }
};