#include <bits/stdc++.h>
using namespace std;
#define ll long long
int Supersequence(string x,int n,string y,int m)
{
  if(n==0||m==0)
  {
    return abs(n-m);
  }
  if(x[n-1]==y[m-1])
  {
    return 1+Supersequence(x,n-1,y,m-1);
  }
  return 1+min(Supersequence(x,n-1,y,m),Supersequence(x,n,y,m-1));
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("error.out", "w", stderr);
    freopen("outputf.out", "w", stdout);
#endif
string x,y;
cin>>x>>y;
int n=x.size();
int m=y.size();
cout<<Supersequence(x,n,y,m);
cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}
