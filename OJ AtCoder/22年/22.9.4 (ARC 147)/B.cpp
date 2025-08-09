#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <climits>
//#include <utility>
//#include <numeric>
//#include <queue>
//#include <map>
//#include <tr1/unordered_map>
//#include <vector>
//#include <ctime>
#define ll long long
#define Mod 998244353
#define ls node[x].lch
#define rs node[x].rch
#define inf 0x7fffffff
#define inf1 1000000009
#define ull unsigned long long
#define llinf 0x7fffffffffffffff
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
//#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
//#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
using namespace std;
template <typename T> inline void read(T &xx){
  char cc=getchar();T ff=1; xx=0;
  while(cc>'9'||cc<'0'){ ff=cc=='-'?-1:ff; cc=getchar();}
  while(cc<='9'&&cc>='0'){ xx=(xx<<1)+(xx<<3)+cc-'0'; cc=getchar();}
  xx=xx*ff;
}
template <typename T> inline void write(T xx){
  if(xx<0){ putchar('-'); xx=-xx;}
  if(xx>9) write(xx/10);
  putchar(xx%10+'0');
}
inline ll lowbit(ll xx){ return xx&(-xx);}
inline ll min(ll xx,ll yy){ return xx>yy?yy:xx;}
inline ll max(ll xx,ll yy){ return xx<yy?yy:xx;}
inline ll gcd(ll xx,ll yy){return yy?gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0; while(yy){ if(yy&1) oo=(oo+xx)%pp; xx=(xx<<1)%pp; yy>>=1;} return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
//q_Pow can conbine with q_Mul to avoid overflow

template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const int maxn=405;
const int maxm=1e5+5;

int n,p[maxn],b[maxm],ans;
char a[maxm];

int main(){
//  freopen("B.in","r",stdin);
//  freopen("B01.out","w",stdout);
  IOS
  cin>>n;
	for(int i=1;i<=n;++i)
		cin>>p[i];
	
	for(int i=2;i<=n;i+=2){
		bool yon=false;
		for(int j=2;j<=n-i;j+=2){
			if(p[j]>p[j+2]){
				yon=true;
				swap(p[j],p[j+2]);
				a[++ans]='B',b[ans]=j;
			}
		}
		if(!yon) break;
	}
	
	bool yon2=true;
	while(yon2){
		yon2=false;
		for(int i=2;i<=n;i+=2){
			if(p[i]%2==0&&p[i]!=i){ yon2=true;
				int k=i;
				while(p[k]!=k){
					if(p[k]<k){
						swap(p[k],p[k-2]);
						k-=2; ++ans;
						a[ans]='B',b[ans]=k;
					} else{
						swap(p[k],p[k+2]);
						k+=2; ++ans;
						a[ans]='B',b[ans]=k-2;
					}
				}
			}
		}
	}
	
	
	for(int i=1;i<=n;i+=2){
		bool yon=false;
		for(int j=1;j<=n-i-1;j+=2){
			if(p[j]>p[j+2]){
				yon=true;
				swap(p[j],p[j+2]);
				a[++ans]='B',b[ans]=j;
			}
		}
		if(!yon) break;
	}
	
	bool yon1=true;
	while(yon1){ yon1=false;
		for(int i=1;i<=n;i+=2){
			if(p[i]%2==0){ yon1=true;
				int k=i;
				while(abs(p[k]-k)!=1){
					if(p[k]<k){
						swap(p[k],p[k-2]);
						k-=2; ++ans;
						a[ans]='B',b[ans]=k;
					} else{
						swap(p[k+2],p[k]);
						k+=2; ++ans;
						a[ans]='B',b[ans]=k-2;
					}
				}
				if(p[k]>k){
					swap(p[k],p[k+1]);
					++ans;
					a[ans]='A',b[ans]=k;
				} else{
					swap(p[k],p[k-1]);
					++ans;
					a[ans]='A',b[ans]=k-1;
				}
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i+=2){
		bool yon=false;
		for(int j=1;j<=n-i-1;j+=2){
			if(p[j]>p[j+2]){
				yon=true;
				swap(p[j],p[j+2]);
				a[++ans]='B',b[ans]=j;
			}
		}
		if(!yon) break;
	}
	
	cout<<ans<<'\n';
	for(int i=1;i<=ans;++i)
		cout<<a[i]<<' '<<b[i]<<'\n';
//  system("pause");
  return 0;
}
/*
7
2 3 4 5 6 7 1

*/
