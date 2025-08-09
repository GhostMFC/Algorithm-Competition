#include <bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
#define ull unsigned long long
#define llinf 0x7fffffffffffffff
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define PRC(b,a) fixed<<setprecision(a)<<b
#define pb push_back
#define All(x) x.begin(),x.end()
#define Next(a,b) for(int a=head[b];a;a=edge[a].nxt)
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}

const int N=10005;

int n;
double f[N][33],x[N],y[N],_2[33];

inline double p2(double a){
  return a*a;
}

inline double calc(int a,int b){
  return sqrt(p2(x[a]-x[b])+p2(y[a]-y[b]));
}

signed main(){
  IOS
  cin>>n;
  F(1,i,1,n) cin>>x[i]>>y[i];
  _2[1]=1;
  for(int i=2;i<=30;++i) _2[i]=_2[i-1]*2;

  for(int i=1;i<=n;++i)
    fill_n(f[i],33,1e18);
  f[1][0]=0;
  for(int i=1;i<=n;++i){
    for(int j=0;j<=30&&j<i;++j){//已经跳了多少次
      for(int k=0;k+j<=30&&i+k+1<=n;++k)//这一次跳多少下
        f[i+k+1][j+k]=min(f[i+k+1][j+k],f[i][j]+calc(i+k+1,i));
    }
  }

  double ans=1e18;
  for(int i=0;i<=30;++i)
    ans=min(ans,f[n][i]+_2[i]);
  cout<<PRC(ans,12)<<'\n';
  
  return 0;
}