// problem link --> https://practice.geeksforgeeks.org/problems/230d87552a332a2970b2092451334a007f2b0eec/1

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        //code here
        int one, two;
        one = min(a, b), two = max(a, b);
        a = one, b = two;
        one = min(c, d), two = max(c, d);
        c = one, d = two;
        if(a <= c and b <= d) return 0;
        if(b > d) return 1 + carpetBox(a, (b>>1), c, d);
        return 1 + carpetBox((a>>1), b, c, d);
    }
};
