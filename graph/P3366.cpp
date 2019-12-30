#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXV = 5000;
const int MAXE = 200000;
struct Edge {
    int u, v;
    int cost;
}E[MAXE];
int father[MAXV+1];
int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    // path compress
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

bool cmp(Edge e1, Edge e2) {
    return e1.cost < e2.cost;
}

void kruskal(int n, int m) {
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    sort(E, E+m, cmp);
    for (int i = 0; i < m; i++) {
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if (faU != faV) {
            father[faU] = faV;
            ans += E[i].cost;
            cnt++;
            if (cnt == n-1) break;
        }
    }
    if (cnt != n-1) printf("orz\n");
    else printf("%d\n", ans);
}


int main() {
    int N, M; // N nodes, M edges
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].cost);
    }
    kruskal(N, M);
}