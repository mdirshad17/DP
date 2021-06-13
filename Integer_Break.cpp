// C/C++ program to find maximum product by breaking
// the Integer
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
// method return x^a in log(a) time
ll power(ll x, ll a)
{
	ll res = 1;
	while (a) {
		if (a & 1)
			res = (res * x) % M;
		x = (x * x) % M;
		a >>= 1;
	}
	return res % M;
}

// Method returns maximum product obtained by
// breaking N

ll breakInteger(ll N)
{

	if (N == 2)
		return 2;

	if (N == 3)
		return 3;

	int maxProduct;

	// breaking based on mod with 3
	switch (N % 3) {
	case 0:
		maxProduct = power(3, N / 3);
		maxProduct = maxProduct % M;
		break;

	// If division gives mod as 1, then break as
	// 4 + power of 3 for remaining part
	case 1:
		maxProduct = 2 * 2 * power(3, (N / 3) - 1);
		maxProduct = maxProduct % M;
		break;

	// If division gives mod as 2, then break as
	// 2 + power of 3 for remaining part
	case 2:
		maxProduct = 2 * power(3, N / 3);
		maxProduct = maxProduct % M;
		break;
	}
	return maxProduct;
}

// Driver code to test above methods
int main()
{
	ll n;
	cin >> n;
	ll maxProduct = breakInteger(n);
	cout << maxProduct << endl;
	return 0;
}
