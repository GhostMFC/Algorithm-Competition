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

const int N=300010;

int q;
multiset<int> a,b;

signed main(){
  //freopen();
  //freopen();
  IOS
  //int T;
  cin>>q;
  while(q--){
    int opt,x;
    cin>>opt;
    if(opt==3){
      auto pos=b.begin();
      cout<<*pos<<'\n';
    } else{
      cin>>x;
      if(opt==1){
        if(a.empty()){
          a.insert(x);
          continue;
        }
        auto pos=a.lower_bound(x);
        if(pos==a.begin()){
          b.insert((*pos)^x);
          a.insert(x);
        } else if(pos==a.end()){
          --pos;
          b.insert((*pos)^x);
          a.insert(x);
        } else{
          int p1=*pos; --pos;
          int p2=*pos;
          b.erase(b.find(p1^p2));
          b.insert(x^p1),b.insert(x^p2);
          a.insert(x);
        }
      } else{
        auto pos=a.find(x);
        auto ppp=a.end();
        --ppp;
        if(a.size()==1) a.erase(pos);
        else if(pos==a.begin()){
          int p=*pos; ++pos;
          int pp=*pos; --pos;
          b.erase(b.find(p^pp));
          a.erase(pos);
        } else if(pos==ppp){
          int p=*pos; --pos;
          int pp=*pos; ++pos;
          b.erase(b.find(p^pp));
          a.erase(pos);
        } else{
          --pos; int p1=*pos; ++pos;
          ++pos; int p2=*pos; --pos;
          b.erase(b.find(p1^(*pos))),b.erase(b.find(p2^(*pos))),b.insert(p1^p2);
          a.erase(pos);
        }
      }
    }
  }
  
  return 0;
}
