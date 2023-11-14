#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int s[n+1]={0};
    s[1] = a[1];
    for(int i = 2; i <= n; i++) {
        s[i] = max(s[i-1], s[i-2]+a[i]);
    }
    cout << s[n] << endl;
}