#include <bits/stdc++.h>
using namespace std;

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

#define i128 __int128

inline i128 Gcd(i128 xx,i128 yy){return yy?Gcd(yy,xx%yy):xx;}
template <typename T1,typename...T2>
inline void read(T1 &x,T2& ...y){read(x);read(y...);}

const int N=100010;

int n;
i128 mod[N],a[N];

inline void exgcd(i128 a,i128 b,i128& d,i128& x,i128& y){
  if(!b){ d=a,x=1,y=0;}
  else{ exgcd(b,a%b,d,y,x); y-=x*(a/b);}
}

inline i128 solve(){
  i128 ans=a[1],lcm=mod[1];
  for(int i=1;i<n;++i){
    i128 k=a[i+1]-ans,p1=lcm,p2=mod[i+1];
    //k1p1+k2p2=k
    if(k%Gcd(p1,p2)) return -1;
    i128 gd=Gcd(p1,p2);
    p1/=gd,p2/=gd,k/=gd;

    i128 k1,k2;
    exgcd(p1,p2,p2,k1,k2);
    ans=ans+k1*lcm*k;
    lcm=lcm*mod[i+1]/Gcd(lcm,mod[i+1]);
    ans=(ans%lcm+lcm)%lcm;
  }
  return ans;
}

signed main(){
  // freopen("excrt.in","r",stdin);
  // freopen();
  //int T;
  read(n);
  for(int i=1;i<=n;++i)
    read(mod[i],a[i]);
  write(solve());

  return 0;
}
/*
3
2 1
6 5
10 7

17
*/