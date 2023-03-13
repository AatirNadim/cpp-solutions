// Question --> 
// Consider a man on a bicycle, who can climb up and down some mountains, with the magnitude of the peaks (adjacent to each other), being represented in an array. If the arr[i+1] > arr[i], it costs the man (arr[i+1] - arr[i]) amount of energy, to climb. The man is given 'q' magic energy pods, which allow him to climb any mountain, irrespective of their height.
// Suppose the man has some amount of energy stored within, when he is atop the 0th mountain (0 based indexing). Compute, the index of the farthest mountain, which he can climb, if he goes about it optimally.
#include <bits/stdc++.h>
using namespace std;
int main() {
    cout<<"Give the length of the array"<<endl;
    int n;cin>>n;
    vector<int> v(n);
    cout<<"Give the array"<<endl;
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<"Give the initial energy"<<endl;
    int x;cin>>x;
    cout<<"Give the q value"<<endl;
    int q;cin>>q;
    priority_queue<int, vector<int>, greater<int>> pq;
    int i=0;
    for(i=1;i<n and q;i++) {
        int val = v[i] -v[i-1];
        if(val > 0) {
            pq.push(val), q--;
        }
    }
    for(;i<n;i++) {
        int val = v[i] - v[i-1];
        pq.push(val);
        val = pq.top(); pq.pop();
        if(val > x) {
            cout<<i-1<<endl;
            return 0;
        }
        else x -= val;
    }
    cout<<n-1;
    return 0;
}