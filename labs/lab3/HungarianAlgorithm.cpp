#include<bits/stdc++.h>
#define MAX 500
using namespace std;

int *p, *vis;
int n, m, e;
int Map[MAX+1][MAX+1] = {0};

bool dfs(int x, int n, int m) {
    for(int i = 1; i <= m; i++) {
        if(Map[x][i] && !vis[i]) {
            vis[i] = 1;
            if(!p[i] || dfs(p[i], n, m)) {
                p[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> e;
    p = (int *)calloc(m+1, sizeof(int));
    vis = new int[m+1];
    for(int i = 1; i <= e; i++) {
        int x, y;
        cin >> x >> y;
        Map[x][y] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(int)*(m+1));
        if(dfs(i, n, m)) ans++;
    }
    cout << ans << endl;
    return 0;
}