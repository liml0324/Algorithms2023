#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);//邻接表
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back({v-1, w});
        adj[v-1].push_back({u-1, w});
    }
    vector<bool> vis(n, false);//标记是否访问过
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//小底堆
    pq.push({0, 0});
    int cost = 0;
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int u = p.second;
        if(vis[u]) continue;
        vis[u] = true;
        cost += p.first;
        for(pair<int, int> v : adj[u]){
            if(!vis[v.first]){
                pq.push({v.second, v.first});
            }
        }
    }
    cout << cost << endl;
    return 0;
}