// problem link --> https://leetcode.com/problems/snapshot-array/

// my solution link --> https://leetcode.com/problems/snapshot-array/discuss/3626067/C%2B%2B-oror-Binary-Search-oror-Design-oror-Short-and-Simple

class SnapshotArray {
public:
    typedef pair<int, int> pi;
    int snap_id = 0; vector<vector<pi>> hash;
    SnapshotArray(int length) {
        hash = vector<vector<pi>>(length, vector<pi>(1, {0, 0}));
        snap_id = 0;
    }
    
    void set(int index, int val) {
        if(hash[index].back().first == snap_id) {
            hash[index].pop_back();
        }
        hash[index].push_back({snap_id, val});
    }
    
    int snap() {
        int val = snap_id++;
        return val;
    }
    
    int getUtil(vector<pi>& v, int snap_id) {
        int minval = 0, maxval = v.size() - 1, medval;
        while(minval <= maxval) {
            medval = minval + (maxval - minval)/2;
            if(v[medval].first <= snap_id) minval = medval + 1;
            else maxval = medval - 1;
        }
        return v[maxval].second;
    }
    
    int get(int index, int snap_id) {
        return getUtil(hash[index], snap_id);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */