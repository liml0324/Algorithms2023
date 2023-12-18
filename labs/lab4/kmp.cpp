#include<bits/stdc++.h>
using namespace std;
void calc_pre(char t[], int pre[], int m) {
    pre[1] = 0;
    int k = 0;
    for(int i = 2; i <= m; i++) {
        while(k > 0 && t[k+1] != t[i] ) {
            k = pre[k];
        }
        if(t[k+1] == t[i]) {
            k++;
        }
        pre[i] = k;
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    char s[n+1], t[m+1];
    cin >> s+1 >> t+1;
    int pre[m+1];
    calc_pre(t, pre, m);
    int q = 0;
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        while(q > 0 && t[q+1] != s[i]) {
            q = pre[q];
        }
        if(t[q+1] == s[i]) {
            q++;
        }
        if(q == m) {
            ans.push_back(i-m);
            q = pre[q];
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << ' ';
    }
    return 0;
}