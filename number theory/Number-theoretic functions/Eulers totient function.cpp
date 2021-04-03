#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;

/*
1} If p is a prime number, then gcd(p,q)=1 for all 1≤q<p. 
									Therefore we have: ϕ(p)=p−1;

2} If p is a prime number and k≥1, then there are exactly p^k/p numbers
			 between 1 and p^k that are divisible by p. 
			 Which gives us:  ϕ(p^k)=p^k−p^(k−1);

3} If a and b are relatively prime (co-prime), then:	ϕ(a*b)=ϕ(a)*ϕ(b);
*/

//formula :
// ϕ(n) = n*(1−1/p1)*(1−1/p2)*...*(1−1/pk);

int etf(int n) {
	int cnt = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			//method-I
			// cnt /= i;
			// cnt *= (i - 1);

			//method-II
			cnt -= cnt / i;//n(p-1)/p;n
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1) {
		//method-I
		// cnt /= n;
		// cnt *= (n - 1);

		//method-II
		cnt -= cnt / n;//n(p-1)/p;
	}
	return cnt;
}

void solve() {

	int n; cin >> n;
	cout << "ETF : " << etf(n) << endl;

	return ;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}