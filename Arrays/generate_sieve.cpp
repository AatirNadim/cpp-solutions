// problem --> Generate prime sieve

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int val = 1e9 + 7;
    vector<bool> sieve((ll)val + 1, 1);
    
    for(int i=3;i<=sqrt(val); i++) {
        for(int j=i*i; j<= val; j+=i) sieve[j] = 0;
    }
    for(bool b : sieve) cout<<b<<" ";
    return 0;
}