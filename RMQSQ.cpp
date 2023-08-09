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
const int N = 200004;
const int K = 25;
int table[N][K + 1];
void preCompute(int n, vi &a) {
	for (int i = 0; i < n; i++) {
		table[i][0] = a[i];
	}
	for (int j = 1; j <= K; j++) {
		for (int i = 0; i + (1LL << j) <= n; i++) {
			table[i][j] = min(table[i][j - 1], table[i + (1LL << (j - 1))][j - 1]);
		}
	}

}
int lg[N + 1];
void preLog() {
	lg[1] = 0;
	for (int i = 2; i <= N; i++) {
		lg[i] = lg[i / 2] + 1;
	}
}
void soluchan()
{
	int n, q;
	cin >> n;
	vi a(n);
	cin >> a;
	preCompute(n, a);
	cin >> q;
	for (int i = 0; i < q; i++) {
		int L, R;
		cin >> L >> R;
		int j = lg[ R - L + 1 ];
		int ans = min (table[L][j], table[R - (1LL << j) + 1][j]);
		cout << ans << endl;
	}
}

int32_t main() {
#ifdef HUEHUEHUE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t = 1;
	preLog();
	while (t--) {
		soluchan();
	}
	return 0;

}