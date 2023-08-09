#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>
#define vb vector<bool>
#define vvb vector<vb>
#define sz(a) a.size()
#define float double
#define pb push_back
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define per(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define endl "\n"
#define fastasfuck ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
	for (auto &x : a)
		cin >> x;
	return cin;
}
void update(int k, int val, vector<int>&bit) {
	while (k <= bit.size() - 1) {
		bit[k] += val;
		k += (k & (-k));
	}
}
int sum(int k, vector<int>&bit) {
	int res = 0;
	while (k > 0) {
		res += bit[k];
		k -= (k & (-k));
	}
	return res;
}
int query(int l, vector<int>&bit) {
	return sum(l, bit);
}

void soluchan()
{
	int n, q;
	cin >> n >> q;
	vi a(n + 1);
	vector<int>bit(n + 1, 0);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		update(i, a[i], bit);
		update(i + 1, -a[i], bit);
	}
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			update(l, x, bit);
			update(r + 1, -x, bit);
		}
		else if (type == 2) {
			int x;
			cin >> x;
			cout << query(x, bit) << endl;
		}
	}
}


int32_t main() {
#ifdef HUEHUEHUE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t = 1;
	// cin >> t;
	while (t--) {
		soluchan();
	}
	return 0;

}

