// problem link --> https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1

#define ll long long int
class Solution {
	public:
		int CountWays(string str){
		    int n = str.size(), val = 1e9 + 7;
		    vector<ll> dp(3);
		    if(str[0] == '0') return 0;
		    dp[0] = 1;
		    for(int i=1;i<n;i++) {
		        if(str[i] - '0') {
		            dp[i%3] = dp[(i-1)%3];
		            int num = (str[i-1] - '0')*10 + (str[i] - '0');
		            if(num <= 26 and num > 10) {
		                int temp = (i - 2 >= 0) ? dp[(i-2)%3] : 1;
		                dp[i%3] = (dp[i%3]%val + temp%val)%val;
		            }
		        }
		        else {
		            if(str[i-1] == '0' or str[i-1] > '2') return 0;
		            dp[i%3] = (i - 2 >= 0) ? dp[(i-2)%3] : 1;
		        }
		    }
		    return (int)(dp[(n-1)%3]%val);
		}

};