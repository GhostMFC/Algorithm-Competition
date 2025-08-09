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

const int N=200010;

int T,n,m,k;

struct Piece{
	ll val; int pos;
}a[N];

#define ls node[x].lch
#define rs node[x].rch

struct Node{
	int l,r,lch,rch,totmx,totmn;
	ll val,tag,tagtot;
}node[N<<1];

int cnt;
inline int build(int l,int r){
	int x=++cnt;
	node[x].l=l,node[x].r=r;
	if(l==r) return x;
	int mid=(l+r)>>1;
	ls=build(l,mid),rs=build(mid+1,r);
	return x;
}

inline ll calc(int x){
	return node[x].val+node[x].tag;
}

inline int calcmn(int x){
	return node[x].totmn+node[x].tagtot;
}
inline int calcmx(int x){
	return node[x].totmx+node[x].tagtot;
}

inline void push_down(int x){
	node[ls].tagtot+=node[x].tagtot;
	node[ls].tag+=node[x].tag;
	node[rs].tagtot+=node[x].tagtot;
	node[rs].tag+=node[x].tag;
	node[x].tag=0,node[x].tagtot=0;
}

inline void push_up(int x){
	node[x].totmn=Min(calcmn(ls),calcmn(rs));
	node[x].totmx=Max(calcmx(ls),calcmx(rs));
}

inline void update(int x,int l,int r,ll val){
	if(calcmn(x)>=k) return ;
	if(node[x].l==node[x].r){
		node[x].tag+=val,node[x].tagtot+=1;
		return ;
	}
	if(node[x].l>=l&&node[x].r<=r){
		if(calcmx(x)<k)
			node[x].tag+=val,node[x].tagtot+=1;
		else{
			push_down(x);
			if(calcmn(ls)<k)
				update(ls,l,r,val);
			if(calcmn(rs)<k)
				update(rs,l,r,val);
		}
		push_up(x);
		return ;
	} int mid=(node[x].l+node[x].r)>>1;
	push_down(x);
	if(l<=mid) update(ls,l,r,val);
	if(r>mid) update(rs,l,r,val);
	push_up(x);
}

inline ll query(int x,int pos){
	if(node[x].l==node[x].r)
		return calc(x);
	int mid=(node[x].l+node[x].r)>>1;
	push_down(x);
	if(pos<=mid) return query(ls,pos);
	else return query(rs,pos);
}

signed main(){
//  freopen("E.in","r",stdin);
//  freopen("E.out","w",stdout);
  IOS
//  cin>>T;
  T=1;
  while(T--){
  	cin>>n>>m>>k;
  	for(int i=1;i<=n;++i)
  		cin>>a[i].val,a[i].pos=i;
  	sort(a+1,a+1+n,[&](Piece A,Piece B){
  		return A.val<B.val;
		});
		
		build(1,n-m+1);
		
		for(int i=1;i<=n;++i){
			int l=Max(1,a[i].pos-m+1),r=Min(a[i].pos,n-m+1);
			update(1,l,r,a[i].val);
		}
  	
		for(int i=1;i<=n-m+1;++i)
			cout<<query(1,i)<<' ';
  }
//  system("pause");
  return 0;
}

