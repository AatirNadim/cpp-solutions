// problem link --> https://practice.geeksforgeeks.org/problems/45fa306a9116332ece4cecdaedf50f140bd252d4/1

class Solution{
public:
    int maxInstance(string s){
        vector<int> hash(26);
        // int res = s.size();
        for(char c : s) hash[c - 'a']++;
        // s = "balloon";
        int res = hash[0];
        res = min(res, hash[1]);
        res = min(res, hash['l' - 'a']/2);
        res = min(res, hash['o' - 'a']/2);
        res = min(res, hash['n' - 'a']);
        return res;
    }
};