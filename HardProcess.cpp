#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vpi vector<pair<int,int>>
#define pii pair<int,int>
#define pb push_back
#define inf 1e18
#define ff first
#define ss  second
#define deb(x) cout<<#x<<" "<<x<<endl;
#define all(x) x.begin(),x.end()
#define endl "\n"
const int maxn = 1e5;
void runcases(int T)
{

	int n, k;
	cin >> n >> k;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int j = 0;
	int sum = 0;
	int maxans = 0;
	pii range;
	for (int i = 0; i < n; i++)
	{
		sum += (v[i] == 0) ? 1 : 0;
		while (sum > k)
		{
			sum += (v[j] == 0) ? -1 : 0;
			j++;
		}
		int l = (i - j + 1);
		// maxans = max(maxans, l);
		if (maxans < l)
		{
			maxans = l;
			range.ff = j;
			range.ss = i;
		}
	}
	cout << maxans << endl;

	for (int i = range.ff; i <= range.ss && maxans ; i++)
	{
		v[i] = 1;
	}
	for (int x : v)
	{
		cout << x << " ";
	}



	//cout<<"Case #"<<T<<": ";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}

	return 0;
}
