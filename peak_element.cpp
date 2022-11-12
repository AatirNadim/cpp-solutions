// find the peak element in the given array
#include <bits/stdc++.h>
using namespace std;
bool peak(vector<int>& v, int idx) {
    if(!idx) return v[idx] > v[idx + 1];
    if(idx == v.size() -1) return v[idx] > v[idx -1];
    return (v[idx] > v[idx - 1] and v[idx] > v[idx + 1]);
}
int main() {
    vector<int> v({30, 20, 15, 2, 98 , 90, 67});
    // vector<int> v({1, 2, 3, 4, 5, 6, 7, 8, 9});
    int minval = 0, maxval= v.size() - 1, medval;
    while(minval < maxval) {
        medval = minval + ((maxval - minval)>>1);
        if(peak(v, medval)) {
            cout<<medval<<" "<<v[medval]; return 0;
        }
        if(v[medval] < v[medval + 1]) minval = medval + 1;
        else maxval = medval - 1;
    }
    cout<<minval<<" "<<v[minval]<<"\n"<<maxval<<" "<<v[maxval];
    return 0;
}