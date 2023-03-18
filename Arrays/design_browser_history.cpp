// problem link --> https://leetcode.com/problems/design-browser-history/

// my solution link --> https://leetcode.com/problems/design-browser-history/discuss/3310442/C%2B%2B-oror-91-faster-oror-88-less-memory-oror-Array

class BrowserHistory {
public:
    vector<string> v;
    int ptr;
    BrowserHistory(string homepage) {
        v.clear(); v.push_back(homepage); ptr = 0;
    }
    
    void visit(string url) {
        int n = v.size();
        for(int i = n-1;i>ptr;i--) v.pop_back();
        v.push_back(url); ptr++;
    }
    
    string back(int steps) {
        ptr = max(0, ptr - steps);
        return v[ptr];
    }
    
    string forward(int steps) {
        ptr = min((int)v.size() - 1, ptr + steps);
        return v[ptr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */