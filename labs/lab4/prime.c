#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int l, r;
    scanf("%d%d", &l, &r);
    if(r < 2) {//排除掉r小于2
        printf("0");
        return 0;
    }
    if(l < 2)  l = 2;//l小于2的直接改成2，以免多算一个1
    int n = (int)sqrt(r);
    int *nprime = (int*)calloc(n+1, sizeof(int));
    int *range = (int*)calloc(r-l+1, sizeof(int));
    int i;
    for(i = 2; i <= n; i++) {
        if(nprime[i] == 1)   continue;//不是素数
        int j;
        for(j = i*i; j <= n; j += i) {//j是合数
            nprime[j] = 1;
        }
        for(j = l/i*i; j <= r; j += i) {
            if(j < l || j == i)   continue;
            range[j-l] = 1;
        }
    }
    int ans = 0;
    for(i = 0; i < r-l+1; i++) {
        if(range[i] == 0)    {
            ans += 1;
            // printf("%d\n", i+l);
        }
    }
    printf("%d", ans);
    return 0;
}