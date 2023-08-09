#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>
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
void _print(bool x) {cerr << (x ? "true" : "false");}

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
template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
	for (auto &x : a)
		cin >> x;
	return cin;
}

/*
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefullv ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph
7. For too high constraints, apply binary search or bit manipulation or precompute or advance dataStructure.
*/


void soluchan()
{
	string s, p;
	cin >> s >> p;
	int m = s.size();
	int n = p.size();
	vector<int>lps(n);
	lps[0] = 0;
	for (int i = 1; i < n; i++) {
		int j = lps[i - 1];
		while (j > 0 and p[i] != p[j]) {
			j = lps[j - 1];
		}
		if (p[i] == p[j]) {
			j++;
		}
		lps[i] = j;
	}
	vector<int>res;
	int i = 0;
	int j = 0;
	while (i < m) {
		if (s[i] == p[j]) {
			i++;
			j++;
			if (j == n) {
				res.push_back(i - j + 1);
			}
		}
		else if (i < m && s[i] != p[j]) {
			if (j > 0) {
				j = lps[j - 1];
			}
			else {
				i++;
			}
		}
	}
	if (res.size() == 0) {
		cout << "Not Found" << endl;
		return;
	}
	cout << res.size() << endl;
	for (auto &x : res) {
		cout << x << " ";
	}
	cout << endl;
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		soluchan();
	}
	return 0;
}