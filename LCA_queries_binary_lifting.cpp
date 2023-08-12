const int MAX = 200005;
int dp[MAX][21];
vector<int>adj[MAX];
int depth[MAX];
int par[MAX];
void build(int x, int n) {
	for (int i = 0; i < n; i++) {
		dp[i][0] = par[i];
	}
	for (int j = 1; j <= x; j++) {
		for (int i = 0; i < n; i++) {
			if (dp[i][j - 1] != -1) {
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
			}
		}
	}
}
void dfs(int u, int p, int d) {
	depth[u] = d;
	for (auto x : adj[u]) {
		if (x != p) {
			par[x] = u;
			dfs(x, u, d + 1);
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
	return node;
}
int lca(int a, int b, int x) {
	if (depth[a] > depth[b]) {
		swap(a, b);
	}
	int diff = depth[b] - depth[a];
	b = find_kth(b, diff);
	if (a == b) {
		return a;
	}
	for (int j = x; j >= 0; j--) {
		if (dp[a][j] != dp[b][j]) {
			a = dp[a][j];
			b = dp[b][j];
		}
	}
	return dp[a][0];
}

void soluchan()
{
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(par, -1, sizeof(par));
	memset(depth, 0, sizeof(depth));
	dfs(0, -1, 0);
	int x = log2(n) + 1;
	build(x, n);
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		//lca
		int w = lca(a, b, x);
		//distance between two nodes
		int res = depth[a] + depth[b] - (2 * depth[w]);
		cout << res << endl;
	}
}
