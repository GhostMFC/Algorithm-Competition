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
#define Next(a,b) for(int a=head[b];a;a=edge[a].nxt)
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}

const int N=12005,M=200005;

int n,m,s,t,cnt=1,head[N],cur[N];
struct Edge{int to,nxt,val;}edge[M<<1];
inline void Add(int fo,int to,int val){
  edge[++cnt]={to,head[fo],val};
  head[fo]=cnt;
}

int dep[N],gap[N];
void bfs(){
  memset(dep,-1,sizeof(dep));
  memset(gap,0,sizeof(gap));
  dep[t]=0,gap[0]=1;
  queue<int> q; q.push(t);
  while(q.size()){
    int c=q.front(); q.pop();
    Next(i,c){
      int &to=edge[i].to;
      if(dep[to]!=-1) continue;
      q.push(to); dep[to]=dep[c]+1;
      gap[dep[to]]++;
    }
  }
}//从t到s点的深度

int maxflow;
inline int dfs(int x,int flow){
  if(x==t){
    maxflow+=flow;
    return flow;
  } int res=flow;
  for(int i=cur[x];i&&res;i=edge[i].nxt){
    int &to=edge[i].to; cur[x]=i;
    if(dep[to]+1==dep[x]&&edge[i].val){
      int tmp=dfs(to,min(edge[i].val,res));
      edge[i].val-=tmp,edge[i^1].val+=tmp,res-=tmp;
    }
  }//结束,说明该点出去的所有点已经流过
  if(res){//还有剩余流量,考虑更改dep,使得该点和其出去的点分开
    --gap[dep[x]];
    if(!gap[dep[x]]) dep[s]=n+1;//出现断层
    gap[++dep[x]]++;
  } return flow-res;
}

int ISAP(){
  maxflow=0;
  bfs();
  while(dep[s]<n){
    memcpy(cur,head,sizeof(cur));
    dfs(s,inf);
  }
  return maxflow;
}

signed main(){
  IOS
  cin>>n>>m>>s>>t;
  for(int i=1;i<=m;++i){
    int fo,to,val;
    cin>>fo>>to>>val;
    Add(fo,to,val);
    Add(to,fo,0);
  } cout<<ISAP()<<'\n';
  
  return 0;
}