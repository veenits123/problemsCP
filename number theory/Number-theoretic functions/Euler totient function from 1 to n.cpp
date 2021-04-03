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
int phi[N];


//Euler totient function from 1 to n in O(nloglogn);
void etf() {

	REP(i, 1, N)
	phi[i] = i;

	REP(i, 2, N) {
		if (phi[i] == i) {
			for (int j = i; j <= N; j += i) {
				//method-I
				// phi[j] /= i;
				// phi[j] *= (i - 1);

				//method-II
				phi[j] -= phi[j] / i;
			}
		}
	}
}

/*
Divisor sum property:  ∑ϕ(d) = n;
Here the sum is over all positive divisors d of n.
For instance the divisors of 10 are 1, 2, 5 and 10.
                   Hence ϕ(1)+ϕ(2)+ϕ(5)+ϕ(10)=1+1+4+4=10.
*/

//Finding the totient from 1 to n using the divisor sum property;
vi phi_1_to_n(int n) {
	vi arr(n + 1);
	arr[0] = 0;
	arr[1] = 1;

	REP(i, 2, n)
	arr[i] = i - 1;

	REP(i, 2, n) {
		for (int j = 2 * i; j <= n; j += i) {
			arr[j] -= arr[i];
		}
	}
	return arr;
}

void solve() {

	int n; cin >> n;

	vi ans = phi_1_to_n(100);
	//cout<<ans[500];
	REP(i, 1, ans.size() - 1)
	cout << i << " " <<ans[i]<< endl;

	//cout << phi[n];

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

	etf();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}