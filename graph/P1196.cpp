#include <cstdio>
#include <vector>

using namespace std;

const int n = 30000;
vector<vector<int>> G(n+1);
int father[n+1];

int findFather(int x) {
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }

    while(a != father[a] ) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void merge(int u, int v) {
    int faU = findFather(u);
    int faV = findFather(v);
    father[faU] = faV;
    G[faV].insert(G[faV].end(), G[faU].begin(), G[faU].end());
}

int check(int u, int v) {

    return -1;
}

int main() {
    int cnt;
    int u, v;
    char cmd;
    for (int j = 1; j <= n; j++) {
        father[j] = j;
        G[j].push_back(j);
    }

    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        scanf("%c %d %d", &cmd, &u, &v);
        if (cmd == 'M') {
            merge(u, v);
        } else if (cmd == 'C') {
            printf("%d\n", check(u, v));
        }
    }
}