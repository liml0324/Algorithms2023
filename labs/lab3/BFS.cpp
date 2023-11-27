#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
int Min[MAX+1] = {0};//从1到i的最短路径长度
int num[MAX+1] = {0};//从1到i的最短路径的条数
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);//邻接表
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);//建图
        adj[v].push_back(u);
    }
    queue<int> q;   
    q.push(1);
    num[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(Min[v] == 0){//如果v没有被访问过
                Min[v] = Min[u] + 1;
                num[v] = num[u];
                q.push(v);
            }else if(Min[v] == Min[u] + 1){//如果v被访问过，且v到1的最短路径长度等于u到1的最短路径长度+1
                num[v] += num[u];
                num[v] %= (int)(1e9+7);
            }
        }
    }
    for(int i = 2; i <= n; i++){
        cout << num[i] << endl;
    }
}