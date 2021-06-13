#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
typedef pair<int, int> pii;
int solve(int * a, int * b, int n, int w)
{
  if (n == 0 || w == 0)
  {
    return 0;
  }
  int d = 0;
  if (b[n - 1] <= w)
  {
    d = a[n - 1] + solve(a, b, n - 1, w - b[n - 1]);
  }
  return max(d, solve(a, b, n - 1, w));
}
void solve(int T)
{

  int n;
  cin >> n;
  int* arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int* brr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> brr[i];
  }
  int w;
  cin >> w;
  cout << solve(arr, brr, n, w) << endl;
  //
  //
  // delete[] arr;

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
