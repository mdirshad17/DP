/*The array elements are in strictly increasing order
Print the longest subset such that adjacent elments are not coprime
ex:[2,3,4,6,9];
op=4;
[2,4,6,9];
ex=[1,2,3,4,5,6,7,8,9,10];
op=5;
[2,4,6,8,10];

*/


#include<bits/stdc++.h>
using namespace std;
#define N 100005
int main()
{
	int n;
	cin >> n;
	vector<int> v(n) ;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int dp[N];
	int d[N];
	memset(dp, 0, sizeof(dp));
	memset(d, 0, sizeof(d));
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		dp[v[i]] = 1;
		for (int j = 2; j * j <= v[i]; j++)
		{
			if ((v[i] % j) == 0)
			{
				dp[v[i]] = max(dp[v[i]], dp[d[j]] + 1);
				dp[v[i]] = max(dp[v[i]], dp[d[v[i] / j]] + 1);
				d[j] = v[i];
				d[v[i] / j] = v[i];
			}

		}
		ans = max(ans, dp[v[i]]);
		d[v[i]] = v[i];
	} cout << ans << endl;


}