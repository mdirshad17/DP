#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int getMax(vector<int> v, int i, int j)
{
	if (i > j) {
		// dp[i][j] = 0;
		return 0;
	}
	if (dp[i][j] != -1)
		return dp[i][j];
	int ans1 = v[i] + min(getMax(v, i + 2, j) , getMax(v, i + 1, j - 1));
	int ans2 = v[j] + min(getMax(v, i + 1, j - 1), getMax(v, i, j - 2));
	return dp[i][j] = max(ans2, ans1);
}
int main()
{

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	} memset(dp, -1, sizeof(dp));
	cout << getMax(v, 0, n - 1) << endl;
}