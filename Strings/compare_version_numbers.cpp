// problem link --> https://leetcode.com/problems/compare-version-numbers/

// my solution link --> https://leetcode.com/problems/compare-version-numbers/discuss/3977999/C%2B%2B-oror-0ms-oror-Short-and-SImple

class Solution {
public:
    int func(string a, string b) {
        // cout<<a<<" "<<b<<"\n";
        int val1 = 0, val2 = 0, idx = 0, m = a.size(), n = b.size();
        while(idx < m) val1 = (val1*10) + (a[idx++] - '0');
        idx = 0;
        while(idx < n) val2 = (val2*10) + (b[idx++] - '0');
        if(val1 > val2) return 1;
        else if(val1 < val2) return -1;
        return 0;
    }
    
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        int left = 0, right = 0;
        string temp1 = "", temp2 = "";
        while(left < m and right < n) {
            temp1.clear(), temp2.clear();
            while(left < m and version1[left] - '.') {
                temp1.push_back(version1[left++]);
            }
            while(right < n and version2[right] - '.') {
                temp2.push_back(version2[right++]);
            }
            int val = func(temp1, temp2);
            if(val) return val;
            left++, right++;
        }
        while(left < m) {
            temp1.clear();
            while(left < m and version1[left] - '.') {
                temp1.push_back(version1[left++]);
            }
            int val = func(temp1, "");
            if(val) return val;
            left++;
        }
        while(right < n) {
            temp2.clear();
            while(right < n and version2[right] - '.') {
                temp2.push_back(version2[right++]);
            }
            // cout<<"sas "<<temp2;
            int val = func("", temp2);
            if(val) return val;
            right++;
        }
        return 0;
    }
};