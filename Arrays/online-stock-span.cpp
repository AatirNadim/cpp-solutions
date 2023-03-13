// Question link --> https://leetcode.com/problems/online-stock-span/description/
//solution link --> https://leetcode.com/problems/online-stock-span/solutions/2796763/c-short-and-simple-easy-implementation/

class StockSpanner {
public:
    stack<pair<int, int>> st; int idx;
    StockSpanner() {
        idx = 1;
    }
    
    int next(int price) {
        while(st.size() and st.top().first <= price) st.pop();
        int res = idx;
        if(st.size()) res -= st.top().second;
        // else res = 1;
        st.push({price, idx++});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */