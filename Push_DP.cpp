#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> L(K), R(K);
    rep(i, K) cin >> L[i] >> R[i];
    vector<ll> dp(N, 0), sdp(N, 0);
    dp[0] = 1;
    sdp[0] = dp[0];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            ll l, r;
            if (i - L[j] < 0)
                l = 0;
            else
                l = sdp[i - L[j]];
            if (i - R[j] - 1 < 0)
                r = 0;
            else
                r = sdp[i - R[j] - 1];
            dp[i] += l - r;
            dp[i] %= 998244353;
        }
        sdp[i] = sdp[i - 1] + dp[i];
    }
    cout << dp[N - 1] % 998244353 << endl;
}