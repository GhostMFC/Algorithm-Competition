#include <bits/stdc++.h>
#include <bits/extc++.h>
#define Mod 998244353
#define Mod1 10000000000037
#define ls node[x].lch
#define rs node[x].rch
#define inf 0x7fffffff
#define inf1 1000000009
#define llinf 0x7fffffffffffffff
#define llinf1 1000000000000000009
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define PRC(b,a) fixed<<setprecision(a)<<b
#define Next(a,b) for(int a=head[b];a;a=edge[a].nxt)
using namespace std;
using namespace __gnu_cxx;//rope<T> x
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
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
inline ll q_2(ll xx){return xx*xx;}
inline ll lowbit(ll xx){return xx&(-xx);}
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0;while(yy){if(yy&1)oo=(oo+xx)%pp;xx=(xx<<1)%pp;yy>>=1;}return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
//q_Pow can conbine with q_Mul to avoid overflow
template <typename T> inline T Min(T xx,T yy){return xx<yy?xx:yy;}
template <typename T> inline T Max(T xx,T yy){return xx>yy?xx:yy;}//(XX-YY>>63)?.:.;
template <typename T> inline void sMin(T &xx,T yy){xx=(xx<yy)?xx:yy;}
template <typename T> inline void sMax(T &xx,T yy){xx=(xx>yy)?xx:yy;}

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

const int N=1000005;

int n,a[N],s[N],p0,p1,_p1;

inline void solve(){
  int ans=1;
  /*for(int i=n;i;--i){
    if(s[i]==1) ++p1;
    else if(s[i]==0) ++p0;
    else if(s[i]==-1) ++_p1;
    else continue;

    if(s[n+1]==1){
      if(p0+_p1&&a[i]!=1){
        ++ans;
        p0=_p1=0;
      } else continue;
    } else{
      if(p0+_p1&&a[i]!=-1){
        ++ans;
        p0=_p1=0;
      } else continue;
    }
  }*/
  for(int i=n;i;--i){
    vector<int> vi(3),vi1(3);
    vi[0]=s[i-1]+s[n+1];
    vi1[0]=s[i],vi1[1]=s[i]+s[n+1],vi1[2]=s[i+1]+s[n+1];
    for(int j=1;j<=2;++j)
      vi[j]=vi[j-1]+a[i+j-1];
    int len=Min(3,n-i+2);
    vi.resize(len),vi1.resize(len);
    bool tag=false;
    for(int &x:vi)
      x=(x>0?1:(x==0?0:-1));
    for(int &x:vi1)
      x=(x>0?1:(x==0?0:-1));
    for(int j=0;j<len;++j)
      if(vi[j]!=vi1[j])
        tag=true;

    ans+=tag;
    // cout<<i<<' '<<tag<<'\n';
    // for(int x:vi) cout<<x<<' '; cout<<'\n';
    // for(int y:vi1) cout<<y<<' '; cout<<'\n';
  }

  cout<<ans<<'\n';
}

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  cin>>n; --n;
  char ch;
  cin>>ch;
  s[n+1]=(ch=='A')?1:-1;
  for(int i=1;i<=n;++i){
    cin>>ch;
    if(ch=='A') a[i]=1;
    else a[i]=-1;
    s[i]=s[i-1]+a[i];
  }
  solve();
  
  return 0;
}