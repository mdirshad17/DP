// ctrl+alt+m 
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
const int maxn=1e5;
// int gcd(int a,int b)
// {
//   if(a==0)
//   {
//     return b;
//   }
//   return gcd(b,a%b);
// }
int dp[1010][1010];
int solve(int s,int n,vi & v,int g)
{
  if(s>=n)
  {
     return g==1;
  }
  if(dp[s][g]!=-1)
  {
    return dp[s][g];
  }
  int f=__gcd(g,v[s]);
  int ans1=solve(s+1,n,v,f);
  int ans2=solve(s+1,n,v,g);
  return  dp[s][g]=(ans1+ans2);
}
void runcases(int T)
{

  int n;
  cin>> n;
  vi v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  memset(dp,-1,sizeof(dp));
  int f=solve(0,n,v,0);
  cout<<f<<endl;
    

  //cout<<"Case #"<<T<<": ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int t=1;t<=T; t++) {
        runcases(t);
    }

    return 0;
}
