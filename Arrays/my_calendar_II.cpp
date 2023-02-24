// problem link --> https://leetcode.com/problems/my-calendar-ii/

// my solution link --> https://leetcode.com/problems/my-calendar-ii/discuss/3224887/C%2B%2B-oror-Two-Vectors-oror-Short-and-Simple

class MyCalendarTwo {
public:
    vector<vector<int>> prim, overlap;
    MyCalendarTwo() {
        prim.clear(), overlap.clear();
    }
    bool booked(int start, int end) {
        for(vector<int>& v : overlap) {
            if(start < v[1] and end > v[0]) return 1;
        }
        return 0;
    }
    bool book(int start, int end) {
        if(booked(start, end)) return 0;
        for(vector<int>& v : prim) {
            if(start < v[1] and end > v[0]) {
                int start1 = max(start, v[0]), end1 = min(end, v[1]);
                overlap.push_back({max(start, v[0]), min(end, v[1])});
            }
        }
        prim.push_back({start, end});
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */