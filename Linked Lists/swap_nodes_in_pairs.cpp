// problem link --> https://leetcode.com/problems/swap-nodes-in-pairs/

// my solution link --> https://leetcode.com/problems/swap-nodes-in-pairs/discuss/3531155/C%2B%2B-oror-0ms-oror-Short-and-Simple

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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode* prev = nullptr, *temp = head->next, *res = head;
        while(temp) {
            ListNode* one = (prev) ? prev->next: head;
            one->next = temp->next;
            if(prev) prev->next = temp;
            else res = temp;
            temp->next = one;
            prev = one; 
            if(one->next) temp = one->next->next;
            else break;
        }
        return res;
    }
};