// problem link --> https://leetcode.com/problems/dota2-senate/

// my solution link --> https://leetcode.com/problems/dota2-senate/discuss/3486241/C%2B%2B-oror-Circular-Doubly-Linked-List-oror-Short-and-Simple-oror-Alternative


struct Node{
    int idx;
    Node* prev, *next;
    Node() {
        idx = -1;
        prev = nullptr, next = nullptr;
    }
};
class Solution {
public:
    string predictPartyVictory(string senate) {
        Node* root1 = nullptr, *root2 = nullptr, *temp1 = root1, *temp2 = root2;
        int n =senate.size();
        for(int i=0;i<n;i++) {
            if(senate[i] == 'R') {
                if(!root1) {
                    root1 = new Node(); root1->idx = i;
                    temp1 = root1;
                }
                else {
                    temp1->next = new Node(); temp1->next->idx = i;
                    temp1->next->prev = temp1;
                    temp1 = temp1->next;
                }
            }
            else {
                if(!root2) {
                    root2 = new Node(); root2->idx = i;
                    temp2 = root2;
                }
                else {
                    temp2->next = new Node(); temp2->next->idx = i;
                    temp2->next->prev = temp2;
                    temp2 = temp2->next;
                }
            }
        }
        
        if(root1) {temp1->next = root1; root1->prev = temp1;}
        if(root2) {temp2->next = root2; root2->prev = temp2;}
        temp1 = root1, temp2 = root2;
        while(temp1 and temp2) {
            if(temp1->idx < temp2->idx) {
                if(temp2->next == temp2) return "Radiant";
                temp2->prev->next = temp2->next;
                temp2->next->prev = temp2->prev;
                temp1->idx += n;
            }
            else {
                if(temp1->next == temp1) return "Dire";
                temp1->prev->next =temp1->next;
                temp1->next->prev = temp1->prev;
                temp2->idx += n;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return (temp1) ? "Radiant" : "Dire";
    }
};