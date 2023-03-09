// problem link --> https://leetcode.com/problems/linked-list-cycle-ii/

// my solution link --> https://leetcode.com/problems/linked-list-cycle-ii/discuss/3277247/C%2B%2B-oror-Floyd-Cycle-Detection-oror-Short-and-Simple



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next) return nullptr;
        ListNode* one = head->next, *two = head->next->next, *temp = head;
        while(one and two and two->next and one != two) {
            one = one->next;
            two = two->next->next;
        }
        if(!two or !two->next) return nullptr;
        while(temp != one) {
            temp = temp->next;
            one = one->next;
        }
        return temp;
    }
};