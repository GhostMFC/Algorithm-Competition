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
#include <bitset>
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

const int maxn=300;
const int N=(1<<17)+123;

int vis[2][N];
int n,m,cnt,head[20];
char s[20][2];
struct Edge{
	int fo,to,nxt;
}edge[maxn<<1];

inline void Add(int fo,int to){
	edge[++cnt]={fo,to,head[fo]};
	head[fo]=cnt;
}

inline void Pre(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(s[i][1]==s[j][0])
				Add(i,j);
}

inline bool dfs(int x,int turn,int status){
	if(vis[turn][status]) return vis[turn][status]-1;
	if(!x){
		for(int i=1;i<=n;++i){
			if(turn==dfs(i,turn^1,status|(1<<i)))
				return turn;
		} return turn^1;
	}
	for(int i=head[x];i;i=edge[i].nxt){
		int &to=edge[i].to;
		if(status&(1<<to)) continue;
		if(turn==dfs(to,turn^1,status|(1<<to))){
			vis[turn][status]=turn+1;
			return turn;
		}
	}
	vis[turn][status]=(turn^1)+1;
	return turn^1;
}

inline void solve(){
	Pre();
	if(dfs(0,1,0))
		cout<<"First\n";
	else
		cout<<"Second\n";
}

int main(){
//  freopen("F.in","r",stdin);
//  freopen("F.out","w",stdout);
  IOS
	cin>>n; char tmp[12];
	for(int i=1;i<=n;++i){
		cin>>tmp+1;
		s[i][0]=tmp[1],s[i][1]=tmp[strlen(tmp+1)];
	} solve();
//  system("pause");
  return 0;
}
/*
2
ab
ba

*/
