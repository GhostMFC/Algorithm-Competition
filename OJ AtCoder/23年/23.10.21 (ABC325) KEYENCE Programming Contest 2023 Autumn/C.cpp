#include <bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
#define ull unsigned long long
#define llinf 0x7fffffffffffffff
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define PRC(b,a) fixed<<setprecision(a)<<b
#define pb push_back
#define All(x) x.begin(),x.end()
#define Next(a,b) for(int a=head[b];a;a=edge[a].nxt)
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
inline void Cout(){cout<<endl;}
template <class T1,class...T2>
inline void Cout(T1 x,T2 ...y){cout<<x<<' ';Cout(y...);}

const int N=1005;

int n,m;
char s[N][N];
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

inline void dfs(int x,int y){
  s[x][y]='.';
  for(int i=0;i<8;++i){
    int tx=x+d2x[i],ty=y+d2y[i];
    if(s[tx][ty]=='#') dfs(tx,ty);
  }
}

signed main(){
  IOS

  cin>>n>>m;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      cin>>s[i][j];
  
  int ans=0;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      if(s[i][j]=='#')  
        dfs(i,j),++ans;
  
  cout<<ans<<'\n';
  return 0;
}