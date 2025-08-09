#include <bits/stdc++.h>
#include <bits/extc++.h>
#define Mod 998244353
#define Mod1 10000000000037
#define ls node[x].lch
#define rs node[x].rch
#define inf 0x7fffffff
#define inf1 1000000009
#define llinf 0x7fffffffffffffff
#define llinf1 1000000000000000009
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define PRC(b,a) fixed<<setprecision(a)<<b
#define Next(a,b) for(int a=head[b];a;a=edge[a].nxt)
using namespace std;
using namespace __gnu_cxx;//rope<T> x
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
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
inline ll q_2(ll xx){return xx*xx;}
inline ll lowbit(ll xx){return xx&(-xx);}
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Mul(ll xx,ll yy,ll pp){ll oo=0;while(yy){if(yy&1)oo=(oo+xx)%pp;xx=(xx<<1)%pp;yy>>=1;}return oo;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
//q_Pow can conbine with q_Mul to avoid overflow
template <typename T> inline T Min(T xx,T yy){return xx<yy?xx:yy;}
template <typename T> inline T Max(T xx,T yy){return xx>yy?xx:yy;}//(XX-YY>>63)?.:.;
template <typename T> inline void sMin(T &xx,T yy){xx=(xx<yy)?xx:yy;}
template <typename T> inline void sMax(T &xx,T yy){xx=(xx>yy)?xx:yy;}

template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}
inline void Cout(){cout<<endl;}
template <class T1,class...T2>
inline void Cout(T1 x,T2 ...y){cout<<x<<' ';Cout(y...);}

#define pb push_back
#define All(x) x.begin(),x.end()

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int d2x[8]={1,0,-1,0,1,-1,-1,1},d2y[8]={0,1,0,-1,1,1,-1,-1};

const double PI=acos(-1),eps=1e-10;

const int N=500010,mxL=500000;

char s[N];
int n,q,tr[2][N];
inline void Add(int z,int x,int val){
  while(x<=mxL) tr[z][x]+=val,x+=lowbit(x);
}
inline int query(int z,int x){
  int res=0;
  while(x) res+=tr[z][x],x-=lowbit(x);
  return res;
}

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  cin>>n>>q;
  cin>>s+1;
  for(int i=1;i<n;++i){
    if(s[i]==s[i+1])//no
      Add(0,i,1);
  }
  while(q--){
    int opt,l,r;
    cin>>opt>>l>>r;
    if(opt==1){
      Add(1,l,1),Add(1,r+1,-1);
      int x,y;
      if(l>1){
        x=query(1,l-1),y=query(1,l);
        if((s[l-1]^(x&1))==(s[l]^(y&1)))
          Add(0,l-1,1);
        else Add(0,l-1,-1);
      }
      if(r<n){
        x=query(1,r),y=query(1,r+1);
        if((s[r]^(x&1))==(s[r+1]^(y&1)))
          Add(0,r,1);
        else Add(0,r,-1);
      }
    } else{
      if(query(0,r-1)-query(0,l-1))
        cout<<"No\n";
      else cout<<"Yes\n";
    }
  }
  
  return 0;
}
/*
5 1
10100
2 3 3
*/