//不能處裡含有"負邊"的圖
#define pii pair<int, int>
//#define int long long
#define MAX INT_MAX //LLONG_MAX
vector<vector<pii>> graph;
vector<int> dist;
vector<int> parent;
void init(int n) {
	graph = vector<vector<pii>>(n+1);
	dist = vector<int>(n+1, MAX);
	parent = vector<int>(n+1, -1);
	return;
}

void dijkstra(int from/*, int target*/) {
	dist[from] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pque;
	pque.push({0, from});
	while (!pque.empty()) {
		int node = pque.top().second;
		int pdist = pque.top().first;
		pque.pop();
		// if (node == target) break;
		if (pdist != dist[node]) continue;
		for (auto &[to, edist] : graph[node]) {
			if (pdist + edist < dist[to]) {
				dist[to] = pdist + edist;
				pque.push({dist[to], to});
				parent[to] = node;
			}
		}
	}
	return;
}