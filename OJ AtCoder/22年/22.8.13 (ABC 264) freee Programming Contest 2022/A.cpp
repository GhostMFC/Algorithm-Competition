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

int a,b;
char s[8]={'a','a','t','c','o','d','e','r'};

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>a>>b; //scanf("%d%d",&n,&m);
	for(int i=a;i<=b;++i) cout<<s[i];
	return 0;
}

