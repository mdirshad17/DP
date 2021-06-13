#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
typedef pair<int, int> pii;


int fastExpo(int a, int n, int mod) {
	int result = 1;
	while ( n > 0) {
		if ( n & 1 )
			result = (result * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return result;
}

int modInverse(int n, int mod) {
	return fastExpo(n, mod - 2, mod);
}

vector<int> factorial(int n) {
	std::vector<int> fac(n + 2, 0);
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % M;

	return fac;
}

int __nCr(int n, int r, vector<int>& Fact, int mod) {
	int ans = (((Fact[n] * modInverse(Fact[r], mod)) % mod)
	           * modInverse(Fact[n - r], mod)) % mod;
	return ans;
}

void solve(int T)
{

	int n;
	cin >> n;
	vector<int> v(n);
	int x = 0;
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
		x = x + v[i];
	}

	if (x % 2 != 0)
	{
		cout << 0;
	} else
	{	x = x / 2;
		int flag = 1;
		int dp[2][x + 1];
		for (int i = 0; i <= x; i++)
		{
			dp[0][i] = 0;
		}
		for (int i = 0; i <= 1; i++)
		{
			dp[i][0] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= x; j++)
			{	dp[flag][j] = (dp[flag ^ 1][j]);
				if (v[i - 1] > j)
				{
					continue;
				} else
				{
					dp[flag][j] = (dp[flag][j] + dp[flag ^ 1][j - v[i - 1]]) % M;
					dp[flag][j] = (dp[flag][j] % M);
				}
			} flag = flag ^ 1;
		}
		int f = modInverse(2, M);
		cout << f << endl;
		dp[flag ^ 1][x] = (dp[flag ^ 1][x] % M * modInverse(2, M) % M) % M;


		cout << dp[flag ^ 1][x];
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
		solve(t);
	}

	return 0;
}