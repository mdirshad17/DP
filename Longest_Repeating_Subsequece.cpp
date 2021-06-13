//  print the longest repeating subsequence that is repeating such that non two characters of the repeating string should overlap
// same to LCS but a variation take the LCS with string itself dp[i][j]=(s[i]==s[j]  && i!=j)?1+dp[i+1][j+1]:max(dp[i+1][j],dp[i][j+1])
//

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

	string s;
	cin >> s;
	int n = s.size();
	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{

			dp[i][j] = (s[i] == s[j]  && i != j) ? 1 + dp[i + 1][j + 1] : max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << dp[i][j] << " ";
		} cout << endl;
	}
	cout << dp[0][0] << endl;



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
