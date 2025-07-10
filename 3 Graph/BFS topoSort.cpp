void topo_sort() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n+1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	vector<int> rudu(n+1, 0);
	for (auto &node : graph) {
		for (auto &now : node) {
			rudu[now]++;
		}
	}
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (rudu[i] == 0) que.push(i);
	}
	vector<int> topo;
	while (!que.empty()) {
		int top = que.front();
		que.pop();
		topo.push_back(top);
		for (auto &i : graph[top]) {
			rudu[i]--;
			if (rudu[i] == 0) que.push(i);
		}
	}
	if (topo.size() == n) {
		for (auto &i : topo) cout << i << " ";
	}
	else
		cout << "IMPOSSIBLE";
}