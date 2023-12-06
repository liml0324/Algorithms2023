#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int Min[n+1] = {0};//从1到i的最短路径长度
    int num[n+1] = {0};//从1到i的最短路径的条数
    vector<vector<int>> adj(n+1);//邻接表
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);//建图
        adj[v].push_back(u);
    }
    queue<int> q;
    int vis[n+1] = {0};
    q.push(1);
    num[1] = 1;
    while(q.size()) {//无向无权图，BFS足矣
        auto u = q.front();
        q.pop();
        for(auto v: adj[u]) {
            if(!vis[v]) {//未访问过的顶点，设置最短路，标记已访问，入队
                Min[v] = Min[u] + 1;
                vis[v] = 1;
                q.push(v);
            }
            if(Min[v] == Min[u] + 1) {//如果v的最短路长度等于u的最短路长度+1，那么v的最短路径数还要加上u的最短路径数
                num[v] += num[u];
                num[v] %= (int)(1e9+7);
            }
        }
    }
    for(auto i = 2; i <= n; i++) {
        cout << num[i] << endl;
    }
    return 0;
}