// problem link --> https://leetcode.com/problems/clone-graph/

// my solution link --> https://leetcode.com/problems/clone-graph/discuss/3393019/C%2B%2B-oror-0ms-oror-DFS-oror-9-line-code-oror-Short-and-Simple


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(mp[node]) return mp[node];
        Node* root = new Node(node->val);
        mp[node] = root;
        for(Node* child : node->neighbors) {
            root->neighbors.push_back(cloneGraph(child));
        }
        return root;
    }
};