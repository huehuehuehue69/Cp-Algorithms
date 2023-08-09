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

vector<int>bit;
void update(int k, int val, int n) {
	while (k <= n) {
		bit[k] += val;
		k += (k & (-k));
	}
}
int sum(int k) {
	int res = 0;
	while (k > 0) {
		res += bit[k];
		k -= (k & (-k));
	}
	return res;
}
int query(int idx, int val) {
	int noOfUpdates = sum(idx);
	while (noOfUpdates) {
		int res = 0;
		while (val) {
			res += val % 10;
			val /= 10;
		}
		val = res;
		if (val < 10) {
			break;
		}
		noOfUpdates--;
	}
	return val;
}

void soluchan()
{
	int n, q;
	cin >> n >> q;
	vi a(n + 1);
	bit.resize(n + 10, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int l, r;
			cin >> l >> r;
			update(l, 1, n);
			update(r + 1, -1, n);
			debug(bit);
		}
		else {
			int pos;
			cin >> pos;
			cout << query(pos, a[pos]) << endl;
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
	cin >> t;
	while (t--) {
		soluchan();
	}
	return 0;
}

