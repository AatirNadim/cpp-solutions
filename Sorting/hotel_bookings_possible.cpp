/*
    problem link --> https://www.interviewbit.com/problems/hotel-bookings-possible/
*/

/*
    the thing of importance to note here is that every arrival can be mapped to its own departure, but when 
    we are counting the number of rooms then this mapping serves no purpose, we only need to know when the no of 
    occupied rooms will increase and decrease

    if at any point, the current occupancy reaches beyond the limit, the entire arrangement is not possible
*/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int left = 0, right = 0, n = arrive.size();
    int curr = 0;
    while(left < n and right < n) {
        if(arrive[left] <= depart[right]) {
            curr++;
            left++;
        }
        else {
            right++; curr--;
        }
        if(curr > K) return 0;
    }
    return 1;
}
