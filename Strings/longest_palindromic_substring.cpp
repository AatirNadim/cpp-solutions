// find the longest palindromic substring in quadratic time

#include <bits/stdc++.h>
using namespace std;
pair<int, int> match(string s, int left, int right, int n) {
    while(left > -1 and right < n and s[left] == s[right]) left--, right++;
    return {left +1, right - 1};
}
string findOdd(string s) {
    int n = s.size();
    pair<int, int> hash = {0,0}, temp;
    for(int i=0;i<n;i++) {
        temp = match(s, i, i, n);
        if(temp.second - temp.first > hash.second - hash.first) hash = temp;
    }
    return s.substr(hash.first, hash.second -hash.first + 1);
}
string findEve(string s) {
    int n = s.size();
    pair<int, int> hash = {-1,-1}, temp;
    for(int i=0;i<n-1;i++) {
        temp = match(s, i, i+1, n);
        if(temp.second - temp.first > hash.second - hash.first) hash = temp;
    }
    if(hash.first - hash.second) return s.substr(hash.first, hash.second - hash.first + 1);
    return "";
}
int main() {
    cout<<"Give the string to find the longest palindromic substring"<<endl;
    string s;cin>>s;
    string temp = findOdd(s), temp1 = findEve(s);
    (temp.size() > temp1.size())?cout<<temp<<endl:cout<<temp1<<endl;
    return 0;
}