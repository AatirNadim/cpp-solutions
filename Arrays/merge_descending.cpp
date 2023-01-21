// problem --> merge two descending arrays into one descending array

#include <bits/stdc++.h>
using namespace std;
int func(vector<int>& a, int n, vector<int>& b, int m) {
    vector<int> res;
    int l = 0, r = 0;
    while(l < n and r < n) {
        if(a[l] >= b[r]) res.push_back(a[l++]);
        else res.push_back(b[r++]);
    }
    while(l < n) res.push_back(a[l++]);
    while(r < m) res.push_back(b[r++]);
    return res[((m + n)>>1)];
}
int main() {
    cout<<"Give number of entries in Almirah 1"<<endl;
    int n;cin>>n;
    cout<<"Give the entries"<<endl;
    vector<int> v1(n);
    for(int i=0;i<n;i++) cin>>v1[i];
    cout<<"Give the number of entries in Almirah 2"<<endl;
    int m;cin>>m;
    cout<<"Give the entries"<<endl;
    vector<int> v2(m);
    for(int i=0;i<m;i++) cin>>v2[i];
    // sort(v1.begin(), v1.end()), sort(v2.begin(), v2.end());
    cout<<func(v1, n, v2, m);
    return 0;
}