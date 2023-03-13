// Question link --> https://leetcode.com/problems/find-median-from-data-stream/description/

// My solution link --> https://leetcode.com/problems/find-median-from-data-stream/solutions/2806357/c-multiset-tree-structure-o-nlogn-insertion-o-1-calculation/


class MedianFinder {
public:
    multiset<int> st;
    multiset<int>:: iterator itr;
    MedianFinder() {
        st.clear();
        // itr = nullptr;
    }
    
    void addNum(int num) {
        if(!st.size()) {
            st.insert(num); itr = st.begin(); return;
        }
        if(st.size()&1) {
            st.insert(num);
            if(num < *itr) { itr--; }
            else {  }
        }
        else {
            st.insert(num);
            if(num < *itr) {  }
            else { itr++; }
        }
        // cout<<num<<" --> "<<*itr<<"\n";
    }
    
    double findMedian() {
        if(st.size()&1) {
            return *itr;
        }
        auto itr1 = itr; itr1++;
        // cout<<*itr<<" "<<*itr1<<"\n";
        return (*itr + *itr1)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */