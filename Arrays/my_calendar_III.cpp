// problem link --> https://leetcode.com/problems/my-calendar-iii/

// my solution link --> https://leetcode.com/problems/my-calendar-iii/discuss/3225417/C%2B%2B-oror-Line-Sweep

class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int start, int end) {
        mp[start]++, mp[end]--;
        int res = 0, curr = 0;
        for(auto&p : mp) {
            curr += p.second;
            res = max(res, curr);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */