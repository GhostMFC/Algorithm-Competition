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
inline ll lowbit(ll xx){ return xx&(-xx);}
inline ll min(ll xx,ll yy){ return xx>yy?yy:xx;}//(XX-YY>>63)?.:.;
inline ll max(ll xx,ll yy){ return xx<yy?yy:xx;}
inline ll gcd(ll xx,ll yy){return yy?gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0; while(yy){ if(yy&1) oo=(oo+xx)%pp; xx=(xx<<1)%pp; yy>>=1;} return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
//q_Pow can conbine with q_Mul to avoid overflow

template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const int maxn=2e5+5;

int n,a;
map <int,int> mp;

int main(){
//  freopen("C.in","r",stdin);
//  freopen("C.out","w",stdout);
  IOS
  cin>>n; //scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		cin>>a;//target
		int k1,k2;//dis
		if(a<i) k2=a+n-i,k1=a-i;
		else if(a>i) k2=a-i,k1=-(i+n-a);
		else k2=0,k1=0;
		if(k1==-1&&k2==1||!k1) ++mp[k1];
		else ++mp[k1],++mp[k2];
	}
	int ans=0;
	for(int i=-n;i<=n;++i)
		ans=max(ans,mp[i]+mp[i-1]+mp[i+1]);
	cout<<ans<<'\n';
//  system("pause");
  return 0;
}

