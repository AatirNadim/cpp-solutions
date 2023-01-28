// problem link --> https://unstop.com/code/practice/250914

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define uint unsigned int
using namespace std;


uint func(uint n) {
    uint temp = 0;
    int val = 32;
    while(val--) {
        temp<<=1;
        temp |= 1;
    }
    return n^temp;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    uint n;cin>>n;
    cout<<func(n);
    return 0;
}