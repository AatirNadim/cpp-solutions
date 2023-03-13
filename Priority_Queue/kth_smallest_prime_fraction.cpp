// problem link --> https://leetcode.com/problems/k-th-smallest-prime-fraction/

// Frankly, I had to take a high degree of reference for this question for various reasons. Hence, I learned a ton from this as well.

class Node {
    public:
    double left, right; int lidx, ridx;
    Node(double l, double r, int li, int ri) {
        left = l, right = r, lidx = li, ridx = ri;
    }
};
class compt {
    public:
    bool operator() (Node& n1, Node& n2) {
        double a = n1.left/n1.right, b = n2.left/n2.right;
        return a > b;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<Node, vector<Node>, compt> pq;
        int n= arr.size();
        for(int i=0;i<n-1;i++) {
            pq.push(Node((double)arr[i], (double)arr[n-1], i, n-1));
        }      
        while(pq.size()) {
            auto currnode = pq.top(); pq.pop();
            k--;
            if(!k) {
                return {(int)currnode.left, (int)currnode.right};
            }
            int lidx = currnode.lidx, ridx = currnode.ridx;
            if(ridx - 1 > lidx) {
                pq.push(Node(currnode.left, (double)arr[ridx - 1], currnode.lidx, ridx - 1));
            }
        }
        return {};
    }
};