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

int n,q,a[N],tot;

signed main(){
  IOS
  cin>>n>>q;
  while(q--){
    int x;
    cin>>x;
    if(a[x]==1){
      a[x]=0;
      if(a[x+1]==1&&a[x-1]==1)
        ++tot;
      if(a[x+1]==0&&a[x-1]==0)
        --tot;
    } else{
      a[x]=1;
      if(a[x+1]==0&&a[x-1]==0)
        ++tot;
      if(a[x+1]==1&&a[x-1]==1)
        --tot;
    }
    cout<<tot<<'\n';
  }
  
  return 0;
}