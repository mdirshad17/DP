#include <bits/stdc++.h>
using namespace std;
#define      M    1000000007
#define      hM   9999999900000001
#define      int long long int
#define      vi vector<int>
#define      vvi vector<vi>
#define      vpi vector<pair<int,int>>
#define      pii pair<int,int>
#define      pb push_back
#define      inf 1e18
#define      ff first
#define      ss  second
#define      line  "\n"
#define      deb(x) cout<<#x<<" "<<x<<endl;
#define      all(x) x.begin(),x.end()
#define      printVec(vec) {for(auto &x : vec) cout << x <<" "; cout << endl; }
const int N = 1e5 + 10;

//int BIT[N];
//void add(int x, int val) {while (x < N)BIT[x] += val, x += x & -x;}
//int sum(int x) {return x ? BIT[x] + sum(x - (x & -x)) : 0;}


void runcases(int T)
{

  string s, p;
  cin >> s >> p;
  int n = s.size();
  int m = p.size();
  int dp[n + 1][m + 1];
  for (int i = 0; i <= n; i++)
  {
    dp[i][0] = i;
  }
  for (int i = 0; i <= m; i++)
  {
    dp[0][i] = i;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == p[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1];
      } else
      {
        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
      }
    }
  }
  cout << dp[n][m] << endl;



  //cout << "Case #" << T << ": ";
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

