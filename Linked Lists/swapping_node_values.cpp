// problem link --> https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// my solution link --> https://leetcode.com/problems/swapping-nodes-in-a-linked-list/discuss/3526512/C%2B%2B-oror-Single-Traversal-oror-Short-and-Simple

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
    ListNode* swapNodes(ListNode* head, int k) {
        int k1 = k - 1;
        ListNode* temp = head, *one = head, *two = head;
        while(k1--) {
            temp = temp->next;
        }
        one = temp;
        while(temp->next) {
            temp = temp->next;
            two = two->next;
        }
        swap(one->val, two->val);
        return head;
    }
};