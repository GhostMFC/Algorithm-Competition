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

const int maxn=1e5+5;

ll n,m;
struct Node{
	ll val,ans;
	int num;
}node[maxn];

inline bool cmp(Node A,Node B){
	return A.val<B.val;
}
inline bool cmp2(Node A,Node B){
	return A.num<B.num;
}

int main(){
//  freopen("E.in","r",stdin);
//  freopen("E.out","w",stdout);
  IOS
  cin>>n>>m; //scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		cin>>node[i].val;
		node[i].num=i;
	} sort(node+1,node+1+n,cmp);
	
	int i=1,tot=0;
	while(i<=n){
		ll s=node[i].val;
		if((s-tot)*(n-i+1)>m){
			ll k=m/(n-i+1);
			for(int i=1;i<=n;++i)
				if(node[i].val>tot)
					node[i].ans=node[i].val-tot-k;
			
			sort(node+1,node+1+n,cmp2);
			
			tot+=k;
			m%=(n-i+1);
			
			break;
		} else{
			m-=(s-tot)*(n-i+1);
		}
		tot=s;
		node[i++].ans=0;
		while(node[i].val==node[i-1].val)
			++i,node[i].ans=0;
	}
	int cnt=1;
	for(int i=1;i<=n;++i){
		if(cnt<=m&&node[i].val>tot) --node[i].ans,++cnt;
		cout<<node[i].ans<<' ';
	}
//  system("pause");
  return 0;
}

