#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> G;
bool* vis;
int* vcolor;
int cnt[2];
int err = 0;

void color(int u, int flag) {
    vcolor[u] = flag;
    cnt[flag]++;
    vis[u] = true;
    for (auto v : G[u]) {
        if (vis[v] == false) {
            color(v, !flag);
        } else if (vcolor[v] == vcolor[u]) {
            err = 1;
            return;
        }
    }
}

int main() {
    int n, m;
    int u, v;
    int mcnt;
    scanf("%d %d", &n, &m);
    G = vector<vector<int>>(n+1);
    vis = new bool[n+1];
    vcolor = new int[n+1];
    fill(vis+1, vis+1+n, false);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int j = 1; j <= n; j++) {
        if (vis[j] == false) {
            cnt[0] = 0; cnt[1] = 0;
            color(j, 0);
            if (cnt[0] > 0 && cnt[1] > 0) {
                mcnt = min(cnt[0], cnt[1]);
                ans += mcnt;
            }
        }
    }
    if (err) printf("Impossible\n");
    else printf("%d", ans);
}