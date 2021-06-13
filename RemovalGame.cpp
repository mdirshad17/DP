#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
typedef pair<int, int> pii;
int dp[5005][5005];
int solveit(vector<int> &v, int s, int n)
{
  if (s > n)
  {


    return 0;
  }
  if (dp[s][n] != -1)
  {
    return dp[s][n];
  }

  return dp[s][n] = max(v[s] + min(solveit(v, s + 2, n), solveit(v, s + 1, n - 1)), v[n] + min(solveit(v, s + 1, n - 1), solveit(v, s, n - 2)));


}
void solve(int T)
{

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  } memset(dp, -1, sizeof(dp));
  cout << solveit(v, 0, n - 1);



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