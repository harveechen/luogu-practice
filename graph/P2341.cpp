#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MaxV = 10000+10;

int N, M;
vector<vector<int>> G;

int dfh[MaxV];
int low[MaxV];
bool ins[MaxV];
stack<int> st;
int vid[MaxV];
int cnt[MaxV];
int groupid = 0;
int outCnt[MaxV];

void tarjon(int u) {
    static int time = 0;
    dfh[u] = low[u] = ++time;
    st.push(u);
    ins[u] = true;

    for (auto v : G[u]) {
        if (dfh[v] == -1) {
            tarjon(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v] == true) {
            low[u] = min(low[u], dfh[v]);
        }
    }

    if (low[u] == dfh[u]) {
        groupid++;
        int w = 0;
        do {
            w = st.top();
            ins[w] = false;
            st.pop();
            vid[w] = groupid;
            cnt[groupid]++;
        }  while(w != u);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    G = vector<vector<int>>(N+1);
    fill(dfh+1, dfh+1+N, -1);
    fill(ins+1, ins+1+N, false);
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
    }
    for (int j = 1; j <= N; j++) {
        if (dfh[j] == -1) {
             tarjon(j);
        }   
    }

    for (int u = 1; u <= N; u++) {
        for (auto v : G[u]) {
            if (vid[v] != vid[u]) {
                outCnt[vid[u]]++;
            }
        }
    }

    int id = 0;
    for (int idx = 1; idx <= groupid; idx++) {
        if (!outCnt[idx]) {
            if (id) {
                printf("0\n");
                return 0;
            }
            id = idx;
        }
    }
    printf("%d", cnt[id]);
}