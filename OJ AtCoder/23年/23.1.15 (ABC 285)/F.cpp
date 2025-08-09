#include <bits/stdc++.h>
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

#define All(x) x.begin(),x.end()

const int N=100010;

int n,cnt,s[N],m;

struct Node{
	int l,r,lch,rch;
	int lc,rc,yon,tot[27];
}node[N<<1];

inline int build(int l,int r){
	int x=++cnt;
	node[x].l=l,node[x].r=r;
	if(l==r){
		node[x].yon=true;
		node[x].lc=node[x].rc=s[l];
		node[x].tot[s[l]]++;
		return x;
	}
	int mid=(l+r)>>1;
	ls=build(l,mid),rs=build(mid+1,r);
	if(node[ls].yon&&node[rs].yon&&node[ls].rc<=node[rs].rc)
		node[x].yon=true,node[x].lc=node[ls].lc,node[x].rc=node[rs].rc;
	else node[x].yon=false;
	for(int i=1;i<=26;++i)
		node[x].tot[i]=node[ls].tot[i]+node[rs].tot[i];
	return x;
}

inline void update(int x,int pos,int co){
	if(node[x].l==node[x].r){
		node[x].tot[node[x].lc]--;
		node[x].tot[co]++;
		node[x].lc=node[x].rc=co;
		return ;
	} int mid=(node[x].l+node[x].r)>>1;
	if(pos<=mid) update(ls,pos,co);
	else update(rs,pos,co);
	if(node[ls].yon&&node[rs].yon&&node[ls].rc<=node[rs].rc)
		node[x].yon=true,node[x].lc=node[ls].lc,node[x].rc=node[rs].rc;
	else node[x].yon=false;
	for(int i=1;i<=26;++i)
		node[x].tot[i]=node[ls].tot[i]+node[rs].tot[i];
}

int lstco,tt[27];
inline bool query(int x,int l,int r){
	if(node[x].l>=l&&node[x].r<=r){
		if(lstco>node[x].lc||!node[x].yon) return false;
		for(int i=1;i<=26;++i)
			tt[i]+=node[x].tot[i];
		return lstco=node[x].rc,true;
	} int mid=(node[x].l+node[x].r)>>1;
	bool yn=true;
	if(l<=mid) yn=query(ls,l,r);
	if(!yn) return false;
	if(r>mid) yn=query(rs,l,r);
	return yn;
}

signed main(){
//  freopen("F.in","r",stdin);
//  freopen("F.out","w",stdout);
  IOS
  cin>>n; //scanf("%d%d",&n,&m);
  char ch;
	for(int i=1;i<=n;++i)
		cin>>ch,s[i]=ch-'a'+1;
	build(1,n);
	cin>>m;
	int opt,l,r,x;
	while(m--){
		cin>>opt;
		if(opt==1){
			cin>>x>>ch;
			update(1,x,ch-'a'+1);
		} else{
			cin>>l>>r;
			lstco=-1;
			memset(tt,0,sizeof(tt));
			if(!query(1,l,r)){ cout<<"No\n";continue;}
			l=0,r=27;
			while(l<27)
				if(tt[l+1]){
					l=l+2;
					break;
				} else ++l;
			while(r>0)
				if(tt[r-1]){
					r-=2;
					break;
				} else --r;
			bool yon=true;
			while(l<=r){
				if(tt[l]!=node[1].tot[l]){
					yon=false;
					break;
				}
				++l;
			}
			cout<<(yon?"Yes":"No")<<'\n';
		}
	}
//  system("pause");
  return 0;
}
/*
8
abcdabcd
3
2 1 4
1 2 a
2 2 3
*/
