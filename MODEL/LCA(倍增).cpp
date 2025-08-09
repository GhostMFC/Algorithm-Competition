#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N=1000010;

vector<int> G[N];
int n,m,fa[N][20],d[N];

inline void dfs(int x,int fafa){
  fa[x][0]=fafa;
  for(int i=1;i<=18;++i)
    fa[x][i]=fa[fa[x][i-1]][i-1];
  for(int to:G[x])
    if(to^fafa)
      d[to]=d[x]+1,dfs(to,x);
}

inline int LCA(int x,int y){
  if(d[x]>d[y]) swap(x,y);
  for(int i=18;~i;--i)
    if(d[fa[y][i]]>=d[x])
      y=fa[y][i];
  if(x==y) return x;
  for(int i=18;~i;--i)
    if(fa[x][i]!=fa[y][i])
      x=fa[x][i],y=fa[y][i];
  return fa[x][0];
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  cin>>n>>m;
  for(int i=1;i<n;++i){
    int x,y;
    cin>>x>>y;
    G[x].pb(y),
    G[y].pb(x);
  } d[1]=1;
  dfs(1,0);
  while(m--){
    int x,y;
    cin>>x>>y;
    cout<<LCA(x,y)<<'\n';
  }
  // for(int i=1;i<=n;++i)
  //   cout<<fa[i][2]<<' ';
  return 0;
}
/*
10 1
2 1
3 2
4 3
5 3
6 3
7 4
8 5
9 8
10 3
9 1
*/