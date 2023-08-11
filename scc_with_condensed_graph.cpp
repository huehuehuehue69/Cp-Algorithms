vector<int>adj[100001];
vector<int>adjT[100001];
stack<int>s;
vector<int>components;
vector<vector<int>>ssc;
vector<bool>vis;
//topo sort
void dfs(int u) {
	vis[u] = true;
	for (auto x : adj[u]) {
		if (!vis[x]) {
			dfs(x);
		}
	}
	s.push(u);
}
//to find sink node
stack<int>s1;
void dfs2(int u, vector<int>adj[]) {
	vis[u] = true;
	for (auto x : adj[u]) {
		if (!vis[x]) {
			dfs2(x, adj);
		}
	}
	s1.push(u);
}
//to find the components of scc
vector<int>code;
int id;
void dfs1(int u) {
	vis[u] = true;
	code[u] = id;
	for (auto x : adjT[u]) {
		if (!vis[x]) {
			dfs1(x);
		}
	}
	components.push_back(u);
}
void soluchan()
{

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
		adj[u].push_back(v);
		adjT[v].push_back(u);
	}
	vis.assign(n + 1, false);
	for (int i = 1; i < n + 1; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	vis.assign(n + 1, false);
	id = 0;
	code.resize(n + 1, 0);
	//storing components
	while (!s.empty()) {
		int t = s.top();
		s.pop();
		if (vis[t]) {
			continue;
		}
		components.clear();
		dfs1(t);
		sort(all(components));
		ssc.push_back(components);
		id++;
	}
	debug(ssc);
	//condensing the graph
	vector<int>newG[id];
	for (auto e : edges) {
		int u = code[e.ff];
		int v = code[e.ss];
		if (u != v) {
			newG[v].push_back(u);
		}
	}
	//find the sink node
	vis.assign(id, false);
	for (int i =  0; i < id; i++) {
		if (!vis[i]) {
			dfs2(i, newG);
		}
	}
	int t = s1.top();
	cout << ssc[t].size() << endl;
	for (auto x : ssc[t]) {
		cout << x << " ";
	}
	cout << endl;
}

