// problem link --> https://leetcode.com/problems/design-parking-system/

// my solution link --> https://leetcode.com/problems/design-parking-system/discuss/3575965/C%2B%2B-oror-Short-and-Simple

class ParkingSystem {
public:
    vector<int> v;
    ParkingSystem(int big, int medium, int small) {
        v.clear();
        v.push_back(big);
        v.push_back(medium);
        v.push_back(small);
    }
    
    bool addCar(int carType) {
        if(v[carType - 1]) return v[carType - 1]--;
        return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */