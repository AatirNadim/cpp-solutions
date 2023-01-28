// problem link --> https://unstop.com/code/practice/250278

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    vector<int> v(n);
    int minval = INT_MAX, secmin = INT_MAX, maxval = INT_MIN, secmax = INT_MIN;
    for(int &i : v) {
        cin>>i;
        if(i <= minval) {
            secmin = minval, minval = i;
        }
        else if(i < secmin) secmin = i;
        if(i >= maxval) {
            secmax = maxval, maxval = i;
        }
        else if(i > secmax) secmax = i;
    }
    cout<<max(minval*secmin + abs(minval - secmin), maxval*secmax + abs(maxval - secmax));

    return 0;
}