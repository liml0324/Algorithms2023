#include<bits/stdc++.h>
using namespace std;
typedef struct tree {
    int num;
    int p;
    int depth;
    vector<int> c;
}treeNode;
void mergeSort(treeNode arr[], int buf[], int l, int r) {//按深度从大到小排序
    //归并排序
    if(l >= r) return;
    int mid = (l+r)/2;
    mergeSort(arr, buf, l, mid);
    mergeSort(arr, buf, mid+1, r);
    int temp[r-l+1];
    int i = l, j = mid+1, k = 0;
    while(i <= mid && j <= r) {
        if(arr[buf[i]].depth > arr[buf[i]].depth) temp[k++] = buf[i++];
        else temp[k++] = buf[j++];
    }
    while(i <= mid) temp[k++] = buf[i++];
    while(j <= r) temp[k++] = buf[j++];
    for(int i = l; i <= r; i++) buf[i] = temp[i-l];
    return;
}
void getDepth(treeNode t[], int root){
    for(int c:t[root].c){
        t[c].depth = t[root].depth+1;
        getDepth(t, c);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    treeNode t[n+1];
    for(int i = 1; i <= n; i++){
        t[i].num = i;
        t[i].p = 0;
        t[i].depth = 0;
    }
    for(int i = 1; i <= n-1; i++){
        int x, y;
        cin >> x >> y;
        t[x].p = y;
        t[y].c.push_back(x);
    }
    int pretty[n+1] = {0};
    int root;
    vector<int> leaf;
    int buf[n+1];
    int added[n+1] = {0};
    for(int i = 1; i <= n; i++){
        if(t[i].p == 0){
            root = i;
        }
        if(t[i].c.empty()){
            leaf.push_back(i);
        }
    }
    getDepth(t, root);
    for(int i = 1; i <= n; i++){
        buf[i] = i;
    }
    mergeSort(t, buf, 1, n);
    // for(int i = 1; i <= n; i++)
    //     cout << buf[i] << endl;
    for(int i = 1; i <= n; i++){
        int p1 = 0, p2 = a[buf[i]];
        if(!t[buf[i]].c.empty())
        {
            for(int c:t[buf[i]].c){
                p1 += pretty[c];
            }
            for(int c:t[buf[i]].c){
                if(t[c].c.empty())  continue;
                else{
                    for(int cc:t[c].c){
                        p2 += pretty[cc];
                    }
                }
            }
        }
        pretty[buf[i]] = max(p1, p2);
    }
    cout << pretty[root] << endl;
    return 0;
}