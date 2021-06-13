#include<bits/stdc++.h>
using namespace std;
int main()
{
	int  n;
	cin >> n;
	vector<int> v(n + 1, INT_MAX);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	int minans = INT_MAX;
	int minidx = -1;
	for (int i = n; i >= 1; i--)
	{
		int sc = ((i + v[i]) <= n ? v[i + v[i]] : 1);
		v[i] = v[i] * sc;

	}
	for (int i = 1; i <= n; i++)
	{
		// cout << v[i] << " ";
		if (minans > v[i])
		{

			// cout << v[i] << " " << minans << endl;
			minans = v[i];
			minidx = i;
		}
	}
	// cout << endl;

	cout << (minidx - 1) << " " << minans << endl;

}