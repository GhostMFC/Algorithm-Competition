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

int n,m,t,x[N],y[N],A,B,a[N],b[N],mx,mn;
map<pair<int,int>,int> mp;

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  cin>>n>>m>>t;
  for(int i=1;i<=t;++i) cin>>x[i]>>y[i];
  cin>>A;
  for(int i=1;i<=A;++i)
    cin>>a[i];
  a[A+1]=2e9;
  cin>>B;
  for(int i=1;i<=B;++i)
    cin>>b[i];
  b[B+1]=2e9;
  for(int i=1;i<=t;++i){
    int l=lower_bound(a+1,a+2+A,x[i])-a-1;
    int r=lower_bound(b+1,b+2+B,y[i])-b-1;
    mp[{l,r}]++;
    mx=Max(mx,mp[{l,r}]);
  }

  if(1ll*(A+1)*(B+1)<=200000ll){
    mn=1e9;
    for(int i=0;i<=A;++i)
      for(int j=0;j<=B;++j)
        mn=Min(mn,mp[{i,j}]);
  }

  cout<<mn<<' '<<mx<<'\n';
  return 0;
}
