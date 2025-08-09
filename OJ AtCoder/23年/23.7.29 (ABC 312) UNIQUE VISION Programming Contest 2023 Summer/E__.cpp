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

#define pb push_back
#define All(x) x.begin(),x.end()

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const double PI=acos(-1),eps=1e-10;

int mp[102][102][102];
map<pair<int,int>,bool> tag;
struct C{ int lx,rx,ly,ry,lz,rz;}c;
int n,ans[100010],d[6][3]={{1,0,0},{0,1,0},{0,0,1}};

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  cin>>n;

  for(int i=1;i<=n;++i){
    cin>>c.lx>>c.ly>>c.lz>>c.rx>>c.ry>>c.rz;
    if(c.lz>c.rz) swap(c.lz,c.rz);
    if(c.lx>c.rx) swap(c.lx,c.rx);
    if(c.ly>c.ry) swap(c.ly,c.ry);
    for(int ii=c.lx;ii<c.rx;++ii)
      for(int j=c.ly;j<c.ry;++j)
        for(int k=c.lz;k<c.rz;++k)
          mp[ii+1][j+1][k+1]=i;
  }

  for(int i=1;i<=100;++i)
    for(int j=1;j<=100;++j)
      for(int k=1;k<=100;++k) if(mp[i][j][k]){
        int v=mp[i][j][k];
          for(int u=0;u<3;++u){
            int q=mp[i+d[u][0]][j+d[u][1]][k+d[u][2]];
            if(q!=v&&q&&!tag[{v,q}]){
              // cout<<i<<' '<<j<<' '<<k<<"---"<<i+u<<' '<<j+w<<' '<<k+p<<'\n';
              ans[v]++,ans[q]++,tag[{v,q}]=1;
            }
          }
      }
  
  for(int i=1;i<=n;++i) cout<<ans[i]<<'\n';
  
  return 0;
}