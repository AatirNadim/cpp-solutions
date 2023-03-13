// given two line segments, (four points, two corresponding to each segment),
// determine, whether they are intersecting
// at the first glance, this seems quite a straightforward problem, but unravels to be much intricate requiring exhaustive thought process
// the main issue regarding the management of the points, is that this requires tweaking the original function which computes the clockwise or other arrangement of three points.
// here, for each line segment, we have to handle the clockwise or other arrangement of the other two points in a specific manner

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct point {
    int x, y;
};
// void get_right(vector<point>& v) {
//     if (v[0].x > v[1].x) {
//         swap(v[0], v[1]);
//     }
// }
int cycle_version(point& p0, point& p1, point& p2) {
    int val= (p1.y - p0.y)*(p2.x - p1.x) - (p2.y - p1.y)*(p1.x - p0.x);
    if(val) { return (val > 0)? 1: -1; }   
    return 0;
}
bool collinear_intersect(vector<point>& v1, vector<point>& v2) {
    int val1 = abs(v1[1].x - v1[0].x), val2 = abs(v2[1].x - v2[0].x);
    int val3 = max(abs(v1[0].x - v2[1].x), abs(v2[0].x - v1[1].x));
    return val1 + val2 >= val3;
}
// bool intersecting(int a, int b) {
//     if (!a || !b) return 1;
//     return (a+b) == 0;
// }
int main() {
    vector<point> v1(2), v2(2);
    cout<<"Give the four points"<<endl;
    for(int i=0;i<2;i++) {
        cin>>v1[i].x>>v1[i].y;
    }
    for(int i=0;i<2;i++) {
        cin>>v2[i].x>>v2[i].y;
    }
    // get_right(v1), get_right(v2);
    int l1p2 = cycle_version(v1[0], v1[1], v2[0]); //-1, 0, 1
    int l1q2 = cycle_version(v1[0], v1[1], v2[1]); //-1, 0, 1
    int l2p1 = cycle_version(v2[0], v2[1], v1[0]); //-1, 0, 1
    int l2q1 = cycle_version(v2[0], v2[1], v1[1]); //-1, 0, 1
    int val1 = abs(l1p2 + l1q2), val2 = abs(l2p1 + l2q1);
    if(val1 == 2 || val2 == 2) {
        cout<<"not intersecting"<<endl;
    } 
    else if (val1 || val2) {
        cout<<"intersecting"<<endl;
    }
    else {
        if(l1p2 == l1q2) {
            if(collinear_intersect(v1, v2)) {
                cout<<"intersecting"<<endl;
            }
            else cout<<"not intersecting"<<endl;
        }
        else cout<<"intesecting"<<endl;
    }
    return 0;
}