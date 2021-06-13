#include<bits/stdc++.h>
using namespace std;
int main()
{
	int  n;
	cin >> n;
	vector<vector<int> > v(2, vector<int>(n));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
	vector<vector<int> > times(2, vector<int>(n));
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> times[i][j];
		}
	}
	int et[2];
	int xt[2];
	for (int i = 0; i < 2; i++)
		cin >> et[i];
	for (int i = 0; i < 2; i++)
		cin >> xt[i];
	v[0][n - 1] += xt[0];
	v[1][n - 1] += xt[1];
	for (int i = n - 2; i >= 0; i--)
	{
		v[0][i] += min(v[1][i + 1] + times[0][i + 1], v[0][i + 1]);
		v[1][i] += min(v[0][i + 1] + times[1][i + 1], v[1][i + 1]);
	}
	int ans1 = v[0][0] + et[0];
	int ans2 = v[1][0] + et[1];
	cout << min(ans1, ans1) << endl;


}