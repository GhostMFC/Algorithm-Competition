#include <bits/stdc++.h>
#include <ext/rope>//__gnu_cxx
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

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

#define All(x) x.begin(),x.end()

const int N=115;

#define int long long

int n,a[N],b[N],c[N];
int tmp[10]={0,4,9,5,7,11,13,17,19,23};

inline void solve(){
	for(int i=1;i<=n;++i)
    cin>>b[i];
  //n%tmp[i]=b[i]
  
  int ans=c[b[1]]+1,sum=1,tot=1;
  for(int i=1;i<9;++i){
    tot+=tmp[i];
    sum=sum*tmp[i]/Gcd(sum,tmp[i]);
    int p=(c[b[tot]]+1)%tmp[i+1];
    while((ans%tmp[i+1])!=p)
      ans+=sum;
  }
    // int i = 2;
    // ll ans = 0, w = 1;
    // for (int j=1;j<=9;++j) {
    //   ll x=tmp[j];
    //     ll r = (b[i - 1] - i + x) % x;
    //     while (ans % x != r) {
    //         ans += w;
    //     }
    //     w *= x;
    //     i += x;
    // }

  cout<<ans<<'\n';
}

signed main(){
//  freopen("F.in","r",stdin);
//  freopen("F.out","w",stdout);
  IOS

  n=108;//
  cout<<n<<"\n";
  std::cout<<std::flush;
  //构造CRT?
  // int l=1,r=n;
  // for(int i=1;i<=9;++i){
  //   int cnt=0;
  //   a[l]=r,c[l]=cnt;
  //   for(int j=1;j<tmp[i]-1;++j,--r)
  //     a[r]=r-1,c[r]=++cnt;
  //   a[r]=l,c[r]=++cnt,++l,--r;
  // }
  int k=0;
  for(int i=1;i<10;++i){
    int cnt=0;
		for(int j=k+1;j<k+tmp[i];++j) cout<<j+1<<' ',c[j+1]=cnt++;
		cout<<k+1<<' '; c[k+1]=cnt++;
		k+=tmp[i];
	} cout<<"\n";

  // for(int i=1;i<=n;++i)
  //   cout<<c[i]<<' ';

  // for(int i=1;i<=n;++i)
  //   printf("%lld ",a[i]);
  std::cout<<std::flush;
  solve();
  // system("pause");
  return 0;
}
/*

*/