#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#define maxn 500010
using namespace std;
int n, m;
int a[maxn];

bool judge(int x) {
	int total = 0;
	int i = 0;
	int now = 0;
    while (i < n+1) {
        i++;
        if (a[i] - a[now] < x) {
        total++;
        } else {
        now = i;
        }
    }
    if (total > m) return false;
    return true;
}

int main() {
    int dis;
    int l, r, ans;
    cin >> dis >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    a[n+1] = dis;
    l = 1;
    r = dis;
    while (l <= r) {
        int mid = (l+r)/2;
        if (judge(mid)) {
        ans = mid;
        l = mid+1;
        } else 
        r = mid-1;
    }
    cout << ans << endl;
    return 0;
}
