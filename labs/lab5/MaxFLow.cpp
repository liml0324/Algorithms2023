#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
long long m, n, s, t;
long long size;
bool bfs(vector<vector<long long>>& c, vector<long long>& depth) {// c是残余网络
    depth[s] = 0;
    queue<long long> q;
    q.push(s);
    while(!q.empty()) {
        long long u = q.front();
        q.pop();
        for(long long v = 1; v <= size; v++) {
            if(depth[v] == -1 && c[u][v] > 0) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
    return depth[t] != -1;
}
long long dfs(vector<vector<long long>>& c, vector<long long>& depth, long long u, long long flow) {// 维护残存网络即可
    if(u == t) return flow;
    long long res = 0;
    for(long long v = 1; v <= size; v++) {
        if(depth[v] == depth[u] + 1 && c[u][v] > 0) {
            long long f = dfs(c, depth, v, min(flow, c[u][v]));
            if(f > 0) {
                c[u][v] -= f;
                c[v][u] += f;
                res += f;
                flow -= f;
                if(flow == 0) break;
            }
        }
    }
    return res;
}
int main() {
    cin >> n >> m >> s >> t;
    size = n;
    vector<vector<long long>> c(MAX, vector<long long>(MAX, 0));
    for(long long i = 0; i < m; i++) {
        long long u, v, cap;
        cin >> u >> v >> cap;
        c[u][v] += cap;
    }
    for(long long u = 1; u <= n; u++) {
        for(long long v = u+1; v <= n; v++) {
            if(c[u][v] > 0 && c[v][u] > 0) {// 有反向边
                size++;
                c[v][size] = c[v][u];
                c[size][u] = c[v][u];
                c[v][u] = 0;
            }
        }
    }
    long long maxflow = 0;
    vector<long long> depth(MAX, -1);
    while(bfs(c, depth)) {
        maxflow += dfs(c, depth, s, LONG_LONG_MAX);
        fill(depth.begin(), depth.end(), -1);
    }
    cout << maxflow << endl;
    return 0;
}