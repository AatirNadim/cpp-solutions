// here, out of the three rods, rod 2 is the destination, rod 1 is the current rod, where the discs are stacked and rod 3 is the spare rod.

// 1.for nth rod, 1st rod being the largest rod, move the stack of (n-1) rods to the spare rod
// 2. move the nth rod to the dest_rod
// 3. move the stack of (n-1) rods from the spare rod to the dest_rod.

#include <bits/stdc++.h>
using namespace std;
void move(int start, int end, int curr_tower, int dest_tower, int spare_tower) {
    if(start > end) return;
    move(start + 1, end, curr_tower, spare_tower, dest_tower);
    cout<<"Disc --> "<<start<<"\nmoved from "<<curr_tower<<" to "<<dest_tower<<"\n";
    move(start + 1, end, spare_tower, dest_tower, curr_tower);
}
int main() {
    cout<<"Give the number of discs for the tower of hanoi"<<endl;
    int n;cin>>n;
    move(1, n, 0, 1, 2);
    return 0;
}