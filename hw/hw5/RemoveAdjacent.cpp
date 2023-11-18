#include<bits/stdc++.h>

typedef struct DLNode {
    int value, del;//用del表示该节点是否已被删除
    struct DLNode *prev, *next;
} DLNode, *DList;

void countSort(DList arr[], int n) {
    int c[26] = {0}; DList res[n];
    for(int i = 0; i < n; i++) {
        c[arr[i]->value]++;
    }
    for(int i = 1; i < 26; i++) {
        c[i] += c[i-1];
    }
    for(int i = n-1; i >= 0; i--) {
        res[c[arr[i]->value]-1] = arr[i];
        c[arr[i]->value]--;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = res[n-i-1];
    }
    return;
}

void mergeSort(DList arr[], int l, int r) {//按节点对应元素从大到小排序
    //归并排序
    if(l >= r) return;
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    DList temp[r-l+1];
    int i = l, j = mid+1, k = 0;
    while(i <= mid && j <= r) {
        if(arr[i]->value > arr[j]->value) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];
    for(int i = l; i <= r; i++) arr[i] = temp[i-l];
    return;
}
int deleteNum(int num[], int n) {
    int count = 0;
    DList Head = (DList)malloc(sizeof(DLNode));
    Head->prev = Head->next = Head;
    Head->value = INT_MAX;//inf表示正无穷
    Head->del = 0;
    DList prev = Head;
    DList pArr[n];//指针数组
    for(int i = 0; i < n; i++) {
        DList p = (DList)malloc(sizeof(DLNode));
        pArr[i] = p;
        p->value = num[i];
        p->del = 0;
        p->prev = prev;
        p->next = NULL;
        prev->next = p;
        prev = p;
    }
    // mergeSort(pArr, 0, n-1);//按节点对应元素从大到小排序
    countSort(pArr, n);//按节点对应元素从小到大排序
    // for(int i = 0; i < n; i++)  std::cout << pArr[i]->value << " ";
    // std::cout << std::endl;
    for(int i = 0; i < n; i++) {
        DList p = pArr[i];
        if(p->del) continue;//遇到已删除的节点，跳过
        if(p && p->prev && p->prev->value==p->value-1)//左边的比它小1，用while可以连续删除一串相等元素
            while(p && p->prev && p->prev->value==p->value-1) {
                DList q = p->next;
                p->prev->next=p->next;
                if(p->next)//防止p是最后一个节点
                    p->next->prev=p->prev;
                p->del = 1;
                // std::cout << (char)(p->value) << std::endl;
                p=q;
                count++;
            }
        else
            while(p && p->next && p->next->value==p->value-1) {//右边的比它小1，用while可以连续删除一串相等元素
                DList q = p->prev;
                if(p->prev)//防止p是第一个节点
                    p->prev->next=p->next;
                p->next->prev=p->prev;
                p->del = 1;
                // std::cout << (char)(p->value) << std::endl;
                p=q;
                count++;
            }
    }
    for(int i = 0; i < n; i++) free(pArr[i]);//最后再释放
    free(Head);
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    int num[n];
    for(int i = 0; i < n; i++) {
        char c;
        scanf("%c", &c);
        num[i] = c - 'a';
    }
    // for(int i = 0; i < n; i++) std::cout << num[i] << " ";
    // std::cout << std::endl;
    printf("%d\n", deleteNum(num, n));
    return 0;
}