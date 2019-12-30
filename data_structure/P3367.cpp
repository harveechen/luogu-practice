#include<cstdio>

using namespace std;

const int maxN = 10000;
int father[maxN+1];

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

int main() {
    int N, M;
    int op, x, y;
    int i, faX, faY;
    char flag;
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) {
        father[i] = i;
    }
    for (i = 0; i < M; i++) {
        scanf("%d %d %d", &op, &x, &y);
        faX = findFather(x);
        faY = findFather(y);
        if (op == 1) {
            father[faX] = faY; 
        } else if (op == 2) {
            flag = faX == faY ? 'Y' : 'N';
            printf("%c\n", flag);
        }
    }
}