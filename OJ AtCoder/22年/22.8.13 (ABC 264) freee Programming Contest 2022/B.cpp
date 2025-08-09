#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cmath>
//#include <numeric>
//#include <queue>
//#include <map> //(unordered_map)
//#include <vector>
//#include <ctime>
#define ll long long
#define Mod 998244353
#define ls node[x].lch
#define rs node[x].rch
#define inf 0x7fffffff
#define inf1 1000000009
#define llinf 0x7fffffffffffffff
//#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
//#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
using namespace std;
template <typename T> inline void read(T &xx){
	char cc=getchar();T ff=1; xx=0;
	while(cc>'9'||cc<'0'){ ff=cc=='-'?-1:ff; cc=getchar();}
	while(cc<='9'&&cc>='0'){ xx=(xx<<1)+(xx<<3)+cc-'0'; cc=getchar();}
	xx=xx*ff;
}
inline ll gcd(ll xx,ll yy){return yy?gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0; while(yy){ if(yy&1) oo=(oo+xx)%pp; xx=(xx<<1)%pp; yy>>=1;} return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1; while(yy){ if(yy&1) oo=oo*xx%pp; xx=xx*xx%pp; yy>>=1;} return oo;}
//q_Pow can conbine with q_Mul to avoid overflow

template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const int maxn=9;

int a,b;
int map[maxn][maxn];

int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>a>>b;
	int p=0;
	for(int i=1;i<=8;++i){
		p^=1;
		for(int j=i;j<=8;++j) map[i][j]=map[j][i]=p;
	}
	if(a>8) a=(8-(a-8));
	if(b>8) b=(8-(b-8));
	if(map[a][b]) cout<<"black\n";
	else cout<<"white\n";
	return 0;
}

