#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int solve(int * a,int n,int sum,int presum,int x)
{  if(sum-presum==x)
  {
    return 1;
  }
  if(n==0)
  {
    return 0;
  }
  return solve(a,n-1,sum-a[n-1],presum+a[n-1],x)+solve(a,n-1,sum,presum,x);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("error.out", "w", stderr);
    freopen("outputf.out", "w", stdout);
#endif
int n,x;
cin>>n>>x;
int a[n];
int sum=0;
for(int i=0;i<n;i++)
{
  cin>>a[i];
  sum+=a[i];
}
cout<<solve(a,n,sum,0,x);





cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

}
