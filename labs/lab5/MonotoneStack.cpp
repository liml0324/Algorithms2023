#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> g(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        g[i] = x;//第二个元素是下标
    }
    int envy_l[n] = {0}, envy_r[n] = {0};
    int l[n] = {0}, r[n] = {0};
    stack<pair<int, int>> s;
    for(int i = 0; i < n; i++) {// 计算每个元素左侧第一个小于等于它的元素位置
        l[i] = i;
        while(s.size() && s.top().first > g[i]) {
            s.pop();
        }
        if(s.size()) {
            l[i] = s.top().second;
        }
        s.push({g[i], i});
    }
    while(s.size()) {
        s.pop();
    }
    for(int i = n - 1; i >= 0; i--) {// 计算每个元素右侧第一个小于等于它的元素位置
        r[i] = i;
        while(s.size() && s.top().first > g[i]) {
            s.pop();
        }
        if(s.size()) {
            r[i] = s.top().second;
        }
        s.push({g[i], i});
    }
    for(int i = 0; i < n; i++) {
        if(l[i] != i) {
            envy_l[i] = envy_l[l[i]] + 1;
        }
        else {
            envy_l[i] = 0;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(r[i] != i) {
            envy_r[i] = envy_r[r[i]] + 1;
        }
        else {
            envy_r[i] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << envy_l[i] + envy_r[i] << ' ';
    }
    return 0;
}