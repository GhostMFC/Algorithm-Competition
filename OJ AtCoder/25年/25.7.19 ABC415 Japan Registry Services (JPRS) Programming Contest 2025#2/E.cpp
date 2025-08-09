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

int n,m;

signed main(){
  //freopen();
  //freopen();
  srand(time(0));
  IOS
  //int T;typedef long long ll;

  int n,m;
  cin>>n>>m;
  vector<vector<int>>A(n,vector<int>(m));
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      cin>>A[i][j];
  int total=n+m-1;
  vector<ll> P(total);
  for (int i=0;i<total;++i)
    cin>>P[i];

  vector<vector<ll>>dp(n,vector<ll>(m,0));

  for(int i=n-1;i>=0;--i) {
    for(int j=m-1;j>=0;--j){
      int k =i+j;
      ll base=max(0ll,(ll)(P[k]-A[i][j]));

      if(i==n-1&&j==m-1) dp[i][j]=base;
      else if(i==n-1){
        ll c=dp[i][j+1]-(A[i][j]-P[k]);
        dp[i][j]=max(base,c);
      } else if(j==m-1){
          ll c=dp[i+1][j]-(A[i][j]-P[k]);
          dp[i][j]=max(base,c);
      } else dp[i][j]=max(base,min(dp[i+1][j]-(A[i][j]-P[k]),dp[i][j+1]-(A[i][j]-P[k])));//candidates
    }
  }

  cout<<dp[0][0]<<'\n';
  
  return 0;
}