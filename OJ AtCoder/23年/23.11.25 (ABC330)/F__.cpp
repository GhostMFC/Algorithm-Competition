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
inline void Cout(){cout<<endl;}
template <class T1,class...T2>
inline void Cout(T1 x,T2 ...y){cout<<x<<' ';Cout(y...);}

#define pb push_back
#define All(x) x.begin(),x.end()

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const double PI=acos(-1),eps=1e-10;

const int N=200010;

int n;
ll x[N],y[N],k,sx[N],sy[N];

inline bool check(ll a){
  ll resx=llinf,resy=llinf;
  for(int i=1;i<=n;++i){
    ll tmp=0;
    tmp+=x[i]*(i-1)-sx[i-1];
    int pos=lower_bound(x+1,x+1+n,x[i]+a)-x;
    // if(a==3) cout<<i<<": "<<pos<<'\n';
    if(pos<=n) tmp+=sx[n]-sx[pos-1]-(x[i]+a)*1ll*(n-pos+1);
    resx=Min(resx,tmp);

    tmp=0;
    tmp+=sx[n]-sx[i]-1ll*(n-i)*x[i];
    pos=lower_bound(x+1,x+1+n,x[i]-a)-x-1;
    if(x[i]-a>x[1]) tmp+=(x[i]-a)*pos-sx[pos];
    resx=Min(resx,tmp);
  } 

  for(int i=1;i<=n;++i){
    ll tmp=0;
    tmp+=y[i]*(i-1)-sy[i-1];
    int pos=lower_bound(y+1,y+1+n,y[i]+a)-y;
    if(pos<=n) tmp+=sy[n]-sy[pos-1]-(y[i]+a)*1ll*(n-pos+1);
    resy=Min(resy,tmp);
    
    tmp=0;
    tmp+=sy[n]-sy[i]-1ll*(n-i)*y[i];
    pos=lower_bound(y+1,y+1+n,y[i]-a)-y-1;
    if(y[i]-a>y[1]) tmp+=(y[i]-a)*pos-sy[pos];
    resy=Min(resy,tmp);
  }
  // cout<<a<<": "<<resx<<' '<<resy<<'\n';

  return resx+resy<=k;
}

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  cin>>n>>k;
  for(int i=1;i<=n;++i)
    cin>>x[i]>>y[i];
  
  sort(x+1,x+1+n),sort(y+1,y+1+n);
  for(int i=1;i<=n;++i)
    sx[i]=sx[i-1]+x[i],sy[i]=sy[i-1]+y[i];

  ll l=0,r=Max(x[n]-x[1],y[n]-y[1]);
  while(l<r){
    ll mid=(l+r)>>1;
    if(check(mid)) r=mid;
    else l=mid+1;
  }

  cout<<l<<'\n';
  
  return 0;
}