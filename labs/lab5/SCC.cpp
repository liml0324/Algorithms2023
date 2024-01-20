#include<bits/stdc++.h>
using namespace std;
int scc_no = 0;
void dfs(vector<vector<int>>& G, int u, vector<int>& visited, vector<int>& order) {
    visited[u] = 1;
    for (int v : G[u]) {
        if (!visited[v]) {
            dfs(G, v, visited, order);
        }
    }
    order.push_back(u);
}
void dfs2(vector<vector<int>>& G, vector<int> &in_degree, vector<int> &out_degree, int u, vector<int>& visited, vector<int>& SCC) {
    visited[u] = scc_no;
    SCC.push_back(u);
    for (int v : G[u]) {
        if (!visited[v]) {
            dfs2(G, in_degree, out_degree, v, visited, SCC);
        }
        else if (visited[v] != scc_no) {
            in_degree[visited[v]]++;
            out_degree[scc_no]++;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n+1);
    vector<vector<int>> Gt(n+1);// G的转置
    vector<int> visited(n+1, 0);// 记录节点是否被访问过
    vector<int> order(0);// 记录节点的访问顺序
    order.push_back(0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        Gt[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(G, i, visited, order);
        }
    }
    vector<vector<int>> SCC(n+1);// 强连通分量
    fill(visited.begin(), visited.end(), 0);
    vector<int> in_degree(n+1);
    vector<int> out_degree(n+1);
    for (int i = n; i >= 1; i--) {
        if (!visited[order[i]]) {
            // std::cout << order[i] << std::endl;
            scc_no++;
            dfs2(Gt, in_degree, out_degree, order[i], visited, SCC[scc_no]);
        }
    }
    vector<int> int_0, out_0;
    for (int i = 1; i <= scc_no; i++) {
        if (in_degree[i] == 0) {
            int_0.push_back(i);
        }
        if (out_degree[i] == 0) {
            out_0.push_back(i);
        }
    }
    if (out_0.size() == 1) {
        cout << SCC[out_0[0]].size() << ' ';
    }
    else {
        cout << 0 << ' ';
    }
    if (int_0.size() == 1) {
        cout << SCC[int_0[0]].size() << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}