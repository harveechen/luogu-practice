#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 200000 + 1;

int parent[MAXN];
bool inStack[MAXN];
int low[MAXN];
int dfh[MAXN];
stack<int> st;
int ans = 0x3fffffff;

void scc(int u) {
    static int time = 0;
    dfh[u] = low[u] = ++time;
    st.push(u);
    inStack[u] = true;

    int v = parent[u];
    if (dfh[v] == -1) {
        scc(v);
        low[u] = min(low[u], low[v]);
    } else if (inStack[v] == true) {
        low[u] = min(low[u], dfh[v]);
    }

    int w = 0;
    int cnt = 0;
    if (low[u] == dfh[u]) {
        while(st.top() != u) {
            w = st.top();
            cnt++;
            inStack[w] = false;
            st.pop();
        }
        w = st.top();
        cnt++;
        inStack[w] = false;
        st.pop();
    }
    if (cnt > 1) {
        ans = min(ans, cnt);
    }     
}

inline int read() {
    int N = 0;
    char ch;
    ch = getchar();
    while (ch >= '0' && ch <= '9') {
        N = N*10 + ch - '0';
        ch = getchar();
    }
    return N;
}

int main() {
    int n;
    n = read();
    fill(dfh+1, dfh+1+n, -1);
    fill(inStack+1, inStack+1+n, false);
    for (int i = 1; i <= n; i++) {
        //scanf("%d", parent+i);
        parent[i] = read();
    }

    for (int i = 1; i <= n; i++) {
        if (dfh[i] == -1) {
            scc(i);
        }
    }

    printf("%d", ans);
}
