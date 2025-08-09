#include <bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
#define ull unsigned long long
#define llinf 0x7fffffffffffffff
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define PRC(b,a) fixed<<setprecision(a)<<b
#define pb push_back
#define All(x) x.begin(),x.end()
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}

const int N=205,M=5005;

struct Edge{ int to,nxt; ll flow;};

struct Dinic{
  int n,m,s,t,cnt;
  Edge edge[M<<1];
  int head[N],cur[N],level[N];//当前弧优化,层级
  void Add(int fo,int to,ll flow){
    edge[++cnt]={to,head[fo],flow};
    head[fo]=cnt;
  }
  
  void Init(){
  	cnt=1;
  	memset(head,0,sizeof head);
	}

  inline bool bfs(){
    queue<int> Q;
    memset(level,0,sizeof(level));
    Q.push(s); level[s]=1;
    while(!Q.empty()){
      int c=Q.front(); Q.pop();
      for(int i=head[c];i;i=edge[i].nxt){
        int &to=edge[i].to;
        if(!level[to]&&edge[i].flow){
          level[to]=level[c]+1;
          Q.push(to);
        }
      }
    } return level[t];
  }

  inline ll dfs(int x,ll flow){
    if(x==t) return flow;
    ll res=flow;
    for(int i=cur[x];i&&res;i=edge[i].nxt){
      cur[x]=i; int &to=edge[i].to;
      if(level[to]==level[x]+1&&edge[i].flow){
        ll tmp=dfs(to,min(res,edge[i].flow));
        edge[i].flow-=tmp,edge[i^1].flow+=tmp;
        res-=tmp;
      }
    } return flow-res;
  }

  inline ll solve(){
    ll res=0,k=0;
    while(bfs()){
      memcpy(cur,head,sizeof cur);
      while(k=dfs(s,llinf)) res+=k;
    } return res;
  }
};

int tag[N][N];
signed main(){
  IOS
  Dinic a; a.Init();
  cin>>a.n>>a.m>>a.s>>a.t;
  int fo,to; ll flow;
  while(a.m--){
    cin>>fo>>to>>flow;
    if(fo==to) continue;
    if(tag[fo][to]) a.edge[tag[fo][to]].flow+=flow;
    else{
      a.Add(fo,to,flow);
      tag[fo][to]=a.cnt;
      a.Add(to,fo,0);
      tag[to][fo]=a.cnt;
    }
  } cout<<a.solve()<<'\n';
  
  return 0;
}