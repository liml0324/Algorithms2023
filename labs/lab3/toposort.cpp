#include<bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);//邻接表
    int c[n] = {0};//每个节点的孩子数目
    int num[n] = {0};//从每个节点开始的路径数目
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[v-1].push_back(u-1);//反向建图
        c[u-1]++;
    }
    int root;
    for(int i = 0; i < n; i++)
        if(adj[i].empty()) root = i;
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(c[i] == 0) {
            q.push(i);//将叶子节点入队
            num[i] = 1;
        }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            c[v]--;
            num[v] += num[u];
            num[v] %= (int)(1e9+7);
            if(c[v] == 0) q.push(v);
        }
    }
    int ans = num[root] % (int)(1e9+7);
    cout << ans << endl;
}