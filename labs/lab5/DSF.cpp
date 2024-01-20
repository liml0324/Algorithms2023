#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long quick_pow(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1) 
            ans = (long long)ans * a % MOD;
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return ans;
}
long long inv(long long a) {
    return quick_pow(a, MOD - 2);
}

class DSF{
public:
    vector<long long> parent;
    vector<long long> a;// weight
    vector<long long> size;
    vector<long long> inv_vec;
    DSF(long long n){
        parent.resize((n+1)*2);
        a.resize((n+1)*2);
        size.resize((n+1)*2);
        inv_vec.resize(n+1);
        for(long long i=1;i<=n;i++){
            parent[i]=i+n;
            parent[i+n]=i+n;
            cin>>a[i];
            a[i+n]=a[i];
            size[i]=1;
            size[i+n]=2;
            inv_vec[i]=inv(a[i]);
        }
    }
    long long find_parent(long long u){
        if(parent[u]==u){
            return u;
        }else{
            return parent[u]=find_parent(parent[u]);
        }
    }
    void merge(long long u, long long v) {
        auto parent_u = find_parent(u);
        auto parent_v = find_parent(v);
        if (parent_u == parent_v) return;
        else {
            auto a_u = a[parent_u];
            auto a_v = a[parent_v];
            auto size_u = size[parent_u];
            auto size_v = size[parent_v];
            if (size_u < size_v) {
                parent[parent_u] = parent_v;
                a[parent_v] = a_u * a_v % MOD;
                size[parent_v] += size[parent_u];
            } else {
                parent[parent_v] = parent_u;
                a[parent_u] = a_u * a_v % MOD;
                size[parent_u] += size[parent_v];
            }
        }
    }
    void move(long long u, long long v) {
        auto parent_u = find_parent(u);
        auto parent_v = find_parent(v);
        if (parent_u == parent_v) return;
        parent[u] = parent_v;
        --size[parent_u];
        ++size[parent_v];
        a[parent_v] = a[parent_v] * a[u] % MOD;
        a[parent_u] = a[parent_u] * inv_vec[u] % MOD;
    }
};

int main() {
    long long n, m;
    cin >> n >> m;
    DSF dsf(n);
    vector<long long> ans;
    for (long long i = 0; i < m; ++i) {
        long long op, u, v;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            dsf.merge(u, v);
        } else if(op == 2) {
            cin >> u;
            // std::cout << dsf.a[dsf.find_parent(u)] << std::endl;
            ans.push_back(dsf.a[dsf.find_parent(u)]);
        }
        else {
            cin >> u >> v;
            dsf.move(u, v);
        }
    }
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}