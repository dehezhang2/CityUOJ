struct Edge { 
	int tar, cost; 
	Edge(int a, int b) :tar(a), cost(b) {}
};
struct Node { 
	int id, dist;
	Node(int a,int b):id(a),dist(b){}
	bool operator<(const Node& o)const {
		return dist > o.dist;
	}
	bool operator>(const Node& o)const {
		return !operator<(o);
	}
};
int n, t;
vector<Edge> G[MAX];
int dis[MAX];
bool rec[MAX];
void dijkstra() {
	priority_queue<Node> q;
	memset(rec, 0, sizeof(rec));
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	dis[n] = 0;
	q.push(Node(n, 0));
	while (!q.empty()) {
		int nd = q.top().id, dist = q.top().dist; q.pop();
		rec[nd] = 1;
		if (nd == 1)return;
		for (int i = 0; i < G[nd].size(); i++) {
			Edge& e = G[nd][i];
			if (!rec[e.tar]&&dis[e.tar] > dist + e.cost) {
				dis[e.tar] = dis[nd] + e.cost;
				q.push(Node(e.tar, dis[e.tar]));
			}
		}
	}
}
