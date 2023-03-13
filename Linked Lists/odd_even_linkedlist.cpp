// problem link --> https://leetcode.com/problems/odd-even-linked-list/

// my solution link --> https://leetcode.com/problems/odd-even-linked-list/discuss/2883419/C%2B%2B-oror-Not-simple-oror-Short-oror-O(1)-space-oror-O(n)-time
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* oddend = head, *currodd = head->next->next, *curreve = head->next;
        while(currodd) {
            curreve->next = currodd->next;
            ListNode* evebegin = oddend->next;
            oddend->next = currodd;
            currodd->next = evebegin;
            curreve = curreve->next;
            oddend = oddend->next;
            currodd = (curreve)? curreve->next:nullptr;
        }
        return head;
    }
};