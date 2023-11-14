#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    char s[n];
    scanf("%s", s);
    cin >> m;
    char t[m];
    scanf("%s", t);
    int c[n+1][m+1];//c[i][j]表示s的前i个字符和t的前j个字符的最长公共子序列的长度
    for(int i = 0; i <= n; i++){
        c[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        c[0][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            c[i][j] = max(c[i-1][j], c[i][j-1]);
            if(s[i-1] == t[j-1]){
                c[i][j] = max(c[i][j], c[i-1][j-1]+1);
            }
        }
    }
    cout << c[n][m] << endl;
    return 0;
}