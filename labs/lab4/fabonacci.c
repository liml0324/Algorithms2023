#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void matrix_mul_ts(long long a[][2], long long b[][2]) {
    long long c[2][2] = {0};
    c[0][0] = ((a[0][0] * b[0][0]) % ((long long)1e9+7) + (a[0][1] * b[1][0]) % ((long long)1e9+7)) % ((long long)1e9+7);
    c[0][1] = ((a[0][0] * b[0][1]) % ((long long)1e9+7) + (a[0][1] * b[1][1]) % ((long long)1e9+7)) % ((long long)1e9+7);
    c[1][0] = ((a[1][0] * b[0][0]) % ((long long)1e9+7) + (a[1][1] * b[1][0]) % ((long long)1e9+7)) % ((long long)1e9+7);
    c[1][1] = ((a[1][0] * b[0][1]) % ((long long)1e9+7) + (a[1][1] * b[1][1]) % ((long long)1e9+7)) % ((long long)1e9+7);
    a[0][0] = c[0][0];
    a[0][1] = c[0][1];
    a[1][0] = c[1][0];
    a[1][1] = c[1][1];
    return;
}

void matrix_mul(long long a[][2], long long b[][2], long long c[][2]) {
    c[0][0] = ((a[0][0] * b[0][0]) % ((long long)1e9+7) + (a[0][1] * b[1][0]) % ((long long)1e9+7)) % ((long long)1e9+7);
    c[0][1] = ((a[0][0] * b[0][1]) % ((long long)1e9+7) + (a[0][1] * b[1][1]) % ((long long)1e9+7)) % ((long long)1e9+7);
    c[1][0] = ((a[1][0] * b[0][0]) % ((long long)1e9+7) + (a[1][1] * b[1][0]) % ((long long)1e9+7)) % ((long long)1e9+7);
    c[1][1] = ((a[1][0] * b[0][1]) % ((long long)1e9+7) + (a[1][1] * b[1][1]) % ((long long)1e9+7)) % ((long long)1e9+7);
    return;
}

int main() {
    long long n;
    scanf("%d", &n);
    n-=2;
    long long i, max = 0;
    for(i = 0; i < 31; i++) {
        if(n & (1 << i) )   max=i;
    }
    long long mtx[max+1][2][2];
    mtx[0][0][0] = 1;
    mtx[0][0][1] = 1;
    mtx[0][1][0] = 1;
    mtx[0][1][1] = 0;
    long long ans[2][2] = {{1, 0}, {0, 1}};
    if(n & 1)    matrix_mul_ts(ans, mtx[0]);
    for(i = 1; i <= max; i++) {
        matrix_mul(mtx[i-1], mtx[i-1], mtx[i]);
        if(n & (1 << i))    matrix_mul_ts(ans, mtx[i]);
    }
    printf("%lld", (ans[0][0] + ans[0][1]) % ((long long)1e9+7));
    return 0;
}

