#include <bits/stdc++.h>
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

#define All(x) x.begin(),x.end()

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const int N=105;

int n,m;
char s[N][N];

inline void Out_xR(int x,int y){
  for(int i=0;i<5;++i)
    cout<<x<<' '<<y+i<<'\n';
}

inline void Out_yD(int x,int y){
  for(int i=0;i<5;++i)
    cout<<x+i<<' '<<y<<'\n';
}

inline void Out_xL(int x,int y){
  for(int i=0;i<5;++i)
    cout<<x-i<<' '<<y<<'\n';
}

inline void Out_yU(int x,int y){
  for(int i=0;i<5;++i)
    cout<<x<<' '<<y-i<<'\n';
}

inline void Out_LL(int x,int y){
  for(int i=0;i<5;++i)
    cout<<x-i<<' '<<y-i<<'\n';
}

inline void Out_RR(int x,int y){
  for(int i=0;i<5;++i)
    cout<<x+i<<' '<<y+i<<'\n';
}

inline void Out_LR(int x,int y){//向左下
  for(int i=0;i<5;++i)
    cout<<x+i<<' '<<y-i<<'\n';
}

inline void Out_RL(int x,int y){//右上
  for(int i=0;i<5;++i)
    cout<<x-i<<' '<<y+i<<'\n';
}

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  cin>>n>>m;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      cin>>s[i][j];
  
  for(int i=1;i<=n-5+1;++i)
    for(int j=1;j<=m;++j){
      if(s[i][j]=='s'&&s[i+1][j]=='n'
      &&s[i+2][j]=='u'&&s[i+3][j]=='k'
      &&s[i+4][j]=='e') return Out_yD(i,j),0;
    }
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m-4;++j){
      if(s[i][j]=='s'&&s[i][j+1]=='n'
        &&s[i][j+2]=='u'&&s[i][j+3]=='k'
        &&s[i][j+4]=='e') return Out_xR(i,j),0;
    }
  
  for(int i=1;i<=n-5+1;++i)
    for(int j=1;j<=m-5+1;++j){
      if(s[i][j]=='s'&&s[i+1][j+1]=='n'
      &&s[i+2][j+2]=='u'&&s[i+3][j+3]=='k'
      &&s[i+4][j+4]=='e') return Out_RR(i,j),0;

      if(s[i][j]=='e'&&s[i+1][j+1]=='k'
      &&s[i+2][j+2]=='u'&&s[i+3][j+3]=='n'
      &&s[i+4][j+4]=='s') return Out_LL(i+4,j+4),0;
    }
  
  for(int i=5;i<=n;++i)
    for(int j=1;j<=m;++j){
      if(s[i][j]=='s'&&s[i-1][j]=='n'
      &&s[i-2][j]=='u'&&s[i-3][j]=='k'
      &&s[i-4][j]=='e') return Out_xL(i,j),0;
    }

  for(int i=1;i<=n;++i)
    for(int j=5;j<=m;++j){
      if(s[i][j]=='s'&&s[i][j-1]=='n'
      &&s[i][j-2]=='u'&&s[i][j-3]=='k'
      &&s[i][j-4]=='e') return Out_yU(i,j),0;
    }

  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j) if(i-4>0&&j+4<=m){
      if(s[i][j]=='s'&&s[i-1][j+1]=='n'
      &&s[i-2][j+2]=='u'&&s[i-3][j+3]=='k'
      &&s[i-4][j+4]=='e') return Out_RL(i,j),0;

      if(s[i][j]=='e'&&s[i-1][j+1]=='k'
      &&s[i-2][j+2]=='u'&&s[i-3][j+3]=='n'
      &&s[i-4][j+4]=='s') return Out_LR(i-4,j+4),0;
    }
  
  return 0;
}
