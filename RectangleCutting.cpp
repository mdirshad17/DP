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

  int a, b;
  cin >> a >> b;
  int dp[a + 1][b + 1];
  dp[0][0] = 0;
  int n = a, m = b;
  for (int i = 1; i <= n; i++)
  {
    dp[i][1] = i - 1;
  }
  for (int i = 1; i <= m; i++)
  {
    dp[1][i] = i - 1;
  }
  // for (int i = 0; i <= n; i++)
  //   dp[i][i] = 0;

  for (int i = 2; i <= n; i++)
  {
    for (int j = 2; j <= m; j++)
    {
      if (i == j)
      {
        dp[i][j] = 0;
      } else
      {
        int l = INT_MAX;
        for (int k = 1; k <= i / 2; k++)
        {
          l = min(l, dp[k][j] + dp[i - k][j]);
        }
        for (int k = 1; k <= (j / 2); k++)
        {
          l = min(l, dp[i][k] + dp[i][j - k]);
        }
        l = l + 1;
        dp[i][j] = l;

      }
    }
  }
  cout << dp[a][b] << endl;



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

