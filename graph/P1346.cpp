#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 100 + 10;
const int inf = 0x3fffffff;

int G[maxn][maxn];
int N, A, B;

int floyd(int u, int v) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    if (G[u][v] == inf) return -1;
    else return G[u][v];
}

int main() {
    scanf("%d %d %d", &N, &A, &B);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            G[i][j] = inf;
        }
        G[i][i] = 0;
    }

    int K, dest;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &K);
        for (int j = 0; j < K; j++) {
            scanf("%d", &dest);
            if (j == 0) G[i][dest] = 0;
            else G[i][dest] = 1;
        }
    }

    int cnt = floyd(A, B);
    printf("%d\n", cnt);
}