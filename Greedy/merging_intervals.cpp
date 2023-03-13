// problem --> Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals.

#include <bits/stdc++.h>
using namespace std;
bool compt(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}
int main() {
    cout<<"Give the total number of intervals"<<endl;
    int n;cin>>n;
    vector<vector<int>> v(n, vector<int>(2));
    cout<<"Give the intervals"<<endl;
    for(int i=0;i<n;i++) cin>>v[i][0]>>v[i][1];
    vector<vector<int>> res;
    sort(v.begin(), v.end(), compt);
    int beg = v[0][0], end = v[0][1], idx = 1;
    while(idx < n) {
        if(v[idx][0] > end) {
            res.push_back({beg, end});
            beg = v[idx][0];
        }
        end = max(end, v[idx][1]);
        idx++;
    }
    res.push_back({beg, end});
    for(vector<int>& temp : res) cout<<temp[0]<<" "<<temp[1]<<endl;
    return 0;
}
