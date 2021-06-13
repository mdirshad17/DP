#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
typedef pair<int, int> pii;

void solve(int T)
{

  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  std::vector<int> seq;
  seq.push_back(v[0]);
  for (int i = 1; i < n; i++)
  {
    if (seq.back() < v[i])
    {
      seq.push_back(v[i]);
    } else
    {
      int x = lower_bound(seq.begin(), seq.end(), v[i]) - seq.begin();

      seq[x] = v[i];
    }
  }
  // for (int x : seq)
  // {
  //   cout << x << " ";
  // } cout << endl;
  cout << seq.size() << endl;
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
