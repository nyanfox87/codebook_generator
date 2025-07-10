const int N = 100005;
vector<vector<int>> graph(N+1);
vector<bool> been(N+1, 0);
vector<bool> onStack(N+1, 0);
vector<int> cycle;
vector<int> topo;
bool dfs(int ind) {
	been[ind] = onStack[ind] = 1;
	for (auto &i : graph[ind]) {
		if (been[i] == 0) {
			if (onStack[i]) {
				cycle.pb(i);
				return true;
			}
			if (dfs(i)) return true;
		}
		else if (onStack[i]) {
			been[ind] = 0;
			cycle.pb(i);
			return dfs(i);
		}
	}
	topo.pb(ind);
	onStack[ind] = 0;
	return 0;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[a].pb(b);
	}
	bool ch = 0;
	for (int i = 1; i <= n; i++) {
		if (been[i] == 0) {
			if (dfs(i)) {
				ch = 1;
				break;
			}
		}
	}
	if (ch) {
		cout << "cycle found: " << endl;
		for (auto &i : cycle) cout << i << " ";
		cout << cycle.front();
	}
	reverse(topo.begin(), topo.end());
	for (auto &i : topo) cout << i << " ";
	return;
}