// given, the number of bacteria, which multiply by a given value at every turn, determine the least number of turns for the number of bacteria to exceed a threshold value.
// a --> original number of bacteria
// b --> threshold value
// c --> number to be multiplied
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll a, b, c;
    cin>>a>>b>>c;
    int res =0;
    while(a < b) {
        a *= c;
        res++;
    }
    cout<<res;
    return 0;
}