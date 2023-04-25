// problem link --> https://leetcode.com/problems/smallest-number-in-infinite-set/

// my solution link --> https://leetcode.com/problems/smallest-number-in-infinite-set/discuss/3452950/C%2B%2B-oror-Constraint-Based-oror-Short-and-Simple


class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        st.clear();
        for(int i=1;i<=1000;i++) st.insert(i);
        
    }
    
    int popSmallest() {
        int val = *st.begin(); 
        st.erase(st.begin());
        return val;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */