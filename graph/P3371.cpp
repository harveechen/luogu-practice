#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 0x7fffffff;
const int MAXV = 10000+1;

struct Edge {
    int dest, cost;
    Edge(int _d, int _c) : dest(_d), cost(_c) {}
    Edge() {}
};

vector<Edge> Adj[MAXV];
int d[MAXV];
bool vis[MAXV];
int n, m, s;

void dijkstra(int s) {
    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].dest;
            if (vis[v] == false && d[u] + Adj[u][j].cost < d[v]) {
                d[v] = d[u] + Adj[u][j].cost;
            }
        }

    }
}

int main() {
    int u, v, w;
    scanf("%d %d %d", &n, &m, &s);
    fill(d+1, d+n+1, INF);
    fill(vis+1, vis+n+1, false);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        Adj[u].push_back(Edge(v, w));
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        printf("%d", d[i]);
        if (i < n) printf(" ");
    }
}