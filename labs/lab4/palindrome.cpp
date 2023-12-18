#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char str[2*n+1];
    int len[2*n+1];
    str[0] = '#';
    len[0] = 1;
    for(int i = 1; i <= n; i++) {
        str[2*i-1] = getchar();
        str[2*i] = '#';
        len[2*i-1] = len[2*i] = 1;
    }
    int c = 0, r = 1;
    for(int i = 1; i < 2*n+1; i++) {
        if(r > i)  {
            if(r-i >= len[2*c-i])   len[i] = len[2*c-i];
            else len[i] = r-i;
        }
        
        for(int j = len[i]; j <= i && j <= 2*n-i; j++) {
            if(str[i-j] == str[i+j]) {
                len[i] = j+1;
            }
            else {
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 2*n+1; i++) {
        if(len[i]-1 > ans)  ans = len[i] - 1;
    }
    cout << ans;
    return 0;
}