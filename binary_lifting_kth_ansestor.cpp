//using parent array
vector<vector<int>>dp;
void build(vector<int>&par, int x, int n) {
	for (int i = 0; i < n; i++) {
		dp[i][0] = par[i];
	}
	for (int j = 1; j <= x; j++) {
		for (int i = 0; i < n; i++) {
			if (dp[i][j - 1] == -1) {
				dp[i][j] = -1;
			}
			else {
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
			}
		}
	}
}

int find_kth(int node, int k) {
	int z = 0;
	while (k > 0) {
		if (k & 1) {
			node = dp[node][z];
		}
		z++;
		k >>= 1;
	}
	return node + 1;
}
void soluchan()
{
	int n, q;
	cin >> n >> q;
	vector<int>par(n);
	par[0] = -1;
	for (int i = 1; i < n; i++) {
		cin >> par[i];
		par[i]--;
	}
	int x = log2(n) + 1;
	dp.resize(n , vector<int>(x + 1, -1));
	build(par, x, n);
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--;
		cout << find_kth(a, b) << endl;
	}
}
