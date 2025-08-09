#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <utility>
#include <numeric>
#include <queue>
#include <map>
#include <tr1/unordered_map>
#include <vector>
#include <ctime>
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
#define PRC(a,b) fixed<<setprecision(b)<<a
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
inline double Min(double xx,double yy){return xx>yy?yy:xx;}//(XX-YY>>63)?.:.;
inline double Max(double xx,double yy){return xx<yy?yy:xx;}
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0;while(yy){if(yy&1)oo=(oo+xx)%pp;xx=(xx<<1)%pp;yy>>=1;}return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
//q_Pow can conbine with q_Mul to avoid overflow

template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const int N=20;
const int maxp=(1<<19)+1234;

int n,m;
struct PLC{
	double x,y;
}pl[N];
double dis[N][N],f[maxp][N],ans=llinf1;

inline void dfs(double ds,double speed,int pos,int tot,int status){
	if(ans<=ds||f[status][pos]<=ds) return ;
	f[status][pos]=ds;
	if(tot>n){
		ans=Min(ans,ds+(dis[pos][1])/speed);
		return ;
	}
	
	for(int i=1;i<=n;++i){
		if(status&(1<<(i-1))) continue;
		dfs(ds+(dis[pos][i])/speed,speed,i,tot+1,status|(1<<(i-1)));
		
	}
	
	for(int i=n+1;i<=n+m;++i){
		if(status&(1<<(i-1))) continue;
		dfs(ds+(dis[pos][i])/speed,speed*2.0,i,tot,status|(1<<i-1));
	}
}

inline void solve(){
	memset(f,0x7f7f7f,sizeof(f));
	dfs(0,1,1,2,1);
	cout<<PRC(ans,10)<<'\n';
}

inline double q_2(double x){return x*x;}
inline double q_dis(int x,int y)
{return sqrt(q_2(pl[x].x-pl[y].x)+q_2(pl[y].y-pl[x].y));}

inline void Solve(){
	for(int i=1;i<=n+m;++i)
		for(int j=1;j<=n+m;++j)
			dis[i][j]=q_dis(i,j);
	solve();
}

int main(){
//  freopen("E.in","r",stdin);
//  freopen("E.out","w",stdout);
  IOS
  cin>>n>>m; //scanf("%d%d",&n,&m);
  ++n;
	for(int i=2;i<=n+m;++i)
		cin>>pl[i].x>>pl[i].y;
	Solve();
//  system("pause");
  return 0;
}

