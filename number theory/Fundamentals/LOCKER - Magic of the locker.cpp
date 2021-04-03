#include <iostream>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int mod = 1e9 + 7;

int mod_exp(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = (res * a) % mod;
			n--;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}

//x^(n/x) is largest when x = 3 (n and x being integers);
//function: y = x^(n/x);
//the function will have its maximum value when dy/dx = 0;
//we found when dy/dx=0, x=e (maximum value of x);
//hence x = 3 (being nearest integer to e=2.718);
//Q.E.D.;
void solve() {
	int n; cin >> n;
	if (n == 1)
		cout << 1 % mod << endl;

	else if (n % 3 == 1) {//e.g. n=10, case1: 3*3*3*1=27 case2: 3*3*4=36;
		//(n-1) not making profit as multiplication of 3 & 1 = 3;
		//but (n-4) making profit of 4 instead of 3*1;
		cout << mod_exp(3, (n - 4) / 3) * 4 % mod << endl;
	}
	else if (n % 3 == 2) {//e.g. n=8, case1: 3*3*2=18 case2: 3*5=15;
		//(n-5) not making profit as giving 5;
		//but (n-2) making profit of 3*2=6 instead of 5;
		cout << mod_exp(3, (n - 2) / 3) * 2 % mod << endl;
	}
	else {//e.g. n=6, case1: 2+2+2=6 and 2*2*2=8 case2:3+3=6 and 3*3=9;
		//same sum but larger product that is the whole idea of this problem;
		cout << mod_exp(3, n / 3) % mod << endl;
	}

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}