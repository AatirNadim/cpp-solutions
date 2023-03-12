// problem link --> https://leetcode.com/problems/merge-k-sorted-lists/

// my solution link --> https://leetcode.com/problems/merge-k-sorted-lists/discuss/3289276/C%2B%2B-oror-Short-and-Simple-oror-Recursion




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
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        if(!a) return b;
        if(!b) return a;
        ListNode* res;
        if(a->val < b->val) {
            res = a;
            res->next = merge(a->next, b);
        }
        else {
            res = b;
            res->next = merge(a, b->next);
        }
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(!n) return nullptr;
        ListNode* root = lists[0];
        for(int i=1;i<n;i++) {
            root = merge(root, lists[i]);
        }
        return root;
    }
};