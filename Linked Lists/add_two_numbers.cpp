// problem link --> https://leetcode.com/problems/add-two-numbers/

// my solution link --> https://leetcode.com/problems/add-two-numbers/discuss/3497063/C%2B%2B-oror-Short-and-Simple

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1, *temp2 = l2, *prev = nullptr;
        while(temp1 and temp2) {
            temp1 = temp1->next, temp2 = temp2->next;
        }
        if(temp1) swap(l1, l2);
        temp1 = l1, temp2 = l2;
        int carry = 0;
        while(temp1 and temp2) {
            temp2->val += temp1->val + carry;
            carry = temp2->val/10;
            temp2->val %=10;
            temp1 = temp1->next, temp2 = temp2->next;
            if(prev) prev = prev->next;
            else prev = l2;
        }
        while(temp2) {
            temp2->val += carry;
            carry = temp2->val/10;
            temp2->val %=10;
            temp2 = temp2->next;
            if(prev) prev = prev->next;
            else prev = l2;
        }
        if(carry) prev->next = new ListNode(carry);
        return l2;
    }
};