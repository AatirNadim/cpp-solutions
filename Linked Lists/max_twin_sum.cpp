// problem link --> https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

// my solution link --> https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/discuss/3534513/C%2B%2B-oror-O(n)-time-oror-O(1)-space-oror-Short-and-Simple


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
    int maxval = 0;
    ListNode* traverse(ListNode* temp, int n) {
        if(!n) {
            maxval = max(maxval, temp->val + temp->next->val);
            return temp->next->next;
        }
        ListNode* two = traverse(temp->next, n - 1);
        maxval = max(maxval, temp->val + two->val);
        return two->next;
    }
    int pairSum(ListNode* head) {
        int n =0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;n++;
        }
        traverse(head, (n>>1) - 1);
        return maxval;
    }
};