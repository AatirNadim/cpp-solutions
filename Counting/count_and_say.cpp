// Question --> Given a string consisting only of numerals, return a string which describes the number of times every character appears continuously.
//this is count and say problem available on leetcode
#include <bits/stdc++.h>
using namespace std;
string func(string s) {
    string res = "";
    auto itr = s.begin();
    while(itr != s.end()) {
        char c = *itr;int num = 0; 
        while(itr != s.end() and *itr == c) itr++, num++;
        res += to_string(num);
        res.push_back(c);
    }
    return res;
}
int main() {
    cout<<"Give the original string"<<endl;
    string s;cin>>s;
    cout<<"Give the number of times the operation is to be performed"<<endl;
    int n;cin>>n;
    while(n--) s = func(s);
    cout<<s<<endl;
    return 0;
    
}