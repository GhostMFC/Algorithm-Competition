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
inline void Cout(){cout<<endl;}
template <class T1,class...T2>
inline void Cout(T1 x,T2 ...y){cout<<x<<' ';Cout(y...);}

const int N=105;

int n,d[N],ans;

inline int check(int x,int y){
  for(int i=1;i<=9;++i){
    bool tag=true;
    int j=x,k=y;
    while(j){
      if(j%10!=i) tag=false;
      j/=10;
    }

    while(k){
      if(k%10!=i) tag=false;
      k/=10;
    }

    if(tag) return true;
  } return false;
}

signed main(){
  IOS

  cin>>n;
  for(int i=1;i<=n;++i){
    cin>>d[i];
    for(int j=1;j<=d[i];++j)
      ans+=check(i,j);
  }

  

  cout<<ans<<'\n';
  
  return 0;
}