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

int n,m;
int a[N],tot[N];

inline bool check(int x){
	int l=1;
	memset(tot,0,sizeof(tot));
	int r=upper_bound(a+1,a+1+n,a[1]+x)-a-1;
	int num=0;
	for(int i=1;i<=r;++i){
		for(int j=1;j*j<=a[i]&&j<=m;++j)
			if(a[i]%j==0){
				tot[j]++;
				if(tot[j]==1) ++num;
				if(j*j!=a[i]&&a[i]/j<=m){
					tot[a[i]/j]++;
					if(tot[a[i]/j]==1) ++num;
				}
			}
	} if(num==m) return true;
	while(r<n){
		++r;
		for(int j=1;j*j<=a[r]&&j<=m;++j)
			if(a[r]%j==0){
				tot[j]++;
				if(tot[j]==1) ++num;
				if(j*j!=a[r]&&a[r]/j<=m){
					tot[a[r]/j]++;
					if(tot[a[r]/j]==1) ++num;
				}
			}
		while(a[r]-a[l]>x){
			for(int j=1;j*j<=a[l]&&j<=m;++j)
				if(a[l]%j==0){
					tot[j]--;
					if(!tot[j]) --num;
					if(j*j!=a[l]&&a[l]/j<=m){
						tot[a[l]/j]--;
						if(!tot[a[l]/j]) --num;
					}
				}
			++l;
		}
		if(num==m) return true;
	}
	return false;
}

inline void solve(){
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	//¶þ·Ö£¿
	int l=0,r=a[n]-a[1];
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(!check(l)) cout<<-1<<'\n';
	else cout<<l<<'\n';
}

signed main(){
//  freopen("C.in","r",stdin);
//  freopen("C.out","w",stdout);
  IOS
  int t;
  cin>>t;
  while(t--){
	  cin>>n>>m;
	  for(int i=1;i<=n;++i)
	  	cin>>a[i];
  	solve();
	}
//  system("pause");
  return 0;
}
/*
1
4 5
1 10 20 30
*/
