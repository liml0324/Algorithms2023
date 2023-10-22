#include <stdio.h>

int main()
{
    int arr[46] = {0};
    arr[1] = 1;
    arr[2] = 2;
    int n;
    scanf("%d", &n);
    int i;
    for (i = 3; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("%d\n", arr[n]);
    return 0;
}
