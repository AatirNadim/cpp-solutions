
// problem --> Given an array of no-negative elements, determine the shortest subarray such that the sum of the taken subarray is divible by the value given in input.

// tip --> always segregate the problem on modulo values when the problem pertains to division.


#include <bits/stdc++.h>
using namespace std;
int main() {
    cout<<"Give the length of the array"<<endl;
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<"Give the value of k"<<endl;
    int k;cin>>k;
    for(int i=1;i<n;i++) v[i] += v[i-1];
    vector<vector<int>> positions(k);
    for(int i=0;i<n;i++) {
        positions[v[i]%k].push_back(i);
    }
    int res = n+1, left = -1, right = n;
    for(int i=0;i<k;i++) {
        int m = positions[i].size();
        for(int j=0;j<m-1;j++) {
            if (res > positions[i][j+1] - positions[i][j]) {
                res = positions[i][j+1] - positions[i][j];
                left = positions[i][j], right = positions[i][j+1];
            } 
        }
    }
    cout<<"Shortest subarray length --> "<<res<<endl;
    cout<<"Subarray --> "<<endl;
    for(int i = left;i<=right;i++) cout<<v[i]<<" ";
    return 0;
    return 0;
}