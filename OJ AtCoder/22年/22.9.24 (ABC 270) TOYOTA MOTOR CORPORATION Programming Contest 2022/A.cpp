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
inline ll lowbit(ll xx){return xx&(-xx);}
inline ll Min(ll xx,ll yy){return xx>yy?yy:xx;}//(XX-YY>>63)?.:.;
inline ll Max(ll xx,ll yy){return xx<yy?yy:xx;}
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0;while(yy){if(yy&1)oo=(oo+xx)%pp;xx=(xx<<1)%pp;yy>>=1;}return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
//q_Pow can conbine with q_Mul to avoid overflow

template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const int maxn=10;

int n;
bool ok[maxn];

int main(){
//  freopen("A.in","r",stdin);
//  freopen("A.out","w",stdout);
  IOS
  cin>>n; //scanf("%d%d",&n,&m);
  if(n==0) ok[0]=true;
  else if(n==1) ok[1]=true;
  else if(n==2) ok[2]=true;
  else if(n==3) ok[1]=ok[2]=true;
  else if(n==4) ok[4]=true;
  else if(n==5) ok[1]=ok[4]=true;
  else if(n==6) ok[2]=ok[4]=true;
  else ok[1]=ok[2]=ok[4]=true;
  cin>>n;
  if(n==0) ok[0]=true;
  else if(n==1) ok[1]=true;
  else if(n==2) ok[2]=true;
  else if(n==3) ok[1]=ok[2]=true;
  else if(n==4) ok[4]=true;
  else if(n==5) ok[1]=ok[4]=true;
  else if(n==6) ok[2]=ok[4]=true;
  else ok[1]=ok[2]=ok[4]=true;
	
	int ans=0;
	if(ok[1]) ans++;
	if(ok[2]) ans+=2;
	if(ok[4]) ans+=4;
	
	cout<<ans<<'\n';
//  system("pause");
  return 0;
}

