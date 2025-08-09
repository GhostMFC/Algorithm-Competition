#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N=200010,M=500010;

bool tag[N];
vector<int> ans;
int n,m,e,q,fa[N],sz[N];
struct Edge{int fo,to,num;}edge[M];

inline int find(int x)
{return fa[x]==x?x:fa[x]=find(fa[x]);}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin>>n>>m>>e;
  for(int i=1;i<=e;++i)
    cin>>edge[i].fo>>edge[i].to;
  cin>>q;
  while(q--){
    int x;
    cin>>x;
    edge[x].num=q+1;
  }

  sort(edge+1,edge+1+e,[&](Edge A,Edge B){return A.num<B.num;});
  for(int i=1;i<=n+m;++i) fa[i]=i,sz[i]=1;
  for(int i=n+1;i<=n+m;++i) tag[i]=true;

  int pos=1,res=0;
  while(!edge[pos].num){
    int x=edge[pos].fo,y=edge[pos].to;
    int fx=find(x),fy=find(y);
    if(fx!=fy){
      fa[fx]=fy;
      bool k=tag[fx]|tag[fy];
      if(k){
        if(!tag[fx])
          tag[fx]=true,res+=sz[fx];
        if(!tag[fy])
          tag[fy]=true,res+=sz[fy];
      } sz[fy]+=sz[fx];
    }
    ++pos;
  }

  while(pos<=e){
    ans.pb(res);
    int x=edge[pos].fo,y=edge[pos].to;
    int fx=find(x),fy=find(y);
    if(fx!=fy){
      fa[fx]=fy;
      bool k=tag[fx]|tag[fy];
      if(k){
        if(!tag[fx])
          tag[fx]=true,res+=sz[fx];
        if(!tag[fy])
          tag[fy]=true,res+=sz[fy];
      } sz[fy]+=sz[fx];
    }
    ++pos;
  }
  reverse(ans.begin(),ans.end());
  for(int x:ans)
    cout<<x<<'\n';
  return 0;
}
