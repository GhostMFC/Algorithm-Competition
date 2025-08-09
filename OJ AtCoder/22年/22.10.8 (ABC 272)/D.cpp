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
template <typename T> inline T Min(T xx,T yy){return xx>yy?yy:xx;}//(XX-YY>>63)?.:.;
template <typename T> inline T Max(T xx,T yy){return xx<yy?yy:xx;}

template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const int maxn=405;

int n,m;
int mp[maxn][maxn];

inline bool Check(int x,int y){
	return x*x+y*y==m;
}

int sx[maxn],sy[maxn],cnt;

struct Node{int x,y,dis;};
queue <Node> q;

inline void solve(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			mp[i][j]=-1;
	mp[1][1]=0;
	
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(Check(i,j)){
				++cnt;
				sx[cnt]=i,sy[cnt]=j;
			}
	
	int k=cnt;
	for(int i=1;i<=cnt;++i)
		sx[k+i]=-sx[i],sy[k+i]=-sy[i];
	
	for(int i=1;i<=cnt;++i)
		sx[k*2+i]=-sx[i],sy[k*2+i]=sy[i];
	
	for(int i=1;i<=cnt;++i)
		sx[k*3+i]=sx[i],sy[k*3+i]=-sy[i];
	
	cnt<<=2;
	
	q.push({1,1,0});
	while(!q.empty()){
		Node c=q.front(); q.pop();
		int x=c.x,y=c.y;
		for(int i=1;i<=cnt;++i){
			int xx=x+sx[i],yy=y+sy[i];
			if(xx<1||yy<1||xx>n||yy>n) continue;
			if(mp[xx][yy]!=-1) continue;
			mp[xx][yy]=c.dis+1;
			q.push({xx,yy,c.dis+1});
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			cout<<mp[i][j]<<' ';
		cout<<'\n';
	}
	
}

int main(){
//  freopen("D.in","r",stdin);
//  freopen("D.out","w",stdout);
  IOS
  cin>>n>>m; //scanf("%d%d",&n,&m);
	solve();
//  system("pause");
  return 0;
}

