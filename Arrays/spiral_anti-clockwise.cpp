// problem --> get the last alternate element while traversing the matrix spirally, anti-clockwise.

#include <bits/stdc++.h>
using namespace std;

int res = 0, count1 = 0;
void counterClockspiralPrint(int m,int n, vector<vector<int>>& arr)
{
	int i, k = 0, l = 0;
	int cnt = 0;
	int total = m * n;

	while (k < m && l < n)
	{
		if (cnt == total)
			break;
		for (i = k; i < m; ++i)
		{
			cout << arr[i][l] << " ";
			cnt++;
		    count1++;
		    if(count1&1) res= arr[i][l];
			
		}
		l++;

		if (cnt == total)
			break;
		for (i = l; i < n; ++i)
		{
			cout << arr[m - 1][i] << " ";
			cnt++;
			count1++;
		    if(count1&1) res= arr[m-1][i];
		}
		m--;

		if (cnt == total)
			break;
		if (k < m)
		{
			for (i = m - 1; i >= k; --i)
			{
				cout << arr[i][n - 1] << " ";
				cnt++;
				count1++;
		        if(count1&1) res= arr[i][n-1];
			}
			n--;
		}

		if (cnt == total)
			break;
		if (l < n)
		{
			for (i = n - 1; i >= l; --i)
			{
				cout << arr[k][i] << " ";
				cnt++;
				count1++;
		        if(count1&1) res= arr[k][i];
			}
			k++;
		}
	}
}

int main()
{
	vector<vector<int>> v = {{ 1, 2, 3, 4 },
					        { 5, 6, 7, 8 },
					        { 9, 10, 11, 12 },
					        { 13, 14, 15, 16 }};
    int m = v.size(), n = v[0].size();
	counterClockspiralPrint(m, n, v);
	cout<<"\n";
	cout<<res<<"\n";
	return 0;
}
