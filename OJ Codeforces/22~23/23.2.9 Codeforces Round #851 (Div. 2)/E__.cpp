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

#define All(x) x.begin(),x.end()

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const int N=200010;

int n;
ll a[N],b[N],dp[N];

struct Fenwick_Tree{
  ll tr[N];
  inline void update(int x,ll v)
  {while(x<=n+1) tr[x]=max(tr[x],v),x+=lowbit(x);}
  inline ll query(int x){
    ll res=-0x3f3f3f3f3f3f3f3f;
    while(x) res=max(tr[x],res),x-=lowbit(x);
    return res;
  }
}bit;

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  
  cin>>n;
  for(int i=1;i<=n;++i)
    cin>>a[i],a[i]+=a[i-1],b[i]=a[i];
  b[n+1]=0;
  sort(b+1,b+2+n);
  int len=unique(b+1,b+2+n)-b-1;
  for(int i=1;i<=n+1;++i) a[i]=lower_bound(b+1,b+1+n,a[i])-b;
  memset(bit.tr,-0x3f3f,sizeof(bit.tr));
  bit.update(a[n+1],0);

  for(int i=1;i<=n;++i){
    dp[i]=dp[i-1];
    ll k=bit.query(a[i]);
    if(k!=-0x3f3f3f3f3f3f3f3f)
      dp[i]=max(dp[i],k+i);
    bit.update(a[i],dp[i]-i);
  }
  cout<<dp[n]<<'\n';
  return 0;
}