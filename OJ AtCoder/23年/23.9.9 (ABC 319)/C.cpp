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

#define int ll

int a[4][4],tot,fac[11];
vector<int> l[4],r[4],d[3];

bool check(){
  for(int i=1;i<=3;++i){
    if(l[i][0]==l[i][1]&&l[i][1]!=l[i][2])
      return false;
    if(r[i][0]==r[i][1]&&r[i][1]!=r[i][2])
      return false;
  }

  for(int i=1;i<=2;++i)
    if(d[i][0]==d[i][1]&&d[i][1]!=d[i][2])
      return false;
  return true;
}

bool vis[4][4];
inline void dfs(int pos){
  if(pos>9){
    tot+=check();
    return ;
  }
  for(int i=1;i<=3;++i)
    for(int j=1;j<=3;++j)
      if(!vis[i][j]){
        vis[i][j]=true;
        if(i==2&&j==2) d[1].pb(a[i][j]),d[2].pb(a[i][j]);
        else if(i==j){
          d[1].pb(a[i][j]);
        } else if(4-i==j){
          d[2].pb(a[i][j]);
        }

        l[i].pb(a[i][j]),r[j].pb(a[i][j]);
        dfs(pos+1);
        vis[i][j]=false;
        if(i==2&&j==2) d[1].pop_back(),d[2].pop_back();
        else if(i==j){
          d[1].pop_back();
        } else if(4-i==j){
          d[2].pop_back();
        }
        l[i].pop_back(),r[j].pop_back();
      }
}

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  for(int i=1;i<=3;++i)
    for(int j=1;j<=3;++j)
      cin>>a[i][j];
  
  fac[0]=1;
  for(int i=1;i<=10;++i) fac[i]=fac[i-1]*i;

  dfs(1);

  cout<<PRC(tot*1.00/fac[9],12)<<'\n';
  
  return 0;
}