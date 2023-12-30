#include<bits/stdc++.h>
using namespace std;
int m, n, s, t;
int BFS(vector<vector<int>> &g, vector<vector<pair<int, int>>> &matrix, vector<pair<int, int>> &path) {
    queue<int> q;
    q.push(s);
    vector<bool> vis(g.size(), false);
    vis[s] = true;
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(auto &v: g[u]) {
            if(!vis[v] && matrix[u][v].first > 0 && matrix[u][v].first > matrix[u][v].second) {// 正向边
                vis[v] = true;
                q.push(v);
                path.push_back({u, v});
                if(v == t) {
                    return 1;
                }
            }
            else if(!vis[v] && matrix[v][u].first > 0 && matrix[v][u].second > 0) {// 反向边
                vis[v] = true;
                q.push(v);
                path.push_back({u, v});
                if(v == t) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main() {
    cin >> m >> n >> s >> t;
    vector<vector<int>> g(m + 1);//邻接表
    vector<vector<pair<int, int>>> matrix(m+1, vector<pair<int, int>>(m+1, {0, 0}));//邻接矩阵
    for(int i = 0; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(v);
        g[v].push_back(u);
        matrix[u][v] = {c, 0};
    }
    int flow = 0;
    vector<pair<int, int>> path;
    while(BFS(g, matrix, path)) {
        vector<pair<int, int>> act_path;
        act_path.push_back(path.back());
        int min = INT_MAX;
        for(int i = path.size()-2; i >= 0; i--) {
            if(path[i].second == act_path.back().first) {
                act_path.push_back(path[i]);
                if(matrix[path[i].first][path[i].second].first > 0 && \
                    matrix[path[i].first][path[i].second].first-matrix[path[i].first][path[i].second].second < min) {// 正向边
                    min = matrix[path[i].first][path[i].second].first-matrix[path[i].first][path[i].second].second;
                }
                else if(matrix[path[i].second][path[i].first].first > 0 && \
                    matrix[path[i].second][path[i].first].second < min) {// 反向边
                    min = matrix[path[i].second][path[i].first].second;
                }
            }
        }
        for(auto &p: act_path) {
            if(matrix[p.first][p.second].first > 0) {// 正向边
                matrix[p.first][p.second].second += min;
                matrix[p.second][p.first].second += min;
            }
            else {// 反向边
                matrix[p.second][p.first].second -= min;
                matrix[p.first][p.second].second -= min;
            }
        }
        flow += min;
        cout << min << endl;
        path.clear();
    }
    cout << flow << endl;
    return 0;
}