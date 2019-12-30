#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int n = 30000;
int father[n+1];
int front[n+1];
int cnt[n+1];

int findFather(int x) {
    if (father[x] == x) return x;
    int pre = father[x];
    father[x] = findFather(father[x]);
    front[x] += front[pre];
    cnt[x] = cnt[father[x]];
    return father[x];
}

void merge(int u, int v) {
    int faU = findFather(u);
    int faV = findFather(v);
    father[faU] = faV;
    front[faU] += cnt[faV];
    cnt[faU] += cnt[faV];
    cnt[faV] = cnt[faU];
}

int check(int u, int v) {
    int faU = findFather(u);
    int faV = findFather(v);
    if (faU != faV) {
        return -1;
    } else {
        return abs(front[u] - front[v]) - 1;
    }
}

int main() {
    int M;
    int u, v;
    char cmd;
    for (int j = 1; j <= n; j++) {
        father[j] = j;
        front[j] = 0;
        cnt[j] = 1;
    }

    scanf("%d\n", &M);
    for (int i = 0; i < M; i++) {
        scanf("%c %d %d\n", &cmd, &u, &v);
        if (cmd == 'M') {
            merge(u, v);
        } else if (cmd == 'C') {
            printf("%d\n", check(u, v));
        }
    }
}