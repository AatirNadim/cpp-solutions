#define ll long long int
#include <bits/stdc++.h>

using namespace std;

vector<int> maxSubarray(vector<int> arr, int n) {
    vector<ll> hash(n);
    hash[0] = arr[0];
    for(int i=1;i<n;i++) hash[i] = hash[i-1] + arr[i];
    ll minyet = 0, res1 = INT_MIN, res2 = INT_MIN;
    for(ll& i : hash) {
        res1 = max(res1, i - minyet);
        minyet = min(minyet, i);
    }
    sort(arr.begin(), arr.end());
    for(int&i : arr) {
        res2 = max((ll)i, res2 + i);
    }
    return {(int)res1, (int)res2};
}

int main()
{
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    v = maxSubarray(v, n);
    cout<<"Maximum subarray sum --> "<<v[0]<<"\n";
    cout<<"Maximum subsequence sum --> "<<v[1]<<"\n";
    return 0;
}

