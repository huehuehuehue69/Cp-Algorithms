vector<vector<int>> adj;
vector<vector<int>> dp;
vector<int> depth;

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
int find_kth(int s, int k, int x) {
	for (int j = x; j >= 0; j--) {
		if ((1 << j) & k) {
			s = dp[s][j];
			k -= (1 << j);
			if (s == -1) {
				return -1;
			}
		}
	}
	return s + 1;
}
void dfs(int u, int p, int d, vector<int>&depth) {
	depth[u] = d;
	for (auto x : adj[u]) {
		if (x != p) {
			dfs(x, p, d + 1, depth);
		}
	}
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
	adj.resize(n);
	for (int i = 1; i < n; i++) {
		adj[par[i]].push_back(i);
	}
	// debug(adj);
	// debug(par);
	int x = log2(n) + 1;
	dp.resize(n , vector<int>(x + 1, -1));
	build(par, x, n);
	// debug(dp);
	vector<int>depth(n, 0);
	dfs(0, -1, 0, depth);
	// debug(depth);
	vector<int>res;
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		debug(depth[a]);
		debug(depth[b]);
		if (depth[a] < depth[b]) {
			swap(a, b);
		}
		for (int i = x; i >= 0; i--) {
			if ((depth[a] - pow(2, i)) >= depth[b]) {
				a = dp[a][i];
			}
		}
		if (a == b) {
			res.push_back(a);
			continue;
		}
		for (int j = x; j >= 0; j--) {
			if (dp[a][j] != dp[b][j]) {
				a = dp[a][j];
				b = dp[b][j];
			}
		}
		res.push_back(dp[a][0]);
	}
	for (auto x : res) {
		cout << x + 1 << endl;
	}
}
