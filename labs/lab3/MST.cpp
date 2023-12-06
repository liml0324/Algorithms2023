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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> big_heap;//大顶堆
    big_heap.push({0, 0});//从0号顶点开始
    auto sum = 0;
    while(big_heap.size()) {
        auto u = big_heap.top();
        big_heap.pop();
        if(vis[u.second])  continue;
        vis[u.second] = true;
        sum += u.first;
        for(auto v: adj[u.second]) {
            big_heap.push({v.second, v.first});//权重在前面，因为要按权重维护堆
        }
    }
    for(auto v: vis) {
        if(!v){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << sum << endl;
    return 0;
}