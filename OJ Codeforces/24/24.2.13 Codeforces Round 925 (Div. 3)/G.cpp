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

const int mod=998244353,N=4000000;

ll a[5],fac[N+5],facn[N+5];

inline ll C(int n,int m){
  if(m>n||n<0) return 0;
  return fac[n]*facn[m]%mod*facn[n-m]%mod;
}

signed main(){
  //freopen();
  //freopen();
  IOS
  int T;
  cin>>T;
  facn[0]=fac[0]=1;
  for(int i=1;i<=N;++i)
    fac[i]=fac[i-1]*i%mod;
  facn[N]=q_Pow(fac[N],mod-2,mod);
  for(int i=N-1;i;--i)
    facn[i]=facn[i+1]*(i+1)%mod;
  while(T--){
    for(int i=1;i<=4;++i)
      cin>>a[i];
    //1->2, 1->3
    //2->1, 2->4
    //3->2
    //4->1
    //4->4, 3->3
    //...it's a permutation and initially it's 1-2-1-2-1-2...
    //and we can put 3&&4 into it, specifically:
    // 4-1-3-2-4-1-3-2....
    ll ans,t1,t2,t3,t4;
    if(abs(a[1]-a[2])>1) goto NO;
    if(!a[1]&&!a[2]&&!a[3]&&!a[4]) goto A0;
    if(!a[1]&&!a[2]&&((!a[3]&&a[4])||(!a[4]&&a[3]))) goto A0;
    if(a[1]^a[2]){
      t1=Max(a[1],a[2]);
      //put a[3](a[4]) balls into t1 boxes,empty boxes are ok
      t2=a[3]+t1;
      ans=C(t2-1,t1-1);
      t3=a[4]+t1;
      ans=ans*C(t3-1,t1-1)%mod;
    } else{
      t1=a[1]+1,t2=a[1],t3=a[3]+t1,t4=a[4]+t2;
      ans=C(t3-1,t1-1)*C(t4-1,t2-1)%mod;
      // cout<<t1<<' '<<t2<<' '<<t3<<' '<<t4<<' '<<ans<<'\n';
      --t1,++t2,--t3,++t4;
      (ans+=C(t3-1,t1-1)*C(t4-1,t2-1))%=mod;
    }
    cout<<ans<<'\n';
    continue;
    NO:cout<<"0\n";
    continue;
    A0:cout<<1<<'\n';
  }
  
  return 0;
}
/*
1
900000 900000 900000 900000

794100779
*/