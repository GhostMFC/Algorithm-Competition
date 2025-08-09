#include <bits/stdc++.h>
#define ll long long
#define Mod 998244353
#define Mod1 10000000000037
#define ls node[x].lch
#define rs node[x].rch
#define inf 0x7fffffff
#define inf1 1000000009
#define ull unsigned long long
#define llinf 0x7fffffffffffffff
#define llinf1 1000000000000000009
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define PRC(b,a) fixed<<setprecision(a)<<b
#define Next(a,b) for(int a=head[b];a;a=edge[a].nxt)
using namespace std;
using namespace __gnu_cxx;
template <typename T> inline void read(T &xx){
  char cc=getchar();T ff=1; xx=0;
  while(cc>'9'||cc<'0'){ ff=cc=='-'?-1:ff,cc=getchar();}
  while(cc<='9'&&cc>='0'){ xx=(xx<<1)+(xx<<3)+(cc^48),cc=getchar();}
  xx=xx*ff;
}
template <typename T> inline void write(T xx){
  if(xx<0){ putchar('-'),xx=-xx;}
  if(xx>9) write(xx/10);
  putchar(xx%10+'0');
}
inline ll lowbit(ll xx){return xx&(-xx);}
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0;while(yy){if(yy&1)oo=(oo+xx)%pp;xx=(xx<<1)%pp;yy>>=1;}return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
//q_Pow can conbine with q_Mul to avoid overflow
template <typename T> inline T Min(T xx,T yy){return xx<yy?xx:yy;}
template <typename T> inline T Max(T xx,T yy){return xx>yy?xx:yy;}//(XX-YY>>63)?.:.;

template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}

#define pb push_back
#define All(x) x.begin(),x.end()

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const double PI=acos(-1),eps=1e-10;

const int N=400010;

bool tag[N];
int n,cnt,cnt2,head2[N],head[N],c[N];
struct Edge{
  int fo,to,nxt;
}edge[N<<1],edge2[N<<1];
inline void Add(int fo,int to){
  edge[++cnt]={fo,to,head[fo]};
  head[fo]=cnt;
}
inline void Add2(int fo,int to){
  edge2[++cnt2]={fo,to,head2[fo]};
  head2[fo]=cnt2;
}

inline void dfs0(int x,int fa){
  tag[x]=true;//需要考虑的点
  for(int i=head2[x];i;i=edge2[i].nxt){
    int &to=edge2[i].to;
    if(to^fa) if(!tag[to]) dfs0(to,x);
  }
}

int _[N];

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>_[i];
    for(int j=1,fo;j<=_[i];++j){
      cin>>fo;//前置书
      if(fo==1) continue;
      Add(fo,i);
      Add2(i,fo);
    }
  }

  dfs0(1,1);

  queue<int> q;
  for(int i=1;i<=n;++i) if(tag[i]&&!_[i])
    q.push({i}); 
  
  while(q.size()){
    int a=q.front(); q.pop();
    if(a==1) return 0;
    cout<<a<<' ';
    Next(i,a){
      int &to=edge[i].to;
      _[to]--;
      if(!_[to]&&tag[to]){
        tag[to]=0;
        q.push(to);
      }
    }
  }

  return 0;
}