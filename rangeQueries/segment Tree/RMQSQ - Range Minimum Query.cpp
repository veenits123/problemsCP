#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e5 + 7;
int a[N];
int tree[4 * N];

void build(int s, int e, int pos) {
  if (s > e) return;
  if (s == e) {
    tree[pos] = a[s];
    return;
  }
  int mid = (s + e) / 2;
  build(s, mid, 2 * pos);
  build(mid + 1, e, 2 * pos + 1);
  tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
  return ;
}

int query(int l, int r, int s, int e, int pos) {
  if (s > e || l > e || r < s) return INT_MAX;
  if (s >= l && r >= e) return tree[pos];
  int mid = (s + e) / 2;
  return min(query(l, r, s, mid, 2 * pos), query(l, r, mid + 1, e, 2 * pos + 1));
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
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, n - 1, 1);
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    cout << query(l, r, 0, n - 1, 1) << endl;
  }


  return 0;
}