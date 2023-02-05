// problem link --> https://practice.geeksforgeeks.org/problems/eae1fbd0ac8f213a833d231e26ba4d829e79dd9c/1

class Solution
{
public:
    int length(Node* head) {
        int res = 0;
        Node* temp = head;
        while(temp) {
            res++, temp = temp->next;
        }
        return res;
    }
    int intersectPoint(Node* head1, Node* head2) {  
        int m = length(head1), n = length(head2), k;
        if(m < n) {
            swap(head1, head2); swap(m, n);
        }
        k = m - n;
        Node* temp1 = head1, *temp2 =head2;
        while(k--)  temp1 = temp1->next;
        while(temp1 and temp2 and temp1 != temp2) {
            temp1 = temp1->next, temp2 = temp2->next;
        }
        return temp1->data;
    }
};
