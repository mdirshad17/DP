#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n, m;
	cin >> n >> m;
	vector < vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x = 0;
			if ((i - 1) >= 0)
			{
				x = max(x, v[i - 1][j]);
			}
			if ((j - 1) >= 0)
			{
				x = max(x, v[i][j - 1]);
			}
			v[i][j] += x;
		}
	}
	cout << v[n - 1][m - 1] << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i][j] << " ";
		} cout << endl;
	}

}