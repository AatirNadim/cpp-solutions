// problem link --> https://leetcode.com/problems/middle-of-the-linked-list/

// my solution link --> https://leetcode.com/problems/middle-of-the-linked-list/discuss/2879432/C%2B%2B-oror-0ms-oror-100-faster

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
    ListNode* middleNode(ListNode* head) {
        ListNode* one = head, *two = head;
        while(one and one->next) {
            one = one->next->next;
            two= two->next;
        }
        return two;
    }
};