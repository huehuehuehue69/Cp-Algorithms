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

class node {
public:
	node* child[2];
	node() {
		child[0] = child[1] = nullptr;
	}
};
class Trie {
	node *root;
public:
	Trie() {
		root = NULL;
	}
	void insert(int num) {
		if (root == NULL) {
			root = new node();
		}
		node* curr = root;
		for (int i = 31; i >= 0; i--) {
			if (num & (1 << i)) {
				if (curr->child[1] == NULL) {
					curr->child[1] = new node();
				}
				curr = curr->child[1];
			}
			else {
				if (curr->child[0] == NULL) {
					curr->child[0] = new node();
				}
				curr = curr->child[0];
			}
		}
	}
	int minXor(int num) {
		int res = 0;
		node* curr = root;
		for (int i = 31; i >= 0; i--) {
			if (num & (1 << i)) {
				if (curr->child[1] != NULL) {
					curr = curr->child[1];
				}
				else if (curr->child[0] != NULL) {
					curr = curr->child[0];
					res |= (1 << i);
				}
				else {
					break;
				}
			}
			else {
				if (curr->child[0] != NULL) {
					curr = curr->child[0];
				}
				else if (curr->child[1] != NULL) {
					curr = curr->child[1];
					res |= (1 << i);
				}
				else {
					break;
				}
			}
		}
		return res;
	}
};

void soluchan()
{

	int n;
	cin >> n;
	vector<int>a(n);
	for (auto &x : a) {
		cin >> x;
	}
	Trie T;
	int res = INT_MIN;
	T.insert(a[0]);
	for (int i = 0; i < n; i++) {
		res = min(res, T.minXor(a[i]));
		T.insert(a[i]);
	}
	cout<<res<<endl;
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		soluchan();
	}
	return 0;
}