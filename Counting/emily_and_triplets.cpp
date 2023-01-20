// problem link --> https://my.newtonschool.co/playground/code/4xou6azsockq


// interestingly, the only way to consider all the cases is not to infer a case from an existing case, but to count all the cases individually.
// this can be head-scratcher on account of how straightforward it actually is.


#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int to_add(int &i, int &j, int &k) {
    unordered_map<int, int> mp;
    mp[i] = 1, mp[j] = 1, mp[k] = 1;
    if(mp.size() == 1) return 1;
    else if(mp.size() == 2) return 3;
    return 6;
}
int func(int &s, int &t) {
    int res = 0;
    int val = s;
    for(int i=0;i<=val;i++) {
        for(int j=i;j<=val;j++) {
            for(int k=j;k<=val;k++) {
                if(i + j + k <= s and i*j*k <= t)
                res += to_add(i, j, k);
            }
        }
    }
    return res;
}

int main() {
	// cout<<"Mohammad Aatir Nadim"<<endl;
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int s, t;
    cin>>s>>t;
    cout<<func(s, t);
    return 0;
}