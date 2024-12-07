/*
    problem link --> https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
*/


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    
    Node* getLoopNode(Node* head) {
        if(!head or !head->next) return nullptr;
        Node* one = head->next, *two = head->next->next;
        while(one and two and two->next and one != two) {
            one = one->next;
            two = two->next->next;
        }
        return (one == two) ? one : nullptr;
    }
    
    void removeLoop(Node* head) {
        // code here
        // just remove the loop without losing any nodes
        Node* loopNode = getLoopNode(head);
        // if there is no loop
        if(!loopNode) return;
        Node* temp = head;
        // if the last node has a pointer to the first node, i.e., the entire list is cyclic, then loopNode will be the head pointer
        while(temp != loopNode and temp->next != loopNode->next) {
            temp = temp->next;
            loopNode = loopNode->next;
        }
        // if the entire list is cyclic, just remove the connection from the last node to the head node
        if(temp == loopNode) {
            while(temp->next != loopNode) temp = temp->next;
            temp->next = nullptr;
        } else {
            // break the loop from the loopNode
            loopNode->next = nullptr;
        }
    }
};
