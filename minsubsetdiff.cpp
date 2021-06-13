#include <bits/stdc++.h>
using namespace std;
int dp[100][1000];
int solve(int * a,int n,int sum,int presum)
{
  if(n==0)
  {    dp[n][presum]=INT_MAX;
      return INT_MAX;
  }
  if(dp[n][presum]!=-1)
  {
    return dp[n][presum];
  }
int res= min({abs(sum-presum),solve(a,n-1,sum-a[n-1],presum+a[n-1]),solve(a,n-1,sum,presum)});
dp[n][presum]=res;
return dp[n][presum];
}
int main(){
  #ifndef ONLINE_JUDGE
      freopen("inputf.in", "r", stdin);
      freopen("error.out", "w", stderr);
      freopen("outputf.out", "w", stdout);
  #endif
	int n;
  cin>>n;
  int a[n];
  int sum=0;
memset(dp,-1,sizeof(dp));
  for (int i = 0; i < n; i++)
  {
    cin>>a[i];
    sum+=a[i];
  }
  int presum=0;
  cout<<solve(a,n,sum,presum);
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;

}
