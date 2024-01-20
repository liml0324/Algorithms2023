#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<utility>
using namespace std;
const int maxn=1000050;
const int mod=1000000007;
int fa[maxn];
int findfa(int u){
	if(fa[u]==u){
        return fa[u];
    }else{
    	return fa[u]=findfa(fa[u]);
    }
}
int weight[maxn];
void uni(int u,int v){
	int fa_u=findfa(u);
  	int fa_v=findfa(v);
  	if(fa_u==fa_v) return;
  	else{
      	int a=rand()%2;
      	if(a==0){
        	fa[fa_v]=fa_u;
            weight[fa_v]=weight[fa_v]*weight[fa_u];
        }else{
            fa[fa_u]=fa_v;
            weight[fa_u]=weight[fa_u]*weight[fa_v];
        }
	}
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        cin>>weight[i];
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        uni(u,v);
    }
	return 0;
}