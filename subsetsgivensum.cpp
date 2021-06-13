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
int solve(int s, int n, vi & v, int sum)
{
  if (s >= n)
  {
    return sum == 0;
  }
  if (sum < 0)
  {
    return 0;
  }
  int ans1 = solve(s + 1, n, v, sum);
  int ans2 = solve(s , n, v, sum - v[s]);
  return (ans1 + ans2);

}
void runcases(int T)
{

  int n;
  cin >> n;
  vi v(n);
  int sum;
  cin >> sum;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int f = solve(0, n, v, sum);
  cout << f << endl;

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
