#include<bits/stdc++.h>
using namespace std;

int sum(int a[], int i, int j) {
    int s = 0;
    for(int k = i; k <= j; k++) {
        s += a[k];
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    int c[n+1];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    int points[n+1][n+1];
    for(int i = 1; i <= n; i++)
        points[i][i] = 0;
    for(int i = 1; i <= n-1; i++) {
        for(int j = 1; j+i <= n; j++) {
            points[j][j+i] = INT_MAX;
            for(int k = j; k < j+i; k++) {
                if(points[j][k] + points[k+1][j+i] < points[j][j+i])
                    points[j][j+i] = points[j][k] + points[k+1][j+i];
            }
            points[j][j+i] += sum(c, j, j+i);
            // cout << j << " " << j+i << " " << points[j][j+i] << endl;
        }
    }
    cout << points[1][n] << endl;
    return 0;
}