// given three points, define whether they are arranged in clockwise, counter-clockwise or collinear manner depending on the order they are read
// the most generic way to solve this is to use the slope between the subsequent points
// but the main issue with the basic slope calculation is the potential infinite slope
// although we need the slope in order to determine the cycle version, we only need an impression of the actual slope in order to arrive at the decision
// let us consider the normal slope calculation as,
// slope_diff = (y2 - y1)/(x2 - x1) - (y3 - y2)/(x3 - x2)
// if slope_diff > 0, the arangement is clock-wise
// if slope_diff < 0, the arrangement is counter-clockwise
// else , the arrangement, is collinear
// in order to avoid the trap of infinite slope, let us define the the new_slope_diff as, 
// new_slope_diff = (y2- y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)
// this is allusion to the actual slope_diff, works on the same conditions and avoids the infinite slope trap

// you can literally, verify this statement, plugging in random values.

#include <iostream>
#include <vector>
using namespace std;
struct Point {
    int x, y;
};
int main (){
    cout<<"Give the three points"<<endl;
    vector<Point> v(3);
    for(int i=0;i<3;i++) {
        cin>>v[i].x>>v[i].y;
    }
    int val = (v[1].y - v[0].y)*(v[2].x - v[1].x) - (v[2].y - v[1].y)*(v[1].x - v[0].x);
    if (val) {
        if(val > 0) cout<<"clockwise"<<endl;
        else cout<<"counter-clockwise"<<endl;
    }
    else cout<<"collinear"<<endl;
    return 0;  
}
