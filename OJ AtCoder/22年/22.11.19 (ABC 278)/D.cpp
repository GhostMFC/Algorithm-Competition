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

const int maxn=2e5+5;

ll n,m,a[maxn],tag;

struct Node{
	int l,r,lch,rch;
	ll val,tag;
}node[maxn<<1];
int cnt;
inline int build(int l,int r){
	int x=++cnt;
	node[x].l=l,node[x].r=r;
	if(l==r){
		node[x].val=a[l];
		node[x].tag=-1;
		return x;
	} int mid=(l+r)>>1;
	ls=build(l,mid),rs=build(mid+1,r);
	node[x].tag=-1;
	return x;
}

inline void push_down(int x){
	if(node[x].tag==-1) return ;
	node[x].val=node[ls].tag=node[rs].tag=node[x].tag;
	node[x].tag=-1;
}

inline void update(int x,int pos,ll val){
	if(node[x].l==node[x].r){
		push_down(x);
		node[x].val+=val;
		return ; 
	} int mid=(node[x].l+node[x].r)>>1;
	push_down(x);
	if(pos<=mid) update(ls,pos,val);
	else update(rs,pos,val);
}

inline ll query(int x,int pos){
	if(node[x].l==node[x].r){
		push_down(x);
		return node[x].val;
	}
	push_down(x);
	int mid=(node[x].l+node[x].r)>>1;
	if(pos<=mid) return query(ls,pos);
	else return query(rs,pos);
}

int main(){
//  freopen("D.in","r",stdin);
//  freopen("D.out","w",stdout);
  IOS
  cin>>n; //scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		cin>>a[i];
	
	build(1,n);
	
	cin>>m;
	int opt;
	ll x,pos;
	while(m--){
		cin>>opt;
		if(opt==1){
			cin>>node[1].tag;
		} else if(opt==2){
			cin>>pos>>x;
			update(1,pos,x);
		} else{
			cin>>pos;
			cout<<query(1,pos)<<'\n';
		}
	}
//  system("pause");
  return 0;
}

