#include <iostream>

using namespace std;

#define int long long int
#define endl '\n'

const int N = 3e5 + 5;
int a[N];
int tree[4 * N];
int mx[4 * N];

const int MAX = 1e6 + 5;

int factor[MAX] = { 0 };

// function to generate all prime factors
// of numbers from 1 to 10^6
void generatePrimeFactors()
{
	factor[1] = 1;

	// Initializes all the positions with their value.
	for (int i = 2; i < MAX; i++)
		factor[i] = i;

	// Initializes all multiples of 2 with 2
	for (int i = 4; i < MAX; i += 2)
		factor[i] = 2;

	// A modified version of Sieve of Eratosthenes to
	// store the smallest prime factor that divides
	// every number.
	for (int i = 3; i * i < MAX; i++) {
		// check if it has no prime factor.
		if (factor[i] == i) {
			// Initializes of j starting from i*i
			for (int j = i * i; j < MAX; j += i) {
				// if it has no prime factor before, then
				// stores the smallest prime divisor
				if (factor[j] == j)
					factor[j] = i;
			}
		}
	}
}

// function to calculate number of factors
int calculateNoOFactors(int n)
{
	if (n == 1)
		return 1;

	int ans = 1;

	// stores the smallest prime number
	// that divides n
	int dup = factor[n];

	// stores the count of number of times
	// a prime number divides n.
	int c = 1;

	// reduces to the next number after prime
	// factorization of n
	int j = n / factor[n];

	// false when prime factorization is done
	while (j != 1) {
		// if the same prime number is dividing n,
		// then we increase the count
		if (factor[j] == dup)
			c += 1;

		/* if its a new prime factor that is factorizing n,
		   then we again set c=1 and change dup to the new
		   prime factor, and apply the formula explained
		   above. */
		else {
			dup = factor[j];
			ans = ans * (c + 1);
			c = 1;
		}

		// prime factorizes a number
		j = j / factor[j];
	}

	// for the last prime factor
	ans = ans * (c + 1);

	return ans;
}

void push_up(int pos) {
	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	mx[pos] = max(mx[2 * pos], mx[2 * pos + 1]);
}

void build(int st, int end, int pos) {
	if (st > end) return ;
	if (st == end) {
		tree[pos] = a[st];
		mx[pos] = a[st];
		return ;
	}
	int mid = (st + end) / 2;
	build(st, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);
	push_up(pos);
	return ;
}

void update(int l, int r, int st, int end, int pos) {
	if (mx[pos] <= 2) return ;
	if (st > end || l > end || st > r) return ;
	if (st == end) {
		tree[pos] = calculateNoOFactors(tree[pos]);
		mx[pos] = tree[pos];
		return ;
	}
	int mid = (st + end) / 2;
	update(l, r, st, mid, 2 * pos);
	update(l, r, mid + 1, end, 2 * pos + 1);
	push_up(pos);
	return ;
}

int query(int l, int r, int st, int end, int pos) {
	if (st > end || l > end || st > r) return 0;
	if (st >= l && r >= end) return tree[pos];
	int mid = (st + end) / 2;
	return query(l, r, st, mid, 2 * pos) +
	       query(l, r, mid + 1, end, 2 * pos + 1);
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	//int t;cin>>t;while(t--){}

	generatePrimeFactors();

	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, n, 1);
	while (q--) {
		int type, l, r; cin >> type >> l >> r;
		if (type == 1) {
			update(l, r, 1, n, 1);
		}
		else {
			cout << query(l, r, 1, n, 1) << endl;
		}
	}


	return 0;
}