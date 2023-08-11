int vis[10001];
vector<int>adj[10001];
int depth[10001];
int res[10001];
void dfs(int u, int p) {
	vis[u] = 1;
	int m1 = -1, m2 = -1;
	for (auto x : adj[u]) {
		if (x != p) {
			dfs(x, u);
			if (depth[x] >= m1) {
				m2 = m1;
				m1 = depth[x];
			}
			else if (depth[x] > m2) {
				m2 = depth[x];
			}
		}
	}
	depth[u] = m1 + 1;
	res[u] = m1 + m2 + 2;
}
void soluchan()
{
	int n;
	cin >> n;
	for (int i = 0 ; i < n - 1 ; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(vis, 0, sizeof(vis));
	memset(depth, 0, sizeof(depth));
	memset(res, 0, sizeof(res));
	dfs(1, -1);
	int mx = INT_MIN;
	for(int i = 0; i < n + 1; i++){
		mx = max(mx, res[i]);
	}
	cout << mx << endl;

}
