#include <stdio.h>
#include <stdlib.h>

typedef struct InitCourage{
    int c;
    int cget;
}InitCourage, *pInitCourage;

int calcCourage(int *courNeed, int num)
{
    int i;
    int courage = 0;
    for (i = 0; i < num; i++)
    {
        courNeed[i] -= i;
        if (courNeed[i] > courage)
        {
            courage = courNeed[i];
        }
    }
    return courage+1;
}

void quickSort(pInitCourage initCourage, int l, int r){//快速排序
    if (l < r)
    {   int i, j;
        InitCourage x;
        i = l;
        j = r;
        x = initCourage[i];
        while (i < j)
        {
            while (i < j && initCourage[j].c > x.c)
                j--;
            if (i < j)
                initCourage[i++] = initCourage[j];
            while (i < j && initCourage[i].c < x.c)
                i++;
            if (i < j)
                initCourage[j--] = initCourage[i];
        }
        initCourage[i] = x;
        quickSort(initCourage, l, i - 1);
        quickSort(initCourage, i + 1, r);
    }
}

int main()
{
    int caves;
    scanf("%d", &caves);
    int *devils[caves];
    int nums[caves];
    int i;
    for (i = 0; i < caves; i++)
    {
        scanf("%d", &nums[i]);
        devils[i] = (int *)malloc(sizeof(int) * nums[i]);
        int j;
        for (j = 0; j < nums[i]; j++)
        {
            scanf("%d", &devils[i][j]);
        }
    }
    struct InitCourage initCourage[caves];
    for (i = 0; i < caves; i++)
    {
        initCourage[i].c = calcCourage(devils[i], nums[i]);
        initCourage[i].cget = nums[i];
    }
    int cNeed = 0;
    quickSort(initCourage, 0, caves-1);
    int cget = 0;
    for(i = 0; i < caves; i++)
    {
        initCourage[i].c -= cget;
        cget += initCourage[i].cget;
        if (initCourage[i].c > cNeed)
        {
            cNeed = initCourage[i].c;
        }
    }
    printf("%d\n", cNeed);
    return 0;
}
