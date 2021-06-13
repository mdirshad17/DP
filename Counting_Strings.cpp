#include <bits/stdc++.h>
using namespace std;
#define M    1000000007
#define hM   9999999900000001
#define      int long long int
#define      vi vector<int>
#define      vvi vector<vi>
#define      vpi vector<pair<int,int>>
#define      pii pair<int,int>
#define      pb push_back
#define      inf 1e18
#define      ff first
#define      ss  second
#define      deb(x) cout<<#x<<" "<<x<<endl;
#define      all(x) x.begin(),x.end()
#define      printVec(vec) {for(auto &x : vec) cout << x <<" "; cout << endl; }
const int maxn = 1e5;

//  int BIT[maxn];
// void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
// int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}


//Set and multiset priority_queue
// if (a[i]<=1e5) then look for nlogn
// constraints are very high try to brute force
// binary_search or (dp constraints)
// if sizeof of arr is more than m then there is always a //combination of elements divisible by m
// Graph dijdp+dummynodes+mst
// two pointers


// Conting Strings Codechef ulta + seedha lexico bada
int dp[maxn + 10][2][2];
int solve(int s, int n, string &p, int f, int g)
{
	if (s >= n)
	{
		return (f and g);
	}
	if (dp[s][f][g] != -1)
	{
		return (dp[s][f][g] % M);
	}
	int ans = 0;
	int val = ('z' - p[s]);
	// if (s < n - 1)
	// {
	if (f)
	{
		ans += (val) * solve(s + 1, n, p, f, 1);
		ans = ans % M;
		if (g == 1)
		{
			ans += solve(s + 1, n, p, f, 1);
			ans = ans % M;
		} else
		{
			ans += solve(s + 1, n, p, f, 0);
			ans = ans % M;
		}
		int t = (26 - (val + 1));
		ans = ans % M;
		t = max(t, 0LL);
		ans += t * solve(s + 1, n, p, f, 0);
		ans = ans % M;

	} else
	{
		ans += solve(s + 1, n, p, f, g);
		ans = ans % M;
		ans += val * solve(s + 1, n, p, 1, 1);
		ans = ans % M;
	}
	ans = ans % M;
	return  dp[s][f][g] = ans;
}
void runcases(int T)
{

	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		s[i] = s[i] + 32;
	}
	memset(dp, -1, sizeof(dp));
	int f = solve(0, n, s, 0, 0);
	cout << f << endl;



	//cout<<"Case #"<<T<<": ";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// freopen("inputf.txt", "r", stdin);
	// freopen("outputf.txt", "w", stdout);
#endif
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}

	return 0;
}
