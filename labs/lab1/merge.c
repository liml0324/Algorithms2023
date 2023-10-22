#include <stdio.h>

int main()
{
    int lena, lenb;
    scanf("%d%d", &lena, &lenb);
    int a[lena], b[lenb];
    int i;
    for (i = 0; i < lena; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < lenb; i++)
        scanf("%d", &b[i]);
    int c[lena+lenb];
    int j = 0, k = 0;
    for (i = 0; i < lena+lenb; i++)
    {
        if (j == lena)
        {
            c[i] = b[k];
            k++;
        }
        else if (k == lenb)
        {
            c[i] = a[j];
            j++;
        }
        else if (a[j] < b[k])
        {
            c[i] = a[j];
            j++;
        }
        else
        {
            c[i] = b[k];
            k++;
        }
    }
    for (i = 0; i < lena+lenb; i++)
        printf("%d ", c[i]);
    return 0;
}
