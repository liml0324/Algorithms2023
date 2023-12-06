#include<bits/stdc++.h>
#define MAX 500
using namespace std;

int p[MAX+1] = {0};
int vis[MAX+1] = {0};

int Map[MAX+1][MAX+1] = {0};

bool dfs(int x, int m) {
    for(int y=1; y <= m; y++) {
        if(Map[x][y] && !vis[y]){
            vis[y] = 1;
            if(!p[y] || dfs(p[y], m)) {//如果x，y有好感，且y未被匹配/可以为y的对象找个新匹配，那么就匹配上
                p[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, e;
    cin >> n >> m >> e;
    for(int i=0; i < e; i++){
        int x, y;
        cin >> x >> y;
        Map[x][y] = 1;
    }
    auto cnt = 0;
    for(int x=1; x <= n; x++) {
        memset(vis, 0, sizeof(vis));//清空vis
        if(dfs(x, m))    cnt++;//每匹配上一次就加1
    }
    cout << cnt << endl;
    return 0;
}