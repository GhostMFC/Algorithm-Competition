#include <bits/stdc++.h>
#define inf 0x7fffffff
#define llinf 0x7fffffffffffffff
#define F(a,b,c,d) for(int b=c;b<=d;b+=a)
#define F2(a,b,c,d) for(int b=c;b>=d;b-=a)
#define PRC(b,a) fixed<<setprecision(a)<<b
#define pb push_back
#define All(x) x.begin(),x.end()
#define Next(a,b) for(int a=head[b];a;a=edge[a].nxt)
#define IOS ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
inline ll q_2(ll xx){return xx*xx;}
inline ll Gcd(ll xx,ll yy){return yy?Gcd(yy,xx%yy):xx;}
inline ll q_Pow(ll xx,ll yy,ll pp){ll oo=1;for(;yy;yy>>=1,xx=xx*xx%pp)yy&1?oo=oo*xx%pp:0;return oo;}
inline void Cout(){cout<<endl;}
template <class T1,class...T2>
inline void Cout(T1 x,T2 ...y){cout<<x<<' ';Cout(y...);}
template <typename T> inline void sMin(T &xx,T yy){xx=(xx<yy)?xx:yy;}
template <typename T> inline void sMax(T &xx,T yy){xx=(xx>yy)?xx:yy;}

const int N=500010;

int n,a[N];

signed main(){
  IOS
  cin>>n;
  for(int i=1;i<=n;++i)
    cin>>a[i];
  
  ll ans=0;
  for(int i=1;i<n;++i){
    int pos=lower_bound(a+1,a+1+n,a[i]<<1)-a;
    ans+=n-pos+1;
  }
  cout<<ans<<'\n';
  
  return 0;
}