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

const int N=200010;

ll n,c,ans[N],rec[N],cc[N];
struct Node{
  int a,num;
}node[N];

signed main(){
  //freopen();
  //freopen();
  srand(time(0));
  IOS
  int T;
  cin>>T;
  while(T--){
    cin>>n>>c;
    for(int i=1;i<=n;++i){
      cin>>node[i].a,node[i].num=i;
      rec[i]=rec[i-1]+node[i].a;
    }
    sort(node+1,node+1+n,[&](Node A,Node B){
      return A.a>B.a;
    });
    for(int i=1;i<=n;++i) cc[node[i].num]=i;
    
    if(node[1].num!=1){
      if(node[1].a>node[cc[1]].a+c) ans[node[1].num]=0;
      else if(node[1].a==node[cc[1]].a+c&&node[cc[1]].num>node[1].num)
        ans[node[1].num]=0;
      else ans[node[1].num]=n-1;
    } else ans[1]=0;

    for(int i=2;i<=n;++i){
      int o=node[1].num<node[i].num;
      if(rec[node[i].num-1]+c+node[i].a>node[1].a)
        ans[node[i].num]=node[i].num-1;
      else if(rec[node[i].num-1]+c+node[i].a<node[1].a)
        ans[node[i].num]=node[i].num-o;
      else
        ans[node[i].num]=node[i].num-1;
    }

    for(int i=1;i<=n;++i)
      cout<<ans[i]<<" ";
    cout<<'\n';
  }
  
  return 0;
}